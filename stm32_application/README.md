# stm32_application

STM32 Application
==========

Design STM32 application.

# FreeRTOS not working APIs

## Software timer

xTimerCreate  xTimerStart  xTimerStop

## Task notification from ISR

vTaskNotifyGiveFromISR


# FreeRTOS working APIs

## Task normal notification

xTaskNotifyGive()  --->  ulTaskNotifyTake()
