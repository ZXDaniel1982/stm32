#include "spc.h"

void Page_Init_Program(Logger logger, PageEntity_t *page)
{
	//logger("\r\nProgram\r\n");
  if ((page == NULL) || (page->publisher)) return;

  strncpy((char *)(page->info.Title), "Program", MAX_INFO_LEN);
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Program(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
	switch (key) {
	case Def:
		return Page_CreatePage(Default, logger, page->publisher);
	case Act:
		return Page_CreatePage(Actual, logger, page->publisher);
	default:
		return NULL;
	}
}
