#include "spc.h"

void Page_Init_Actual(Logger logger, PageEntity_t *page)
{
	//logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  strncpy((char *)(page->info.Title), "Actual", MAX_INFO_LEN);
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Actual(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
	switch (key) {
	case Prog:
		return Page_CreatePage(Program, logger, page->publisher);
	case Def:
		return Page_CreatePage(Default, logger, page->publisher);
	default:
		return NULL;
	}
}
