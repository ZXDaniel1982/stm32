#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

TaskHandle_t TaskMeasure = NULL;
TimerHandle_t TimerMeasure = NULL;

extern xQueueHandle TimerQueue;

/**
 * Voltage and current sensor handler
 */
static void Task_MeasureVoltCur(void *pvParameters)
{
    while (1) {
        uint8_t KeyIn;
        if (xQueueReceive(TimerQueue, &KeyIn, portMAX_DELAY)) {
            ;
        }
    }
}

void Measure_VoltCurInit(void)
{
    uartprintf("Init voltage and current sensor\r\n");
    xTaskCreate(Task_MeasureVoltCur, (const char *) "Measure", 256,
                NULL, 0, &TaskMeasure);
}
