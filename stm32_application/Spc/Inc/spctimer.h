/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPCTIMER_H
#define __SPCTIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "spc.h"

#define TIMER_INDEX(TIMER_OPT) \
  TIMER_OPT(TimerFlash, Flash) \
  TIMER_OPT(TimerRestore, Restore)

#define TIMER_ENUM(TYPE, type) TYPE = type,

typedef enum SpcTimer_Enum {
    TIMER_INDEX(TIMER_ENUM)
    MAX_TIMER
} SpcTimer_Enum_t;

typedef struct tSpcTimer_t {
    SpcTimer_Enum_t type;
    bool renew;
    uint16_t count;
    uint16_t interval;
} SpcTimer_t;

void SpcTimer_Init(void);
void SpcTimer_StartTimer(SpcTimer_Enum_t type, uint16_t interval, bool renew);
void SpcTimer_StopTimer(SpcTimer_Enum_t type);
void SpcTimer_UpdateTimer(void);
void SpcTimer_StopAllTimer(void);

#ifdef __cplusplus
}
#endif

#endif /* __SPCTIMER_H */
