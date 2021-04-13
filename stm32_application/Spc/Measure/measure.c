#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "gpio.h"

TaskHandle_t TaskMeasure = NULL;

/**
 * Voltage and current sensor handler
 */
static void Task_MeasureVoltCur(void *pvParameters)
{
    while (1) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        LedBlink();
    }
}

void Measure_VoltCurInit(void)
{
    uartprintf("Init voltage and current sensor\r\n");
    xTaskCreate(Task_MeasureVoltCur, (const char *) "Measure", 256,
                NULL, 0, &TaskMeasure);
}
