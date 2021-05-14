#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "gpio.h"

static const GPIO_PINS_t GPIO_PINS_L[] = {
	{Led_GPIO_Port, Led_Pin, (GPIO_CRL_CNF5 | GPIO_CRL_MODE5),
	 GPIO_CRL_MODE5_1},
	{SST_CS_GPIO_Port, SST_CS_Pin, (GPIO_CRL_CNF4 | GPIO_CRL_MODE4),
	 GPIO_CRL_MODE4},

	// spi1
	{GPIOA, GPIO_BSRR_BS5, (GPIO_CRL_CNF5 | GPIO_CRL_MODE5),
	 (GPIO_CRL_CNF5_1 | GPIO_CRL_MODE5)},
	{GPIOA, GPIO_BSRR_BS6, (GPIO_CRL_CNF6 | GPIO_CRL_MODE6), GPIO_CRL_CNF6_0},
	{GPIOA, GPIO_BSRR_BS7, (GPIO_CRL_CNF7 | GPIO_CRL_MODE7),
	 (GPIO_CRL_CNF7_1 | GPIO_CRL_MODE7)},

	// FSMC
	{GPIOE, GPIO_BSRR_BS1, (GPIO_CRL_CNF1 | GPIO_CRL_MODE1), GPIO_CRL_MODE1_1},
	{GPIOE, GPIO_BSRR_BS7, (GPIO_CRL_CNF7 | GPIO_CRL_MODE7),
	 (GPIO_CRL_CNF7_1 | GPIO_CRL_MODE7)},
	{GPIOD, GPIO_BSRR_BS0, (GPIO_CRL_CNF0 | GPIO_CRL_MODE0),
	 (GPIO_CRL_CNF0_1 | GPIO_CRL_MODE0)},
	{GPIOD, GPIO_BSRR_BS1, (GPIO_CRL_CNF1 | GPIO_CRL_MODE1),
	 (GPIO_CRL_CNF1_1 | GPIO_CRL_MODE1)},
	{GPIOD, GPIO_BSRR_BS4, (GPIO_CRL_CNF4 | GPIO_CRL_MODE4),
	 (GPIO_CRL_CNF4_1 | GPIO_CRL_MODE4)},
	{GPIOD, GPIO_BSRR_BS5, (GPIO_CRL_CNF5 | GPIO_CRL_MODE5),
	 (GPIO_CRL_CNF5_1 | GPIO_CRL_MODE5)},
	{GPIOD, GPIO_BSRR_BS7, (GPIO_CRL_CNF7 | GPIO_CRL_MODE7),
	 (GPIO_CRL_CNF7_1 | GPIO_CRL_MODE7)},

	// sdio
	{GPIOD, GPIO_BSRR_BS2, (GPIO_CRL_CNF2 | GPIO_CRL_MODE2),
	 (GPIO_CRL_CNF2_1 | GPIO_CRL_MODE2)},
};

static const GPIO_PINS_t GPIO_PINS_H[] = {
	// usart1
	{GPIOA, GPIO_BSRR_BS9, (GPIO_CRH_CNF9 | GPIO_CRH_MODE9),
	 (GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9)},
	{GPIOA, GPIO_BSRR_BS10, (GPIO_CRH_CNF10 | GPIO_CRH_MODE10),
	 GPIO_CRH_CNF10_0},

	// FSMC
	{GPIOD, GPIO_BSRR_BS13, (GPIO_CRH_CNF13 | GPIO_CRH_MODE13),
	 GPIO_CRH_MODE13},
	{GPIOD, GPIO_BSRR_BS8, (GPIO_CRH_CNF8 | GPIO_CRH_MODE8),
	 (GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8)},
	{GPIOD, GPIO_BSRR_BS9, (GPIO_CRH_CNF9 | GPIO_CRH_MODE9),
	 (GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9)},
	{GPIOD, GPIO_BSRR_BS10, (GPIO_CRH_CNF10 | GPIO_CRH_MODE10),
	 (GPIO_CRH_CNF10_1 | GPIO_CRH_MODE10)},
	{GPIOD, GPIO_BSRR_BS11, (GPIO_CRH_CNF11 | GPIO_CRH_MODE11),
	 (GPIO_CRH_CNF11_1 | GPIO_CRH_MODE11)},
	{GPIOD, GPIO_BSRR_BS14, (GPIO_CRH_CNF14 | GPIO_CRH_MODE14),
	 (GPIO_CRH_CNF14_1 | GPIO_CRH_MODE14)},
	{GPIOD, GPIO_BSRR_BS15, (GPIO_CRH_CNF15 | GPIO_CRH_MODE15),
	 (GPIO_CRH_CNF15_1 | GPIO_CRH_MODE15)},
	{GPIOE, GPIO_BSRR_BS8, (GPIO_CRH_CNF8 | GPIO_CRH_MODE8),
	 (GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8)},
	{GPIOE, GPIO_BSRR_BS9, (GPIO_CRH_CNF9 | GPIO_CRH_MODE9),
	 (GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9)},
	{GPIOE, GPIO_BSRR_BS10, (GPIO_CRH_CNF10 | GPIO_CRH_MODE10),
	 (GPIO_CRH_CNF10_1 | GPIO_CRH_MODE10)},
	{GPIOE, GPIO_BSRR_BS11, (GPIO_CRH_CNF11 | GPIO_CRH_MODE11),
	 (GPIO_CRH_CNF11_1 | GPIO_CRH_MODE11)},
	{GPIOE, GPIO_BSRR_BS12, (GPIO_CRH_CNF12 | GPIO_CRH_MODE12),
	 (GPIO_CRH_CNF12_1 | GPIO_CRH_MODE12)},
	{GPIOE, GPIO_BSRR_BS13, (GPIO_CRH_CNF13 | GPIO_CRH_MODE13),
	 (GPIO_CRH_CNF13_1 | GPIO_CRH_MODE13)},
	{GPIOE, GPIO_BSRR_BS14, (GPIO_CRH_CNF14 | GPIO_CRH_MODE14),
	 (GPIO_CRH_CNF14_1 | GPIO_CRH_MODE14)},
	{GPIOE, GPIO_BSRR_BS15, (GPIO_CRH_CNF15 | GPIO_CRH_MODE15),
	 (GPIO_CRH_CNF15_1 | GPIO_CRH_MODE15)},

	// sdio
	{GPIOC, GPIO_BSRR_BS8, (GPIO_CRH_CNF8 | GPIO_CRH_MODE8),
	 (GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8)},
	{GPIOC, GPIO_BSRR_BS9, (GPIO_CRH_CNF9 | GPIO_CRH_MODE9),
	 (GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9)},
	{GPIOC, GPIO_BSRR_BS10, (GPIO_CRH_CNF10 | GPIO_CRH_MODE10),
	 (GPIO_CRH_CNF10_1 | GPIO_CRH_MODE10)},
	{GPIOC, GPIO_BSRR_BS11, (GPIO_CRH_CNF11 | GPIO_CRH_MODE11),
	 (GPIO_CRH_CNF11_1 | GPIO_CRH_MODE11)},
	{GPIOC, GPIO_BSRR_BS12, (GPIO_CRH_CNF12 | GPIO_CRH_MODE12),
	 (GPIO_CRH_CNF12_1 | GPIO_CRH_MODE12)},
};

static void GPIOxL_Init(GPIO_TypeDef * GPIOx, uint32_t pin, uint32_t clear,
						uint32_t set)
{
	// ¶Ë¿ÚÎ»Çå³ý¼Ä´æÆ÷  Çå³ý¶Ë¿ÚxµÄÎ»y  1£ºÇå³ý¶ÔÓ¦µÄODRyÎ»Îª0
	WRITE_REG(GPIOx->BRR, pin);

	// ¶Ë¿ÚÅäÖÃµÍ¼Ä´æÆ÷  CNF 00£ºÍ¨ÓÃÍÆÍìÊä³öÄ£Ê½  MODE  10 : Êä³öÄ£Ê½£¬×î´óËÙ¶È2MHz
	MODIFY_REG(GPIOx->CRL, clear, set);

	// ¶Ë¿ÚÊä³öÊý¾Ý¼Ä´æÆ÷  
	MODIFY_REG(GPIOx->ODR, pin, 0);
}

static void GPIOxH_Init(GPIO_TypeDef * GPIOx, uint32_t pin, uint32_t clear,
						uint32_t set)
{
	// ¶Ë¿ÚÎ»Çå³ý¼Ä´æÆ÷  Çå³ý¶Ë¿ÚxµÄÎ»y  1£ºÇå³ý¶ÔÓ¦µÄODRyÎ»Îª0
	WRITE_REG(GPIOx->BRR, pin);

	// ¶Ë¿ÚÅäÖÃµÍ¼Ä´æÆ÷  CNF 00£ºÍ¨ÓÃÍÆÍìÊä³öÄ£Ê½  MODE  10 : Êä³öÄ£Ê½£¬×î´óËÙ¶È2MHz
	MODIFY_REG(GPIOx->CRH, clear, set);

	// ¶Ë¿ÚÊä³öÊý¾Ý¼Ä´æÆ÷  
	MODIFY_REG(GPIOx->ODR, pin, 0);
}

void GPIO_Init()
{
	uint8_t i;

	for (i = 0; i < NUM_ROWS(GPIO_PINS_L); ++i) {
		GPIOxL_Init(GPIO_PINS_L[i].port, GPIO_PINS_L[i].pin,
					GPIO_PINS_L[i].clear, GPIO_PINS_L[i].set);
	}
	for (i = 0; i < NUM_ROWS(GPIO_PINS_H); ++i) {
		GPIOxH_Init(GPIO_PINS_H[i].port, GPIO_PINS_H[i].pin,
					GPIO_PINS_H[i].clear, GPIO_PINS_H[i].set);
	}
}

void LedBlink(void)
{
	static uint8_t flag = 0;

	if (flag) {
		flag = 0;
		SET_BIT(Led_GPIO_Port->ODR, Led_Pin);
	} else {
		flag = 1;
		CLEAR_BIT(Led_GPIO_Port->ODR, Led_Pin);
	}
}

void LedOn(void)
{
		SET_BIT(Led_GPIO_Port->ODR, Led_Pin);
}

