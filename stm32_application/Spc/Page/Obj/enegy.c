#include "spc.h"

#define Refresh_Enegy_Pos (14)
#define Refresh_Enegy_Msk (1 << Refresh_Enegy_Pos)
#define Refresh_Cost_Pos (15)
#define Refresh_Cost_Msk (1 << Refresh_Cost_Pos)

void EnegyProcess(PageEntity_t *page, SpcUint16_t *Enegy)
{
    if (Enegy->hasValue) {
        uint8_t content[MAX_INFO_LEN] = {0};
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", Enegy->value, "kwh");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "No Enegy", MAX_INFO_LEN);
    }
}

void CostProcess(PageEntity_t *page, SpcUint16_t *Cost)
{
    if (Cost->hasValue) {
        uint8_t content[MAX_INFO_LEN] = {0};
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", Cost->value, "$");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "No Cost", MAX_INFO_LEN);
    }
}

void Page_Init_Enegy(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(Refresh_Enegy_Msk);
    strncpy((char *)(page->info.Title), "Total Energy", MAX_INFO_LEN);

    SpcUint16_t Enegy;
    if (SpcData_GetEnegy(&Enegy)) {
        EnegyProcess(page, &Enegy);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Enegy", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

void Page_Init_Cost(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(Refresh_Cost_Msk);
    strncpy((char *)(page->info.Title), "Total Cost", MAX_INFO_LEN);

    SpcUint16_t Cost;
    if (SpcData_GetCost(&Cost)) {
        CostProcess(page, &Cost);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Cost", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Enegy(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Left:
    case Right:
        return Page_CreatePage(Spc_GetNextPage(logger, key, Enegy), logger, page->publisher);
    case Update:
        Page_Init_Enegy(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

PageEntity_t *Page_Func_Cost(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Left:
    case Right:
        return Page_CreatePage(Spc_GetNextPage(logger, key, Cost), logger, page->publisher);
    case Update:
        Page_Init_Cost(logger, page);
        return NULL;
    default:
        return NULL;
    }
}
