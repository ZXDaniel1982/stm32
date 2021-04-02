/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIMER_H
#define __TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void Timer_TickInc(void);
uint32_t Timer_GetTick(void);

#ifdef __cplusplus
}
#endif

#endif /* __TIMER_H */
