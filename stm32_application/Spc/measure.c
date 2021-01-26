#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

static xTimerHandle VoltCurrTimer = NULL;

static void Measure_VoltCurTimer(xTimerHandle unused)
{
    uartprintf("Measure volt and current\r\n");
}

void Measure_VoltCurInit(void)
{
    // Start a periodic request for connection
    const char* name = (const char*)"Volt Current measure";
    VoltCurrTimer = xTimerCreate(name,
                                 5,
                                 pdTRUE,
                                 NULL,
                                 Measure_VoltCurTimer);
    xTimerStart(VoltCurrTimer, 0);
}
