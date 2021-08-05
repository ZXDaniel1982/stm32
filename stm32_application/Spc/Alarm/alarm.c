#include "usart.h"
#include "vector.h"

static SubVector_t *ListActivedAlarms = NULL;
static SubVector_t *ListAlarmsInRam = NULL;
static SubVector_t *ListAlarmsInRom = NULL;

void SpcAlarm_Init(void)
{
    uartprintf("Init Spc Alarm\r\n");
}