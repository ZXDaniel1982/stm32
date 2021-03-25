#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

TaskHandle_t TaskGui = NULL;

/**
 * Voltage and current sensor handler
 */
static void Task_GuiMainloop(void *pvParameters)
{
	uartprintf("Measure volt and current\r\n");

	Gui_CreateButton();
	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
		vTaskDelay(5000);
	}
}

void Gui_Init(void)
{
	uartprintf("Init Gui\r\n");
	xTaskCreate(Task_GuiMainloop, (const char *) "Gui", 512, NULL, 0,
				&TaskGui);
}