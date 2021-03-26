#include <stdio.h>
#include <unistd.h>
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#define PIC 0

void LCD_Fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, lv_color_t *color)
{
	for (int i=y1; i<=y2; i++) {
		for (int j=x1; j<=x2; j++) {
#if (PIC == 1)
			if (color->full == 0xef7e)
				printf(".");
			else if (color->full == 0xffff)
				printf(" ");
			else
				printf("*");
#else
            if ((i < 16) && (j<11))
                printf("0x%04x, ", color->full);
#endif
			color++;
		}
		printf("\n");
	}
}

void main()
{
	lv_init();
    lv_port_disp_init();

    static lv_style_t label_shadow_style;
    lv_style_init(&label_shadow_style);
    
    lv_style_set_text_opa(&label_shadow_style, LV_STATE_DEFAULT, LV_OPA_50);
    lv_style_set_text_color(&label_shadow_style, LV_STATE_DEFAULT, LV_COLOR_RED);
    
    lv_obj_t * shadow_label = lv_label_create(lv_scr_act(), NULL);
    lv_obj_add_style(shadow_label, LV_LABEL_PART_MAIN, &label_shadow_style);
    
    lv_obj_t * label1 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(label1, LV_LABEL_LONG_BREAK);
    lv_label_set_text(label1, "N");
    
    lv_label_set_text(shadow_label, lv_label_get_text(label1));
    
    lv_obj_set_pos(label1, 0, 0);
    
    lv_obj_align(shadow_label, label1, LV_ALIGN_IN_TOP_LEFT, 1, 1);

    lv_task_handler();
}
