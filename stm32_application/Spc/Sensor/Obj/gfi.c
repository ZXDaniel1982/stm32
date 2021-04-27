#include "spc.h"
#include "sensor.h"

void Sensor_ProcessSensorGfi(void *pvParameters)
{
    uint16_t val = 350;
    while (1) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        SpcData_SetGfi(val++);
    }
}

