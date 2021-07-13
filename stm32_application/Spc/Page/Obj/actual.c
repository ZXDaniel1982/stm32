#include "spc.h"

void Page_Init_Actual(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Actual", MAX_INFO_LEN);
    strncpy((char *)(page->info.Content), "Operating Values", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Actual(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        if (!MenuIsNotAdvance())
            return Page_CreatePage(Statistic, logger, page->publisher);
        else
            return NULL;
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Left:
    case Right:
        return Page_CreatePage(Spc_GetNextPage(logger, key, Actual), logger, page->publisher);
    default:
        return NULL;
    }
}
