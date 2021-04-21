/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SENSOR_H
#define __SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "timer.h"
#include "semphr.h"
#include "vector.h"

#define SENSOR_FUNC_DECLARE(TYPE, type) void Sensor_Process##TYPE(void *);

#define SENSOR_FUNC(TYPE, type) { \
    if (TYPE == type) { \
        return Sensor_Process##TYPE; \
    } \
}

SENSOR_INDEX(SENSOR_FUNC_DECLARE, NULL)

static inline TaskFunction_t GetSensorFunc(Timer_Enum_t type) {
	SENSOR_INDEX(SENSOR_FUNC, type)
    return NULL;
}

typedef struct tSensorTimer_t {
    Timer_Enum_t type;
    TaskHandle_t handle;
} SensorTimer_t;

SensorTimer_t *Sensor_GetSensor(Timer_Enum_t type);

#ifdef __cplusplus
}
#endif

#endif /* __SENSOR_H */
