#include "spc.h"
#include "sensor.h"

void Sensor_ProcessSensorVoltage(void *pvParameters)
{
    uint16_t val = 100;
    while (1) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        SpcData_SetVoltage(val++);
    }
}
