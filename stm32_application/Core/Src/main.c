#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

static void RCC_Init(void)
{
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    // ¸¨Öú¹¦ÄÜIOÊ±ÖÓÊ¹ÄÜ
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);
    SET_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN);

    CLEAR_BIT(AFIO->MAPR,AFIO_MAPR_SWJ_CFG);  // 000£ºÍêÈ«SWJ(JTAG-DP + SW-DP)£º¸´Î»×´Ì¬£»
    SET_BIT(AFIO->MAPR, AFIO_MAPR_SWJ_CFG_DISABLE); // 100£º¹Ø±ÕJTAG-DP£¬¹Ø±ÕSW-DP£»

    MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_1);

    SET_BIT(RCC->CR, RCC_CR_HSEON);
    while(!READ_BIT(RCC->CR, RCC_CR_HSERDY));

    SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);
    while(!READ_BIT(RCC->BDCR, RCC_BDCR_LSERDY));

    MODIFY_REG(RCC->CFGR, (RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL),
             (RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL9));

    // 1£º PLLÊ¹ÄÜ¡£
    SET_BIT(RCC->CR, RCC_CR_PLLON);
    while(!READ_BIT(RCC->CR, RCC_CR_PLLRDY));

    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_CFGR_HPRE_DIV1);
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_CFGR_PPRE1_DIV2);
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, RCC_CFGR_PPRE2_DIV1);
    MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
    while((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_SWS)) != RCC_CFGR_SWS_PLL);

    SystemCoreClock = 72000000;

    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPDEN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPEEN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);
    SET_BIT(RCC->AHBENR,  RCC_AHBENR_SDIOEN);
    SET_BIT(RCC->AHBENR,  RCC_AHBENR_FSMCEN);
    SET_BIT(RCC->APB1ENR, RCC_APB1ENR_BKPEN);
    
#ifdef BOARD_ADV1
    // Config SPI DMA
    // SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA1EN);
#endif
} 

int main()
{
    uint32_t i;

    RCC_Init();
    GPIO_Init();
    TIMER_Init();
    USART_Init();
    SPI_Init();
    FSMC_Init();
    LCD_Init();
    SDIOEx_Init();
    EEPROM_Init();

    for (i=0;i<7200000;++i) {}
    tftprintf("Start application");

#ifdef BOARD_ADV1
    LedBlink();

    vTaskStartScheduler();
#endif
    
    while(1) {

    }
}

void Error_Handle()
{
    while (1);
}
