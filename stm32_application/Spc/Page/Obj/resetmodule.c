#include "spc.h"

void Page_Init_ResetModule(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(DISABLE_REFRESH);
  strncpy((char *)(page->info.Title), "Reset Module", MAX_INFO_LEN);

  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_ResetModule(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Left:
        return Page_CreatePage(Baudrate, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(SystemTest, logger, page->publisher);
    default:
        return NULL;
    }
}
