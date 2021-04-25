/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIMER_H
#define __TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define SENSOR_INDEX(SENSOR_OPT, type) \
  SENSOR_OPT(SensorTemp, type) \
  SENSOR_OPT(SensorVoltage, type) \
  SENSOR_OPT(SensorCurrent, type)

#define OBJ_ENUM(TYPE, type) TYPE,

typedef enum Timer_Enum {
    SENSOR_INDEX(OBJ_ENUM, NULL)
    MAX_SENSOR
} Timer_Enum_t;

void Timer_TickInc(void);
uint32_t Timer_GetTick(void);

#ifdef __cplusplus
}
#endif

#endif /* __TIMER_H */
