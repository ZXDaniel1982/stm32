#include "spc.h"
#include "data.h"

typedef enum {
  SysStatus = 0,
  HeatStatus,
  HeatTemp
} LcdDef_Enum_t;

void Page_Init_Default(Logger logger, PageEntity_t *page)
{
	//logger("\r\nDefault\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  uint8_t lcdDef = SpcData_GetLcdDef();
  switch (lcdDef) {
  case SysStatus:
    break;
  case HeatStatus:
    break;
  case HeatTemp:
    break;
  default:
    strncpy((char *)(page->info.Title), "Default Error", MAX_INFO_LEN);
    strncpy((char *)(page->info.Content), "Unsupported Def", MAX_INFO_LEN);
    page->publisher(&(page->info));
    break;
  }
}

PageEntity_t *Page_Func_Default(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
	switch (key) {
	case Prog:
		return Page_CreatePage(Program, logger, page->publisher);
	case Act:
		return Page_CreatePage(Actual, logger, page->publisher);
	default:
		return NULL;
	}
}
