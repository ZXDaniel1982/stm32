#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "gui_button.h"

TaskHandle_t TaskGui = NULL;

/**
 * Voltage and current sensor handler
 */
static void Task_GuiMainloop(void *pvParameters)
{
	uartprintf("Gui main loop\r\n");

	Gui_CreateButton(Act, 10, 10);
	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
		Gui_UpdateButton();
		vTaskDelay(300);
	}
}

void Gui_Init(void)
{
	uartprintf("Init Gui\r\n");
	xTaskCreate(Task_GuiMainloop, (const char *) "Gui", 512, NULL, 0,
				&TaskGui);
}
