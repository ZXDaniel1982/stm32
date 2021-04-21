#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "spc.h"
#include "sensor.h"

static SubVector_t *ListSensor = NULL;

static void Sensor_CreateSensor(SubVector_t *list, Timer_Enum_t type)
{
    SensorTimer_t *NewSensor = (SensorTimer_t *) Vector_List_AddElement(list, type, sizeof(SensorTimer_t));

    if (NewSensor == NULL) return;

    uint8_t name[10] = {0};
    snprintf((char *)name, 10, "Sensor%d", type);

    NewSensor->type = type;
    xTaskCreate(GetSensorFunc(type), (const char *) name, 256,
                NULL, 0, &(NewSensor->handle));
}

SensorTimer_t *Sensor_GetSensor(Timer_Enum_t type)
{
    SensorTimer_t *sensor = (SensorTimer_t *) Vector_List_GetElement(ListSensor, type);

    return sensor;
}

/**
 *  Sensor handler
 */
void Sensor_Init(void)
{
    uartprintf("Init sensor measurement\r\n");
    ListSensor = Vector_AddList(LISTSENSOR, NULL);

    for (uint8_t i=SensorTemp;i<MAX_SENSOR;i++) {
        Sensor_CreateSensor(ListSensor, i);
    }
}
