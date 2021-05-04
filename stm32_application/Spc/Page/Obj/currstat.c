#include "spc.h"

#define Refresh_MaxCurrent_Pos (10)
#define Refresh_MaxCurrent_Msk (1 << Refresh_MaxCurrent_Pos)

void Page_Init_MaxCurrent(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(Refresh_MaxCurrent_Msk);
  strncpy((char *)(page->info.Title), "Max Current", MAX_INFO_LEN);

  SpcUint16_t current;
  if (SpcData_GetMaxCurrent(&current)) {
    CurrentProcess(page, &current);
  } else {
    strncpy((char *)(page->info.Content), "Cant read maxC", MAX_INFO_LEN);
  }
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_MaxCurrent(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(MaxGfi, logger, page->publisher);
    case Left:
        return Page_CreatePage(MinTemperature, logger, page->publisher);
    case Update:
        Page_Init_MaxCurrent(logger, page);
        return NULL;
    default:
        return NULL;
    }
}
