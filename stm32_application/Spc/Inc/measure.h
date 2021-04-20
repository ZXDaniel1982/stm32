/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MEASURE_H
#define __MEASURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "task.h"

typedef enum {
    Temperature = 0
} MeasTimer_Enum_t;

typedef struct tMeasTimer_t {
    MeasTimer_Enum_t type;
    TaskHandle_t handle;
    struct tMeasTimer_t *next;
} MeasTimer_t;

#ifdef __cplusplus
}
#endif

#endif /* __MEASURE_H */
