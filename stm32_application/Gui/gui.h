#ifndef __GUI_H
#define __GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "lcd.h"

#define ToString(x) #x

#define GUI_INDEX(GUI_OPT, key) \
  GUI_OPT(Act, key) \
  GUI_OPT(Prog, key) \
  GUI_OPT(Up, key) \
  GUI_OPT(Down, key) \
  GUI_OPT(Left, key) \
  GUI_OPT(Right, key) \
  GUI_OPT(Reset, key) \
  GUI_OPT(Alarm, key)

#define OBJ_ENUM(TYPE, type) TYPE,

#ifdef __cplusplus
}
#endif

#endif /* __GUI_H */
