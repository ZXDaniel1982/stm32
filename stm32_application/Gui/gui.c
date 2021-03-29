#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "gui_button.h"
#include "gui_label.h"
#include "lcd.h"

TaskHandle_t TaskGui = NULL;

/**
 * Voltage and current sensor handler
 */
static void Task_GuiMainloop(void *pvParameters)
{
	uartprintf("Gui main loop\r\n");

	Gui_CreateLabel(Title, 		10, 	30, 	(uint8_t *) "wwwwwwwwwwwwwwww", LCD_Fill);
	Gui_CreateLabel(Content, 	10, 	50, 	(uint8_t *) "wwwwwwwwwwwwwwww", LCD_Fill);
	Gui_CreateButton(Act, 		30, 	120, 	LCD_Fill);
	Gui_CreateButton(Up, 		90, 	120, 	LCD_Fill);
	Gui_CreateButton(Prog, 		150, 	120, 	LCD_Fill);
	Gui_CreateButton(Left, 		30, 	170, 	LCD_Fill);
	Gui_CreateButton(Enter, 	90, 	170, 	LCD_Fill);
	Gui_CreateButton(Right, 	150, 	170, 	LCD_Fill);
	Gui_CreateButton(Reset, 	30, 	220, 	LCD_Fill);
	Gui_CreateButton(Down, 		90, 	220, 	LCD_Fill);
	Gui_CreateButton(Alarm, 	150, 	220, 	LCD_Fill);
	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
		Gui_UpdateButton();
		Gui_UpdateLabel();
		vTaskDelay(300);
	}
}

void Gui_Init(void)
{
	uartprintf("Init Gui\r\n");
	xTaskCreate(Task_GuiMainloop, (const char *) "Gui", 512, NULL, 0, &TaskGui);
}
