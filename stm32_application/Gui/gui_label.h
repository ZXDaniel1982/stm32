#ifndef __GUI_LABEL_H
#define __GUI_LABEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gui.h"

#define NUM_ROWS(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))

typedef enum LabelEnum {
	Title,
	Content
} LabelEnum_t;

typedef struct {
	uint8_t ch;
	uint8_t size_x;
	uint8_t size_y;
	const uint16_t *bitmap;
} GuiFont_t;

typedef struct tLabelObj {
	bool updated;
	LabelEnum_t type;
	uint16_t x;
	uint16_t y;
	uint8_t info[16];
	Drawer drawer;
	struct tLabelObj *next;
} labelObj_t;

void Gui_CreateLabel(LabelEnum_t, uint16_t, uint16_t, uint8_t *, Drawer);
void Gui_UpdateLabel(void);

#ifdef __cplusplus
}
#endif
#endif							/* __GUI_LABEL_H */
