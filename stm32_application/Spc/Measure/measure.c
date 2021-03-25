#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

TaskHandle_t TaskMeasure = NULL;

/**
 * Voltage and current sensor handler
 */
static void Task_MeasureVoltCur(void *pvParameters)
{
	//uartprintf("Measure volt and current\r\n");
	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
		vTaskDelay(5000);
	}
}

void Measure_VoltCurInit(void)
{
	uartprintf("Init voltage and current sensor\r\n");
	xTaskCreate(Task_MeasureVoltCur, (const char *) "Measure", 128, NULL, 0,
				&TaskMeasure);
}
