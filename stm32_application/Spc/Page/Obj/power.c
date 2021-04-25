#include "spc.h"

#define Refresh_Voltage_Pos (4)
#define Refresh_Voltage_Msk (1 << Refresh_Voltage_Pos)

void VoltageProcess(PageEntity_t *page, SpcUint16_t *voltage)
{
  if (voltage->hasValue) {
    uint8_t content[MAX_INFO_LEN] = {0};
    snprintf((char *)content, MAX_INFO_LEN, "%d %s", voltage->value, "V");
    strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
  } else {
    strncpy((char *)(page->info.Content), "No voltage", MAX_INFO_LEN);
  }
}

void Page_Init_Voltage(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(Refresh_Voltage_Msk);
  strncpy((char *)(page->info.Title), "Voltage", MAX_INFO_LEN);
 
  SpcUint16_t voltage;
  if (SpcData_GetVoltage(&voltage)) {
    VoltageProcess(page, &voltage);
  } else {
    strncpy((char *)(page->info.Content), "Cant read volt", MAX_INFO_LEN);
  }
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Voltage(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Left:
        return Page_CreatePage(TempRTDB, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(Current, logger, page->publisher);
    case Update:
        Page_Init_Voltage(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

