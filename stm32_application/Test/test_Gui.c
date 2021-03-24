#include <stdio.h>
#include <unistd.h>
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

void LCD_Fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, lv_color_t *color)
{
	for (int i=y1; i<=y2; i++) {
		for (int j=x1; j<=x2; j++) {
			if (color->full == 0xffff)
				printf(" ");
			else
				printf("*");
			color++;
		}
		printf("\n");
	}
}

void main()
{
	lv_init();
    lv_port_disp_init();

    lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL);     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
    lv_obj_set_size(btn, 120, 50);                          /*Set its size*/

    lv_obj_t * label = lv_label_create(btn, NULL);          /*Add a label to the button*/
    lv_label_set_text(label, "Button");                     /*Set the labels text*/

    lv_obj_t * label1 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(label1, "Hello world!");
    lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align(btn, label1, LV_ALIGN_OUT_TOP_MID, 0, -10);

    lv_task_handler();
}
