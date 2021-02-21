#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "spc.h"

TaskHandle_t TaskPageMainloop = NULL;

/**
 * Voltage and current sensor handler
 */
static void Spc_Mainloop(void *pvParameters)
{
    uartprintf("Spc mainloop task\r\n");
    PAGE_INDEX(PAGE_INIT)
    while (1) {
      /* Block to wait for prvTask1() to notify this task. */
      vTaskDelay(5000);
    }
}

void Page_Init(void)
{
    uartprintf("Spc page init\r\n");
    xTaskCreate(Spc_Mainloop, (const char*) "Page", 512,
                NULL, 0, &TaskPageMainloop);
}
