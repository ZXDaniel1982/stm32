/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __KEY_H
#define __KEY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// USART
typedef enum {
  Act = 0x37,
  Prog = 0x39,
  Up = 0x38,
  Down = 0x32,
  Left = 0x34,
  Right = 0x36,
  Enter = 0x35,
  Reset = 0x31,
  Alarm = 0x33
} KeyEnum_t;

#ifdef __cplusplus
}
#endif

#endif /* __KEY_H */
