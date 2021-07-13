#include "spc.h"

#define Refresh_Power_Pos (4)
#define Refresh_Power_Msk (1 << Refresh_Power_Pos)

void PowerProcess(PageEntity_t *page, SpcUint16_t *Power)
{
    if (Power->hasValue) {
        uint8_t content[MAX_INFO_LEN] = {0};
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", Power->value, "%");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "No Power", MAX_INFO_LEN);
    }
}

void Page_Init_Power(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(Refresh_Power_Msk);
    strncpy((char *)(page->info.Title), "Power", MAX_INFO_LEN);

    SpcUint16_t Power;
    if (SpcData_GetPower(&Power)) {
        PowerProcess(page, &Power);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Power", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Power(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        if (!MenuIsNotAdvance())
            return Page_CreatePage(Statistic, logger, page->publisher);
        else
            return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Left:
    case Right:
        return Page_CreatePage(Spc_GetNextPage(logger, key, Power), logger, page->publisher);
    case Update:
        Page_Init_Power(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

