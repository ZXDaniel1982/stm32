#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "gui_button.h"
#include "gui_label.h"
#include "lcd.h"

TaskHandle_t TaskButton = NULL;
TaskHandle_t TaskLabel = NULL;
xQueueHandle LabelQueue = NULL;

extern xQueueHandle UartQueue;

uint8_t labelInfo[32] = {0};

/**
 * Voltage and current sensor handler
 */
static void Task_ButtonHandle(void *pvParameters)
{
	uartprintf("Button task handler\r\n");

	Gui_CreateButton(Act, 		30, 	120, 	LCD_Fill);
	Gui_CreateButton(Up, 		90, 	120, 	LCD_Fill);
	Gui_CreateButton(Prog, 		150, 	120, 	LCD_Fill);
	Gui_CreateButton(Left, 		30, 	170, 	LCD_Fill);
	Gui_CreateButton(Enter, 	90, 	170, 	LCD_Fill);
	Gui_CreateButton(Right, 	150, 	170, 	LCD_Fill);
	Gui_CreateButton(Reset, 	30, 	220, 	LCD_Fill);
	Gui_CreateButton(Down, 		90, 	220, 	LCD_Fill);
	Gui_CreateButton(Alarm, 	150, 	220, 	LCD_Fill);
	Gui_UpdateButton();
	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
    uint8_t KeyIn;
		if (xQueueReceive(UartQueue, &KeyIn, portMAX_DELAY)) {
      uartprintf("Got button input\r\n");
    }
	}
}

static void Task_LabelHandle(void *pvParameters)
{
	uartprintf("Label task handler\r\n");

	Gui_CreateLabel(Title, 		10, 	30, 	(uint8_t *) "wwwwwwwwwwwwwwww", LCD_Fill);
	Gui_CreateLabel(Content, 	10, 	50, 	(uint8_t *) "wwwwwwwwwwwwwwww", LCD_Fill);
	Gui_UpdateLabel();
	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
		if (xQueueReceive(LabelQueue, labelInfo, portMAX_DELAY)) {
      ;
    }
	}
}

void Gui_Init(void)
{
	uartprintf("Init Gui\r\n");
	LabelQueue = xQueueCreate(32, sizeof(uint8_t));
	xTaskCreate(Task_ButtonHandle, (const char *) "Button", 256, NULL, 0, &TaskButton);
	xTaskCreate(Task_LabelHandle, (const char *) "Label", 256, NULL, 0, &TaskLabel);
}
