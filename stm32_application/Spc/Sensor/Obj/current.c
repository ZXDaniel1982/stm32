#include "spc.h"
#include "sensor.h"

void Sensor_ProcessSensorCurrent(void *pvParameters)
{
    uint16_t val = 10;
    while (1) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        SpcData_SetCurrent(val++);
    }
}

