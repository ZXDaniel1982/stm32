#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

TaskHandle_t TaskGui = NULL;

static uint32_t count = 0;
/**
 * Voltage and current sensor handler
 */
static void task_GuiMainloop(void *pvParameters)
{
	tftprintf("Gui task main loop");
	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
		vTaskDelay(1000);
    tftprintf("Measue count %d", count++);
	}
}

void Gui_Init(void)
{
	uartprintf("Init Gui\r\n");
	xTaskCreate(task_GuiMainloop, (const char *) "Gui", 128, NULL, 1,
				&TaskGui);
}
