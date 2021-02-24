#include "spc.h"

void Page_Init_Default(Logger logger)
{
	logger("\r\nDefault\r\n");
}

PageEntity_t *Page_Func_Default(KeyEnum_t key, Logger logger)
{
	switch (key) {
	case Prog:
		return Page_CreatePage(Program, logger);
	case Act:
		return Page_CreatePage(Actual, logger);
	default:
		return NULL;
	}
}
