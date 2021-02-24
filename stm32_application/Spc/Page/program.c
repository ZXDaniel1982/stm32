#include "spc.h"

void Page_Init_Program(Logger logger)
{
	logger("Program\r\n");
}

PageEntity_t *Page_Func_Program(Logger logger)
{
	return Page_CreatePage(Default, logger);
}
