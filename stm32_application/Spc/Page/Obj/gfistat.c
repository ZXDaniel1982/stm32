#include "spc.h"

#define Refresh_MaxGfi_Pos (11)
#define Refresh_MaxGfi_Msk (1 << Refresh_MaxGfi_Pos)

void Page_Init_MaxGfi(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(Refresh_MaxGfi_Msk);
  strncpy((char *)(page->info.Title), "Max Ground Faul", MAX_INFO_LEN);

  SpcUint16_t gfi;
  if (SpcData_GetMaxGfi(&gfi)) {
    GfiProcess(page, &gfi);
  } else {
    strncpy((char *)(page->info.Content), "Cant read maxG", MAX_INFO_LEN);
  }
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_MaxGfi(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(MaxVoltage, logger, page->publisher);
    case Left:
        return Page_CreatePage(MaxCurrent, logger, page->publisher);
    case Update:
        Page_Init_MaxGfi(logger, page);
        return NULL;
    default:
        return NULL;
    }
}
