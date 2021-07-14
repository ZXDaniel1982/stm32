#include "spc.h"

void Page_Init_Statistic(Logger logger, PageEntity_t *page)
{
    Spc_Init_Page(logger, page, (uint8_t *)"Actual", (uint8_t *)"Statistics");
}

PageEntity_t *Page_Func_Statistic(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
    case Left:
        return Page_CreatePage(Spc_GetNextPage(logger, key, Statistic), logger, page->publisher);
    default:
        return NULL;
    }
}
