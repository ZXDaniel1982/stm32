#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

TaskHandle_t TaskGuiMainloop = NULL;


static void btn_event_cb(lv_obj_t * btn, lv_event_t event)
{
    return;
}

static void Gui_Mainloop(void *pvParameters)
{
    lv_init();
    lv_port_disp_init();

    lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL);     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
    lv_obj_set_size(btn, 120, 50);                          /*Set its size*/
    lv_obj_set_event_cb(btn, btn_event_cb);                 /*Assign a callback to the button*/

    lv_obj_t * label = lv_label_create(btn, NULL);          /*Add a label to the button*/
    lv_label_set_text(label, "Button");                     /*Set the labels text*/

    lv_obj_t * label1 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(label1, "Hello world!");
    lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align(btn, label1, LV_ALIGN_OUT_TOP_MID, 0, -10);

    while (1) {
        lv_task_handler();
        vTaskDelay(5);
    }
}

void Gui_init(void)
{
	uartprintf("Gui init\r\n");
	xTaskCreate(Gui_Mainloop, (const char *) "Gui", 128,
				NULL, 0, &TaskGuiMainloop);
}
