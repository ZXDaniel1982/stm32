#include <stdio.h>
#include <stdlib.h>
#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "spc.h"

TaskHandle_t TaskPageMainloop = NULL;

extern xQueueHandle UartQueue;
extern xQueueHandle LabelQueue;

static void Spc_Publish(PageInfo_t *info)
{
  xQueueSend(LabelQueue, info, portMAX_DELAY);
}

/**
 * Voltage and current sensor handler
 */
static void Spc_PageMainloop(void *pvParameters)
{
	PageEntity_t *Page = NULL;
	PageEntity_t *PageNext = NULL;

	uartprintf("Spc mainloop task\r\n");
	Page = Page_CreatePage(Default, uartprintf, Spc_Publish);
	if (Page == NULL) {
		uartprintf("Failed to create page\r\n");
	}
	while (1) {
		/* Block to wait for prvTask1() to notify this task. */
    uint8_t KeyIn;
		if (xQueuePeek(UartQueue, &KeyIn, portMAX_DELAY)) {
      vTaskDelay(100);
			if (Page->func != NULL) {
				PageNext = Page->func(KeyIn, uartprintf, Page);
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
				NULL, 1, &TaskPageMainloop);
}
