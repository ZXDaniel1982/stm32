#include "spc.h"

void Page_Init_Default(Logger logger, PageEntity_t *page)
{
	//logger("\r\nDefault\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  uint8_t lcdDef = SpcData_GetLcdDef();
  switch (lcdDef) {
  case SysStatus:
    strncpy((char *)(page->info.Title), "Sytem Status", MAX_INFO_LEN);
    strncpy((char *)(page->info.Content), "Unsupported", MAX_INFO_LEN);
    break;
  case HeatStatus:
    {
      HeatStProcess(page);
    }
    break;
  case HeatTemp:
    {
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
	default:
		return NULL;
	}
}
