#include "spc.h"

void Page_Init_Actual(Logger logger)
{
	logger("Actual\r\n");
}

PageEntity_t *Page_Func_Actual(KeyEnum_t key, Logger logger)
{
	switch (key) {
	case Prog:
		return Page_CreatePage(Program, logger);
	case Def:
		return Page_CreatePage(Default, logger);
	default:
		return NULL;
	}
}
