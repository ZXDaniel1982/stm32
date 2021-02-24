#include "spc.h"

void Page_Init_Actual(Logger logger)
{
	logger("Actual\r\n");
}

PageEntity_t *Page_Func_Actual(Logger logger)
{
	return Page_CreatePage(Program, logger);
}
