#include <string.h>

#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "sdio.h"

void Error_Handle(void)
{
    //uartprintf("Kernel panic ...\n");
    //while(1);
}

static void RCC_Init(void)
{
    __IO uint32_t tmpreg;
    // ��������IOʱ��ʹ��
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);
    /* Delay after an RCC peripheral clock enabling */
    tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);
    (void)tmpreg;

    // ��Դ�ӿ�ʱ��ʹ��
    // If you don't set the RCC_APB1ENR .PWREN bit,
    // the registers of PWR unit can't be written and reading them returns 0.
    SET_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN);
    /* Delay after an RCC peripheral clock enabling */
    tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN);
    (void)tmpreg;

    NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    // ͨ�ú͸��ù���I/O
    CLEAR_BIT(AFIO->MAPR,AFIO_MAPR_SWJ_CFG);  // 000����ȫSWJ(JTAG-DP + SW-DP)����λ״̬��
    SET_BIT(AFIO->MAPR, AFIO_MAPR_SWJ_CFG_DISABLE); // 100���ر�JTAG-DP���ر�SW-DP��

    // 010�������ȴ�״̬���� 48MHz < SYSCLK �� 72MHz
    MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_1);
    if((uint32_t)(READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY)) != FLASH_ACR_LATENCY_1) {
        Error_Handle();  
    }

    // �ⲿ����ʱ��ʹ��
    // 1�� HSE��������
    SET_BIT(RCC->CR, RCC_CR_HSEON);
    while(READ_BIT(RCC->CR, RCC_CR_HSERDY) != RCC_CR_HSERDY);

    // PLL����ʱ��Դ  1�� PREDIV1�����ΪPLL����ʱ��
    // PREDIV1��Ƶ���ӵĵ�λ  ��0
    // PLL��Ƶϵ��  0111�� PLL 9��Ƶ���
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL,
             (RCC_CFGR_PLLSRC & (RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE)) | RCC_CFGR_PLLMULL9);

    // 1�� PLLʹ�ܡ�
    SET_BIT(RCC->CR, RCC_CR_PLLON);
    while(READ_BIT(RCC->CR, RCC_CR_PLLRDY) != RCC_CR_PLLRDY);

    // AHBԤ��Ƶ  0xxx�� SYSCLK����Ƶ
    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_CFGR_HPRE_DIV1);
    // ����APBԤ��Ƶ   100�� HCLK 2��Ƶ
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_CFGR_PPRE1_DIV2);
    // ����APBԤ��Ƶ   0xx�� HCLK����Ƶ
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, RCC_CFGR_PPRE2_DIV1);
    // ϵͳʱ���л�    10�� PLL�����Ϊϵͳʱ�ӣ�
    MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
    while((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_SWS)) != RCC_CFGR_SWS_PLL);


    SysTick->LOAD  = (uint32_t)((72000000 / 1000U) - 1UL);  // ������0�� ����װ��
    SysTick->VAL   = 0UL;   // currentֵ  д����0
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |      // 1 : �ں�ʱ��Դ FCLK
                    SysTick_CTRL_ENABLE_Msk;  // ��ʱ��ʹ��


    SET_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk);
    SystemCoreClock = 72000000;

    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPDEN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);
    SET_BIT(RCC->AHBENR,  RCC_AHBENR_SDIOEN);
}

void delay(uint32_t val)
{
    int i;
    for (i = 0; i < 3600000; ++i);
}

int main()
{
    uint8_t buf = 0;

    RCC_Init();
    GPIO_Init();
    USART_Init();
    SPI_Init();
    SDIOEx_Init();
    EEPROM_Init();

    uartprintf("STM32 bootloader V1.0\r\n");

    BootargsInit();
    if (GetBootargFromEEP() == STM32_FALSE) {
        uartprintf("Could not find bootargs, using default\r\n");
        GetBootargFromDefault();
    } else {
        uartprintf("Press any key to stop auto start in : ");
        if (autoboot() == STM32_SUCCESS) {
            bootm(&buf);
        }
    }

    uartprintf("stm32 > ");

    while(1) {
        if((USART1->SR & USART_CR1_RXNEIE) != 0) {
            buf = USART1->DR;
            USART_RxProcess(buf);
        }
    }
}
