#include "usart.h"
#include "gpio.h"
#include "spc.h"
#include "spctimer.h"
#include "vector.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

extern xQueueHandle UartQueue;

static SubVector_t *ListTimer = NULL;

static void SpcTimer_CreateTimer(SubVector_t *list, SpcTimer_Enum_t type)
{
    SpcTimer_t *NewTimer = (SpcTimer_t *) Vector_List_AddElement(list, type, sizeof(SpcTimer_t));

    if (NewTimer == NULL) return;

    memset(NewTimer, 0, sizeof(SpcTimer_t));
    NewTimer->type = type;
}

static void SpcTimer_WalkThroughTimer(void *data)
{
    if (data == NULL) return;

    SpcTimer_t *timer = (SpcTimer_t *) data;

    if (timer->interval > 0) {
        if (timer->count < timer->interval) {
            timer->count++;
        } else {
            timer->count = 0;
            if (!timer->renew) timer->interval = 0;
       
            uint8_t val = timer->type;
            xQueueSendFromISR(UartQueue, &val, pdFALSE);
        }
    }
}

void SpcTimer_StartTimer(SpcTimer_Enum_t type, uint16_t interval, bool renew)
{
    SpcTimer_t *timer = (SpcTimer_t *) Vector_List_GetElement(ListTimer, type);

    if (timer == NULL) return;

    timer->count = 0;
    timer->interval = interval;
    timer->renew = renew;
}

void SpcTimer_StopTimer(SpcTimer_Enum_t type)
{
    SpcTimer_t *timer = (SpcTimer_t *) Vector_List_GetElement(ListTimer, type);

    if (timer == NULL) return;

    timer->count = 0;
    timer->interval = 0;
    timer->renew = false;
}

void SpcTimer_UpdateTimer(void)
{
    Vector_List_WalkThrough(ListTimer);
}

void SpcTimer_Init(void)
{
    uartprintf("Init Spc Timer\r\n");
    ListTimer = Vector_AddList(LISTTIMER, SpcTimer_WalkThroughTimer);

    for (uint8_t i=TimerFlash;i<MAX_TIMER;i++) {
        SpcTimer_CreateTimer(ListTimer, i);
    }
}

