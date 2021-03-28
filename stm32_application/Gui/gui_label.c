#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "font.h"
#include "gui_label.h"

#define TEXT_LEN (16)

labelObj_t *labelHead = NULL;
labelObj_t *labelEnd = NULL;

static const GuiFont_t GuiFontList[] = {
	{'A', NUM_ROWS(font_bitmap_A) / TEXT_LEN, TEXT_LEN, font_bitmap_A},
	{'a', NUM_ROWS(font_bitmap_a) / TEXT_LEN, TEXT_LEN, font_bitmap_a},
	{'B', NUM_ROWS(font_bitmap_B) / TEXT_LEN, TEXT_LEN, font_bitmap_B},
	{'b', NUM_ROWS(font_bitmap_b) / TEXT_LEN, TEXT_LEN, font_bitmap_b},
	{'C', NUM_ROWS(font_bitmap_C) / TEXT_LEN, TEXT_LEN, font_bitmap_C},
	{'c', NUM_ROWS(font_bitmap_c) / TEXT_LEN, TEXT_LEN, font_bitmap_c},
	{'D', NUM_ROWS(font_bitmap_D) / TEXT_LEN, TEXT_LEN, font_bitmap_D},
	{'d', NUM_ROWS(font_bitmap_d) / TEXT_LEN, TEXT_LEN, font_bitmap_d},
	{'E', NUM_ROWS(font_bitmap_E) / TEXT_LEN, TEXT_LEN, font_bitmap_E},
	{'e', NUM_ROWS(font_bitmap_e) / TEXT_LEN, TEXT_LEN, font_bitmap_e},
	{'F', NUM_ROWS(font_bitmap_F) / TEXT_LEN, TEXT_LEN, font_bitmap_F},
	{'f', NUM_ROWS(font_bitmap_f) / TEXT_LEN, TEXT_LEN, font_bitmap_f},
	{'G', NUM_ROWS(font_bitmap_G) / TEXT_LEN, TEXT_LEN, font_bitmap_G},
	{'g', NUM_ROWS(font_bitmap_g) / TEXT_LEN, TEXT_LEN, font_bitmap_g},
	{'H', NUM_ROWS(font_bitmap_H) / TEXT_LEN, TEXT_LEN, font_bitmap_H},
	{'h', NUM_ROWS(font_bitmap_h) / TEXT_LEN, TEXT_LEN, font_bitmap_h},
	{'I', NUM_ROWS(font_bitmap_I) / TEXT_LEN, TEXT_LEN, font_bitmap_I},
	{'i', NUM_ROWS(font_bitmap_i) / TEXT_LEN, TEXT_LEN, font_bitmap_i},
	{'J', NUM_ROWS(font_bitmap_J) / TEXT_LEN, TEXT_LEN, font_bitmap_J},
	{'j', NUM_ROWS(font_bitmap_j) / TEXT_LEN, TEXT_LEN, font_bitmap_j},
	{'K', NUM_ROWS(font_bitmap_K) / TEXT_LEN, TEXT_LEN, font_bitmap_K},
	{'k', NUM_ROWS(font_bitmap_k) / TEXT_LEN, TEXT_LEN, font_bitmap_k},
	{'L', NUM_ROWS(font_bitmap_L) / TEXT_LEN, TEXT_LEN, font_bitmap_L},
	{'l', NUM_ROWS(font_bitmap_l) / TEXT_LEN, TEXT_LEN, font_bitmap_l},
	{'M', NUM_ROWS(font_bitmap_M) / TEXT_LEN, TEXT_LEN, font_bitmap_M},
	{'m', NUM_ROWS(font_bitmap_m) / TEXT_LEN, TEXT_LEN, font_bitmap_m},
	{'N', NUM_ROWS(font_bitmap_N) / TEXT_LEN, TEXT_LEN, font_bitmap_N},
	{'n', NUM_ROWS(font_bitmap_n) / TEXT_LEN, TEXT_LEN, font_bitmap_n},
	{'O', NUM_ROWS(font_bitmap_O) / TEXT_LEN, TEXT_LEN, font_bitmap_O},
	{'o', NUM_ROWS(font_bitmap_o) / TEXT_LEN, TEXT_LEN, font_bitmap_o},
	{'P', NUM_ROWS(font_bitmap_P) / TEXT_LEN, TEXT_LEN, font_bitmap_P},
	{'p', NUM_ROWS(font_bitmap_p) / TEXT_LEN, TEXT_LEN, font_bitmap_p},
	{'R', NUM_ROWS(font_bitmap_R) / TEXT_LEN, TEXT_LEN, font_bitmap_R},
	{'r', NUM_ROWS(font_bitmap_r) / TEXT_LEN, TEXT_LEN, font_bitmap_r},
	{'S', NUM_ROWS(font_bitmap_S) / TEXT_LEN, TEXT_LEN, font_bitmap_S},
	{'s', NUM_ROWS(font_bitmap_s) / TEXT_LEN, TEXT_LEN, font_bitmap_s},
	{'T', NUM_ROWS(font_bitmap_T) / TEXT_LEN, TEXT_LEN, font_bitmap_T},
	{'t', NUM_ROWS(font_bitmap_t) / TEXT_LEN, TEXT_LEN, font_bitmap_t},
	{'U', NUM_ROWS(font_bitmap_U) / TEXT_LEN, TEXT_LEN, font_bitmap_U},
	{'u', NUM_ROWS(font_bitmap_u) / TEXT_LEN, TEXT_LEN, font_bitmap_u},
	{'V', NUM_ROWS(font_bitmap_V) / TEXT_LEN, TEXT_LEN, font_bitmap_V},
	{'v', NUM_ROWS(font_bitmap_v) / TEXT_LEN, TEXT_LEN, font_bitmap_v},
	{'W', NUM_ROWS(font_bitmap_W) / TEXT_LEN, TEXT_LEN, font_bitmap_W},
	{'w', NUM_ROWS(font_bitmap_w) / TEXT_LEN, TEXT_LEN, font_bitmap_w},
	{'X', NUM_ROWS(font_bitmap_X) / TEXT_LEN, TEXT_LEN, font_bitmap_X},
	{'x', NUM_ROWS(font_bitmap_x) / TEXT_LEN, TEXT_LEN, font_bitmap_x},
	{'Y', NUM_ROWS(font_bitmap_Y) / TEXT_LEN, TEXT_LEN, font_bitmap_Y},
	{'y', NUM_ROWS(font_bitmap_y) / TEXT_LEN, TEXT_LEN, font_bitmap_y},
	{'Z', NUM_ROWS(font_bitmap_Z) / TEXT_LEN, TEXT_LEN, font_bitmap_Z},
	{'z', NUM_ROWS(font_bitmap_z) / TEXT_LEN, TEXT_LEN, font_bitmap_z},
	{'1', NUM_ROWS(font_bitmap_1) / TEXT_LEN, TEXT_LEN, font_bitmap_1},
	{'2', NUM_ROWS(font_bitmap_2) / TEXT_LEN, TEXT_LEN, font_bitmap_2},
	{'3', NUM_ROWS(font_bitmap_3) / TEXT_LEN, TEXT_LEN, font_bitmap_3},
	{'4', NUM_ROWS(font_bitmap_4) / TEXT_LEN, TEXT_LEN, font_bitmap_4},
	{'5', NUM_ROWS(font_bitmap_5) / TEXT_LEN, TEXT_LEN, font_bitmap_5},
	{'6', NUM_ROWS(font_bitmap_6) / TEXT_LEN, TEXT_LEN, font_bitmap_6},
	{'7', NUM_ROWS(font_bitmap_7) / TEXT_LEN, TEXT_LEN, font_bitmap_7},
	{'8', NUM_ROWS(font_bitmap_8) / TEXT_LEN, TEXT_LEN, font_bitmap_8},
	{'9', NUM_ROWS(font_bitmap_9) / TEXT_LEN, TEXT_LEN, font_bitmap_9},
	{'0', NUM_ROWS(font_bitmap_0) / TEXT_LEN, TEXT_LEN, font_bitmap_0},
	{'!', NUM_ROWS(font_bitmap_s1) / TEXT_LEN, TEXT_LEN, font_bitmap_s1},
	{'@', NUM_ROWS(font_bitmap_s2) / TEXT_LEN, TEXT_LEN, font_bitmap_s2},
	{'#', NUM_ROWS(font_bitmap_s3) / TEXT_LEN, TEXT_LEN, font_bitmap_s3},
	{'$', NUM_ROWS(font_bitmap_s4) / TEXT_LEN, TEXT_LEN, font_bitmap_s4},
	{'%', NUM_ROWS(font_bitmap_s5) / TEXT_LEN, TEXT_LEN, font_bitmap_s5},
	{'^', NUM_ROWS(font_bitmap_s6) / TEXT_LEN, TEXT_LEN, font_bitmap_s6},
	{'&', NUM_ROWS(font_bitmap_s7) / TEXT_LEN, TEXT_LEN, font_bitmap_s7},
	{'*', NUM_ROWS(font_bitmap_s8) / TEXT_LEN, TEXT_LEN, font_bitmap_s8},
	{'(', NUM_ROWS(font_bitmap_s9) / TEXT_LEN, TEXT_LEN, font_bitmap_s9},
	{')', NUM_ROWS(font_bitmap_s0) / TEXT_LEN, TEXT_LEN, font_bitmap_s0},
	{'-', NUM_ROWS(font_bitmap_dash) / TEXT_LEN, TEXT_LEN, font_bitmap_dash},
	{'+', NUM_ROWS(font_bitmap_plus) / TEXT_LEN, TEXT_LEN, font_bitmap_plus},
	{'=', NUM_ROWS(font_bitmap_equal) / TEXT_LEN, TEXT_LEN, font_bitmap_equal},
	{'.', NUM_ROWS(font_bitmap_dot) / TEXT_LEN, TEXT_LEN, font_bitmap_dot}
};

static const GuiFont_t *Gui_GetFont(uint8_t ch)
{
	for (uint8_t i = 0; i < NUM_ROWS(GuiFontList); i++) {
		if (ch == GuiFontList[i].ch) {
			return &GuiFontList[i];
		}
	}
	return NULL;
}

static void Gui_DrawLabel(labelObj_t * label)
{
	uint16_t x1, x2, y1, y2;

	x1 = label->x;
	y1 = label->y;

	for (uint8_t i = 0; i < strlen((char *) label->info); i++) {
		if (' ' == label->info[i]) {
			x1 += 6;
			continue;
		}

		const GuiFont_t *font = Gui_GetFont(label->info[i]);

		if (font == NULL)
			return;
		x2 = x1 + font->size_x - 1;
		y2 = y1 + font->size_y - 1;

		LCD_Fill(x1, y1, x2, y2, font->bitmap);
		x1 = x2 + 1;
	}
}

void Gui_CreateLabel(LabelEnum_t type, uint16_t x, uint16_t y, uint8_t * info)
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
	strncpy((char *) NewLabel->info, (char *) info, 16);

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
