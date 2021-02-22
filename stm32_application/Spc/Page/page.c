#include <stdio.h>
#include <stdlib.h>
#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "spc.h"

TaskHandle_t TaskPageMainloop = NULL;

PageEntity_t *Page = NULL;
PageEntity_t *PageNext = NULL;

PageEntity_t *Page_CreatePage(PageEnum_t type)
{
    PageInit init = NULL;
    PageEntity_t *NewPage = (PageEntity_t *)malloc(sizeof(PageEntity_t));
    
    if (NewPage == NULL) {
        return NULL;
    }
    
    NewPage->type = type;
    NewPage->func = GetPageFunc(type);
    init = GetPageInit(type);
    if (init != NULL) {
        init();
    }
    
    return NewPage;
}

/**
 * Voltage and current sensor handler
 */
static void Spc_Mainloop(void *pvParameters)
{
    uartprintf("Spc mainloop task\r\n");
    Page = Page_CreatePage(Default);
    if (Page == NULL) {
        uartprintf("Failed to create page\r\n");
    }
    while (1) {
      /* Block to wait for prvTask1() to notify this task. */
      vTaskDelay(5000);
      if (Page->func != NULL) {
          PageNext = Page->func();
          if (PageNext != NULL) {
            free(Page);
            Page = PageNext;
          }
      }
    }
}

void Page_Init(void)
{
    uartprintf("Spc page init\r\n");
    xTaskCreate(Spc_Mainloop, (const char*) "Page", 1024,
                NULL, 0, &TaskPageMainloop);
}
