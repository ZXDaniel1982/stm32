#include "spc.h"

void Page_Init_Default(Logger logger)
{
	logger("Default\r\n");
}

PageEntity_t *Page_Func_Default(Logger logger)
{
	return Page_CreatePage(Actual, logger);
}
