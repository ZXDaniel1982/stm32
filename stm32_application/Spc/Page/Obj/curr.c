#include "spc.h"

#define Refresh_Current_Pos (5)
#define Refresh_Current_Msk (1 << Refresh_Current_Pos)

void CurrentProcess(PageEntity_t *page, SpcUint16_t *current)
{
  if (current->hasValue) {
    uint8_t content[MAX_INFO_LEN] = {0};
    snprintf((char *)content, MAX_INFO_LEN, "%d %s", current->value, "A");
    strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
  } else {
    strncpy((char *)(page->info.Content), "No current", MAX_INFO_LEN);
  }
}

void Page_Init_Current(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(Refresh_Current_Msk);
  strncpy((char *)(page->info.Title), "Current", MAX_INFO_LEN);
 
  SpcUint16_t current;
  if (SpcData_GetCurrent(&current)) {
    CurrentProcess(page, &current);
  } else {
    strncpy((char *)(page->info.Content), "Cant read cur", MAX_INFO_LEN);
  }
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Current(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Left:
        return Page_CreatePage(Power, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Update:
        Page_Init_Current(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

