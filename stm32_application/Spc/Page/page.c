#include "spc.h"

PageEntity_t *Page_CreatePage(PageEnum_t type, Logger logger)
{
	PageInit init = NULL;
	PageEntity_t *NewPage = (PageEntity_t *) malloc(sizeof(PageEntity_t));

	if (NewPage == NULL) {
		return NULL;
	}

	NewPage->type = type;
	NewPage->func = GetPageFunc(type);
	init = GetPageInit(type);
	if (init != NULL) {
		init(logger);
	}

	return NewPage;
}
