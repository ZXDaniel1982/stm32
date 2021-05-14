#include "spc.h"

void Page_Init_Program(Logger logger, PageEntity_t *page)
{
	//logger("\r\nProgram\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(DISABLE_REFRESH);
  strncpy((char *)(page->info.Title), "Program", MAX_INFO_LEN);
  strncpy((char *)(page->info.Content), "Setpoints", MAX_INFO_LEN);

  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Program(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
	switch (key) {
	case Def:
		return Page_CreatePage(Default, logger, page->publisher);
	case Act:
		return Page_CreatePage(Actual, logger, page->publisher);
	case Left:
        return Page_CreatePage(Version, logger, page->publisher);
  case Right:
        return Page_CreatePage(Maintain, logger, page->publisher);
	default:
		return NULL;
	}
}
