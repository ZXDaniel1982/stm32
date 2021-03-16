#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "lvgl.h"

TaskHandle_t TaskGuiMainloop = NULL;

static void Gui_Mainloop(void *pvParameters)
{
    lv_init();
    
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
