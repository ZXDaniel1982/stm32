#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "spc.h"

void Page_Init_Default(void)
{
	uartprintf("Default\r\n");
}

PageEntity_t *Page_Func_Default(void)
{
	return Page_CreatePage(Actual);
}
