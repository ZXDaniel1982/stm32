#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "GUI.h"
#include "GUI_Type.h"
#include "GUI_ConfDefaults.h"
#include "WM.h"

TaskHandle_t TaskGui = NULL;

/**
 * Voltage and current sensor handler
 */
static void task_GuiMainloop(void *pvParameters)
{
  uartprintf("X %d, Y %d\r\n", LCD_GetXSize(), LCD_GetYSize());
	GUI_Init();
	//WM_SetCreateFlags(WM_CF_MEMDEV);

	GUI_Clear();
	GUI_SetFont(&GUI_Font20_1);
	GUI_DispStringAt("Hello world!", (LCD_GetXSize()-100)/2, (LCD_GetYSize()-20)/2);

  uartprintf("X %d, Y %d\r\n", LCD_GetXSize(), LCD_GetYSize());

	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
		vTaskDelay(5000);
	}
}

void Gui_Init(void)
{
	uartprintf("Init Gui\r\n");
	xTaskCreate(task_GuiMainloop, (const char *) "Gui", 512, NULL, 1,
				&TaskGui);
}
