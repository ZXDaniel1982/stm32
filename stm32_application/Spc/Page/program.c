#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"
#include "spc.h"

void Page_Init_Program(void)
{
	uartprintf("Program\r\n");
}

PageEntity_t *Page_Func_Program(void)
{
	return Page_CreatePage(Default);
}
