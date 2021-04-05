#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

TimerHandle_t demoTimer;

void vTimerCallback( TimerHandle_t xTimer )
{
  LedBlink();  
}

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
	Gui_Init();
	Page_Init();

  demoTimer = xTimerCreate("Timer", 1000, pdTRUE, (void *)0, vTimerCallback);
  xTimerStart(demoTimer, 0);

	vTaskStartScheduler();

	while (1) {

	}
}

void Error_Handle()
{
	while (1);
}
