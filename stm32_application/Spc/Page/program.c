#include "spc.h"

void Page_Init_Program(Logger logger)
{
	logger("Program\r\n");
}

PageEntity_t *Page_Func_Program(KeyEnum_t key, Logger logger)
{
	switch (key) {
	case Def:
		return Page_CreatePage(Default, logger);
	case Act:
		return Page_CreatePage(Actual, logger);
	default:
		return NULL;
	}
}
