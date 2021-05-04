#include "spc.h"

void Page_Init_ResetStatistic(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(DISABLE_REFRESH);
  strncpy((char *)(page->info.Title), "Reset Statistics", MAX_INFO_LEN);

  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_ResetStatistic(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Left:
        return Page_CreatePage(OnPercent, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(Version, logger, page->publisher);
    default:
        return NULL;
    }
}
