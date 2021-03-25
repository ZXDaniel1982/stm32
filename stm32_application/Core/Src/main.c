#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

/**
 * Entry point for the application.
 */
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

	for (i = 0; i < 7200000; ++i) {
	}
	uartprintf("Start application\r\n");

	Measure_VoltCurInit();
	Page_Init();
	Gui_Init();

	vTaskStartScheduler();

	while (1) {

	}
}

void Error_Handle()
{
	while (1);
}
