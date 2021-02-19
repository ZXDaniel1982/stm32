#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

TaskHandle_t sigrcvHandle;
TaskHandle_t sigsendHandle;

/**
 * Main loop task.
 */
static void sig_rcv(void *pvParameters)
{
    while (1) {
      ulTaskNotifyTake(pdTRUE, 2000);
      uartprintf("Got notification\r\n");
    }
}

static void sig_send(void *pvParameters)
{
    
    while (1) {
      vTaskDelay(1000);
      xTaskNotifyGive(sigrcvHandle);
    }
}

/**
 * Entry point for the application.
 */
int main()
{
    uint32_t i;

    RCC_Init();
    GPIO_Init();
    TIMER_Init();
    USART_Init();
    SPI_Init();
    FSMC_Init();
    LCD_Init();
    SDIOEx_Init();
    EEPROM_Init();

    for (i=0;i<7200000;++i) {}
    uartprintf("Start application\r\n");
    
    xTaskCreate(sig_rcv, (const char*) "Recieve", 512,
                NULL, 0, &sigrcvHandle);
    xTaskCreate(sig_send, (const char*) "Send", 512,
                NULL, 0, &sigsendHandle);

    vTaskStartScheduler();
    
    while(1) {

    }
}

void Error_Handle()
{
    while (1);
}
