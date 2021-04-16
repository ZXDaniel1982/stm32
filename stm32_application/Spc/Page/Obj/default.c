#include "spc.h"

void Page_Init_Default(Logger logger, PageEntity_t *page)
{
	//logger("\r\nDefault\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  uint8_t lcdDef = SpcData_GetLcdDef();
  switch (lcdDef) {
  case SysStatus:
    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Sytem Status", MAX_INFO_LEN);
    strncpy((char *)(page->info.Content), "Unsupported", MAX_INFO_LEN);
    break;
  case HeatStatus:
    {
      SpcData_SetRefreshMask(Refresh_Heatst_Msk);
      HeatStProcess(page);
    }
    break;
  case HeatTemp:
    {
      SpcData_SetRefreshMask(Refresh_Temperature_Msk);
      strncpy((char *)(page->info.Title), "Heater Temp", MAX_INFO_LEN);

      SpcTemp_t temperature;
      if (SpcData_GetTemperature(&temperature)) {
        TemperatureProcess(page, &temperature);
      } else {
        strncpy((char *)(page->info.Content), "Cant read temp", MAX_INFO_LEN);
      }
    }
    break;
  default:
    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Default Error", MAX_INFO_LEN);
    strncpy((char *)(page->info.Content), "Unsupported Def", MAX_INFO_LEN);
    break;
  }
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Default(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
	switch (key) {
	case Prog:
		return Page_CreatePage(Program, logger, page->publisher);
	case Act:
  case Right:
		return Page_CreatePage(Actual, logger, page->publisher);
  case Update:
    Page_Init_Default(logger, page);
    return NULL;
	default:
		return NULL;
	}
}
