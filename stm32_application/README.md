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

# Use indent to format C files

indent -bad -kr -br -ce -i4 -sob -ts4 -l80 *
