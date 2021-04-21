#ifndef __GUI_BUTTON_H
#define __GUI_BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gui.h"

#define BUTTON_SIZE_X (48)
#define BUTTON_SIZE_Y (28)

#define BUTTON_PIXEL(TYPE, type) { \
    if (TYPE == type) { \
        return buttonBitmap_##TYPE; \
    } \
}

typedef struct tButtonObj {
    bool toUpdate;
    bool pushed;
    KeyEnum_t type;
    const uint16_t *pixel_origin;
    const uint16_t *pixel_push;
    uint16_t x;
    uint16_t y;
    uint16_t size_x;
    uint16_t size_y;
    uint32_t size_total;
    uint32_t push_timeout;
    uint32_t push_timer;
    uint32_t push_timer_start;
    Drawer drawer;
    Tick tick;
} buttonObj_t;

void Gui_InitButton(void);
void Gui_CreateButton(KeyEnum_t, uint16_t, uint16_t, Drawer, Tick);
void Gui_UpdateButton(void);
void Gui_PushButton(KeyEnum_t);

#ifdef __cplusplus
}
#endif
#endif							/* __GUI_BUTTON_H */
