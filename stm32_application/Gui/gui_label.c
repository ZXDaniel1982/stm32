#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "font.h"
#include "gui_label.h"

labelObj_t *labelHead = NULL;
labelObj_t *labelEnd = NULL;

static const GuiFont_t GuiFontList[] = {
  {'A', 12, 16, font_bitmap_A},
  {'a',  9, 16, font_bitmap_a},
  {'B', 11, 16, font_bitmap_B},
  {'b', 10, 16, font_bitmap_b}
};

static const GuiFont_t *Gui_GetFont(uint8_t ch)
{
  for (uint8_t i=0;i<NUM_ROWS(GuiFontList);i++) {
    if (ch == GuiFontList[i].ch) {
      return &GuiFontList[i];
    }
  }
  return NULL;
}

static void Gui_DrawLabel(labelObj_t *label)
{
  uint16_t x1, x2, y1, y2;

  x1 = label->x;
  y1 = label->y;

  for (uint8_t i=0;i<strlen((char *)label->info);i++) {
    const GuiFont_t *font = Gui_GetFont(label->info[i]);
    if (font == NULL)
      return;
    x2 = x1 + font->size_x - 1;
    y2 = y1 + font->size_y - 1;

    LCD_Fill(x1, y1, x2, y2, font->bitmap);
    x1 = x2 + 1;
  }
}

void Gui_CreateLabel(LabelEnum_t type, uint16_t x, uint16_t y, uint8_t *info)
{
	labelObj_t *NewLabel = (labelObj_t *) malloc(sizeof(labelObj_t));
	if (NewLabel == NULL) {
		uartprintf("Failed to create label\r\n");
	}

	NewLabel->updated = false;
	NewLabel->type = type;
	//NewLabel->pixel_origin = GetButtonPixel(type);
	//NewLabel->pixel_push = buttonBitmap_Push;
	NewLabel->x = x;
	NewLabel->y = y;
	//NewLabel->size_x = BUTTON_SIZE_X;
	//NewLabel->size_y = BUTTON_SIZE_Y;
	//NewLabel->size_total = (uint32_t) NewButton->size_x * NewButton->size_y;
  memset(NewLabel->info, 0, 16);
  strncpy((char *)NewLabel->info, (char *)info, 16);

	if (labelHead == NULL) {
		labelHead = NewLabel;
		labelEnd = labelHead;
		labelEnd->next = NULL;
		NewLabel = NULL;
	} else {
		labelEnd->next = NewLabel;
		labelEnd = NewLabel;
		labelEnd->next = NULL;
		NewLabel = NULL;
	}
}

void Gui_UpdateLabel(void)
{
	labelObj_t *labelObj = labelHead;

	while (labelObj != NULL) {
		if (!labelObj->updated) {
			Gui_DrawLabel(labelObj);
      labelObj->updated = true;
		}
		labelObj = labelObj->next;
	}
}

