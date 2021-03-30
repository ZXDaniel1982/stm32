#include <stdio.h>
#include <stdlib.h>
#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "spc.h"

TaskHandle_t TaskPageMainloop = NULL;
//uint8_t KeyRecved = 0;
//uint8_t KeyString[20] = {0};

xQueueHandle pageQueue = NULL;
uint8_t keyInputForPage = 0;

static KeyEnum_t KeyType = Act;

extern xQueueHandle buttonQueue;
extern xQueueHandle labelQueue;

/**
 * Voltage and current sensor handler
 */
static void Spc_PageMainloop(void *pvParameters)
{
	PageEntity_t *Page = NULL;
	PageEntity_t *PageNext = NULL;

	uartprintf("Spc mainloop task\r\n");
	Page = Page_CreatePage(Default, uartprintf);
	if (Page == NULL) {
		uartprintf("Failed to create page\r\n");
	}
	pageQueue = xQueueCreate(1, sizeof(uint8_t));
	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
		//vTaskDelay(50);
		//if (KeyRecved == 0) continue;
		//KeyRecved = 0;
		if (xQueueReceive(pageQueue, &keyInputForPage, portMAX_DELAY)) {
			KeyType = GetKeyType(&keyInputForPage);
			xQueueSend(buttonQueue, &keyInputForPage, portMAX_DELAY);
			//memset(KeyString, 0, 20);
			if (Page->func != NULL) {
				PageNext = Page->func(KeyType, uartprintf);
				if (PageNext != NULL) {
					free(Page);
					Page = PageNext;
				}
			} else {
			}
		}
	}
}

void Page_Init(void)
{
	uartprintf("Spc page init\r\n");
	xTaskCreate(Spc_PageMainloop, (const char *) "Page", 1024,
				NULL, 0, &TaskPageMainloop);
}
