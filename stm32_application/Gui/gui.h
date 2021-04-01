#ifndef __GUI_H
#define __GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "key.h"

#define GUI_INDEX(GUI_OPT, key) \
  GUI_OPT(Act, key) \
  GUI_OPT(Prog, key) \
  GUI_OPT(Up, key) \
  GUI_OPT(Down, key) \
  GUI_OPT(Left, key) \
  GUI_OPT(Right, key) \
  GUI_OPT(Reset, key) \
  GUI_OPT(Enter, key) \
  GUI_OPT(Alarm, key)

typedef void (*Drawer)(uint8_t, uint8_t, uint8_t, uint8_t, const uint16_t *);

#ifdef __cplusplus
}
#endif
#endif							/* __GUI_H */
