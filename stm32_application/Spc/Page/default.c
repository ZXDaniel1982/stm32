#include "spc.h"

void Page_Init_Default(Logger logger, PageEntity_t *page)
{
	//logger("\r\nDefault\r\n");
  if ((page == NULL) || (page->publisher)) return;

  strncpy((char *)(page->info.Title), "Default", MAX_INFO_LEN);
  page->publisher(&(page->info));
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
