#include "spc.h"

PageEntity_t *Page_CreatePage(PageEnum_t type, Logger logger, Publisher pub)
{
    PageInit init = NULL;
    PageEntity_t *NewPage = (PageEntity_t *) malloc(sizeof(PageEntity_t));

    if (NewPage == NULL) {
        return NULL;
    }

    memset(NewPage, 0 , sizeof(PageEntity_t));

    NewPage->type = type;
    NewPage->func = GetPageFunc(type);
    NewPage->publisher = pub;
    memset(NewPage->info.Title, 0, MAX_INFO_LEN);
    memset(NewPage->info.Content, 0, MAX_INFO_LEN);
    init = GetPageInit(type);
    if (init != NULL) {
        init(logger, NewPage);
    }

    return NewPage;
}
