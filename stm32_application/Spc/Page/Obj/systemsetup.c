#include "spc.h"

void Page_Init_SystemSetup(Logger logger, PageEntity_t *page)
{
    Spc_Init_Page(logger, page, (uint8_t *)"Program", (uint8_t *)"System Setup");
}

PageEntity_t *Page_Func_SystemSetup(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        if (!MenuIsNotAdvance())
            return Page_CreatePage(SystemTest, logger, page->publisher);
        else
            return Page_CreatePage(Program, logger, page->publisher);
    case Left:
    case Right:
        return Page_CreatePage(Spc_GetNextPage(logger, key, SystemSetup), logger, page->publisher);
    default:
        return NULL;
    }
}
