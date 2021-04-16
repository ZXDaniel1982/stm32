#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "gpio.h"
#include "spc.h"

TaskHandle_t TaskMeasure = NULL;

/**
 * Voltage and current sensor handler
 */
static void Task_MeasureVoltCur(void *pvParameters)
{
    int16_t val = -50;
    while (1) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        LedBlink();
        SpcData_SetTemperature(Normal, val++, 0);
        SpcData_SetTempRTDA(Normal, val++, 0);
        SpcData_SetTempRTDB(Normal, val++, 0);
    }
}

void Measure_VoltCurInit(void)
{
    uartprintf("Init voltage and current sensor\r\n");
    xTaskCreate(Task_MeasureVoltCur, (const char *) "Measure", 256,
                NULL, 0, &TaskMeasure);
}
