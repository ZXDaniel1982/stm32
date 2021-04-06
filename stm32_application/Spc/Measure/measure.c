#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

TaskHandle_t TaskMeasure = NULL;
TimerHandle_t TimerMeasure = NULL;

/**
 * Voltage and current sensor handler
 */
static void Task_MeasureVoltCur(TimerHandle_t xTimer)
{
	uartprintf("Measure volt and current\r\n");
}

void Measure_VoltCurInit(void)
{
	uartprintf("Init voltage and current sensor\r\n");
	TimerMeasure = xTimerCreate("Measure", 1000, pdTRUE, (void *)0, Task_MeasureVoltCur);
	xTimerStart(TimerMeasure, 5000);
}
