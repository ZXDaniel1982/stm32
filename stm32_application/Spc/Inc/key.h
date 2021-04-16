/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __KEY_H
#define __KEY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// USART
typedef enum {
  Update = 0,
  Def = 0x30,     // 48
  Act = 0x37,     // 55
  Prog = 0x39,    // 57
  Up = 0x38,      // 56
  Down = 0x32,    // 50
  Left = 0x34,    // 52
  Right = 0x36,   // 54
  Enter = 0x35,   // 53
  Reset = 0x31,   // 49
  Alarm = 0x33    // 51
} KeyEnum_t;

#ifdef __cplusplus
}
#endif

#endif /* __KEY_H */
