#include "spc.h"

#define Refresh_Gfi_Pos (6)
#define Refresh_Gfi_Msk (1 << Refresh_Gfi_Pos)

void GfiProcess(PageEntity_t *page, SpcUint16_t *gfi)
{
    if (gfi->hasValue) {
        uint8_t content[MAX_INFO_LEN] = {0};
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", gfi->value, "mA");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "No gfi", MAX_INFO_LEN);
    }
}

void Page_Init_Gfi(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(Refresh_Gfi_Msk);
    strncpy((char *)(page->info.Title), "Gfi", MAX_INFO_LEN);

    SpcUint16_t gfi;
    if (SpcData_GetGfi(&gfi)) {
        GfiProcess(page, &gfi);
    } else {
        strncpy((char *)(page->info.Content), "Cant read gfi", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Gfi(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        if (!MenuIsNotAdvance())
            return Page_CreatePage(Statistic, logger, page->publisher);
        else
            return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Left:
    case Right:
        return Page_CreatePage(Spc_GetNextPage(logger, key, Gfi), logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Update:
        Page_Init_Gfi(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

