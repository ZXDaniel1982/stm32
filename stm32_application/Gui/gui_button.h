#ifndef __GUI_BUTTON_H
#define __GUI_BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gui.h"

#define BUTTON_SIZE_X (48)
#define BUTTON_SIZE_Y (28)

typedef enum ButtonEnum {
    GUI_INDEX(OBJ_ENUM, NULL)
} ButtonEnum_t;

#define BUTTON_PIXEL(TYPE, type) { \
    if (TYPE == type) { \
        return buttonBitmap_##TYPE; \
    } \
}

typedef struct tButtonObj {
    bool updated;
    ButtonEnum_t type;
    const uint16_t *pixel_origin;
    const uint16_t *pixel_push;
    uint16_t x;
    uint16_t y;
    uint16_t size_x;
    uint16_t size_y;
    uint32_t size_total;
    Drawer drawer;
    struct tButtonObj *next;
} buttonObj_t;

void Gui_CreateButton(ButtonEnum_t, uint16_t, uint16_t, Drawer);
void Gui_UpdateButton(void);

#ifdef __cplusplus
}
#endif
#endif							/* __GUI_BUTTON_H */
