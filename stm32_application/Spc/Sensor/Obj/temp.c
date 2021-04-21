#include "spc.h"
#include "sensor.h"

void Sensor_ProcessSensorTemp(void *pvParameters)
{
    int16_t val = -50;
    while (1) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        SpcData_SetTemperature(Normal, val++, 0);
        SpcData_SetTempRTDA(Normal, val++, 0);
        SpcData_SetTempRTDB(Normal, val++, 0);
    }
}
