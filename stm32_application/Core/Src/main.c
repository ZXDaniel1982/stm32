#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

/**
 * Main loop task.
 */
static void mainLoop(void *pvParameters)
{
    Measure_VoltCurInit();
    
    while (1) {
        
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
    
    xTaskCreate(mainLoop, (const char*) "Main", 512, 
                NULL, 0, NULL);

    vTaskStartScheduler();
    
    while(1) {

    }
}

void Error_Handle()
{
    while (1);
}
