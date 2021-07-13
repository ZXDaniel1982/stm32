#include "spc.h"

#define Refresh_OnTime_Pos (16)
#define Refresh_OnTime_Msk (1 << Refresh_OnTime_Pos)
#define Refresh_OnPercent_Pos (17)
#define Refresh_OnPercent_Msk (1 << Refresh_OnPercent_Pos)

void OnTimeProcess(PageEntity_t *page, SpcUint16_t *Ontime)
{
    if (Ontime->hasValue) {
        uint8_t content[MAX_INFO_LEN] = {0};
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", Ontime->value, "hours");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "No on time", MAX_INFO_LEN);
    }
}

void OnPercentProcess(PageEntity_t *page, SpcUint16_t *OnPercent)
{
    if (OnPercent->hasValue) {
        uint8_t content[MAX_INFO_LEN] = {0};
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", OnPercent->value, "%");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "No percent", MAX_INFO_LEN);
    }
}

void Page_Init_OnTime(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(Refresh_OnTime_Msk);
    strncpy((char *)(page->info.Title), "Heater On Time", MAX_INFO_LEN);

    SpcUint16_t OnTime;
    if (SpcData_GetOnTime(&OnTime)) {
        OnTimeProcess(page, &OnTime);
    } else {
        strncpy((char *)(page->info.Content), "Cant read OnTime", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

void Page_Init_OnPercent(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(Refresh_OnPercent_Msk);
    strncpy((char *)(page->info.Title), "Heater On Perc", MAX_INFO_LEN);

    SpcUint16_t OnPercent;
    if (SpcData_GetOnPercent(&OnPercent)) {
        OnPercentProcess(page, &OnPercent);
    } else {
        strncpy((char *)(page->info.Content), "Cant read OnPercent", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_OnTime(KeyEnum_t key, Logger logger, PageEntity_t *page)
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
        return Page_CreatePage(Spc_GetNextPage(logger, key, OnTime), logger, page->publisher);
    case Update:
        Page_Init_OnTime(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

PageEntity_t *Page_Func_OnPercent(KeyEnum_t key, Logger logger, PageEntity_t *page)
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
        return Page_CreatePage(Spc_GetNextPage(logger, key, OnPercent), logger, page->publisher);
    case Update:
        Page_Init_OnPercent(logger, page);
        return NULL;
    default:
        return NULL;
    }
}
