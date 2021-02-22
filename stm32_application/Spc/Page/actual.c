#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "spc.h"

void Page_Init_Actual(void)
{
	uartprintf("Actual\r\n");
}

PageEntity_t *Page_Func_Actual(void)
{
	return Page_CreatePage(Program);
}
