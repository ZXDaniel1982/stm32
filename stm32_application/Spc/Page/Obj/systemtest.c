#include "spc.h"

void Page_Init_SystemTest(Logger logger, PageEntity_t *page)
{
	Spc_Init_Page(logger, page, (uint8_t *)"Program", (uint8_t *)"System Test");
}

PageEntity_t *Page_Func_SystemTest(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
	switch (key) {
	case Def:
		return Page_CreatePage(Default, logger, page->publisher);
	case Act:
		return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Left:
    case Right:
        return Page_CreatePage(Spc_GetNextPage(logger, key, SystemTest), logger, page->publisher);
	default:
		return NULL;
	}
}
