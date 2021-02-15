#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

TaskHandle_t TaskMeasure = NULL;

/**
 * Voltage and current sensor handler
 */
static void Measure_VoltCurTimer(void *pvParameters)
{
    while (1) {
        /* Block to wait for prvTask1() to notify this task. */
        ulTaskNotifyTake( pdTRUE, portMAX_DELAY );
        uartprintf("Measure volt and current\r\n");
    }
}

void Measure_VoltCurInit(void)
{
    uartprintf("Init voltage and current sensor\r\n");
    xTaskCreate(Measure_VoltCurTimer, (const char*) "Main", 128,
                NULL, 0, &TaskMeasure);
}
