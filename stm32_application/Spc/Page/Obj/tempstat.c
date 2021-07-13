#include "spc.h"

#define Refresh_MaxTemperature_Pos (8)
#define Refresh_MaxTemperature_Msk (1 << Refresh_MaxTemperature_Pos)
#define Refresh_MinTemperature_Pos (9)
#define Refresh_MinTemperature_Msk (1 << Refresh_MinTemperature_Pos)

void Page_Init_MaxTemperature(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(Refresh_MaxTemperature_Msk);
    strncpy((char *)(page->info.Title), "Max Temperature", MAX_INFO_LEN);

    SpcTemp_t temperature;
    if (SpcData_GetMaxTemperature(&temperature)) {
        TemperatureProcess(page, &temperature);
    } else {
        strncpy((char *)(page->info.Content), "Cant read maxT", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

void Page_Init_MinTemperature(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(Refresh_MinTemperature_Msk);
    strncpy((char *)(page->info.Title), "Min Temperature", MAX_INFO_LEN);

    SpcTemp_t temperature;
    if (SpcData_GetMinTemperature(&temperature)) {
        TemperatureProcess(page, &temperature);
    } else {
        strncpy((char *)(page->info.Content), "Cant read minT", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_MaxTemperature(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
    case Left:
        return Page_CreatePage(Spc_GetNextPage(logger, key, MaxTemperature), logger, page->publisher);
    case Update:
        Page_Init_MaxTemperature(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

PageEntity_t *Page_Func_MinTemperature(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
    case Left:
        return Page_CreatePage(Spc_GetNextPage(logger, key, MinTemperature), logger, page->publisher);
    case Update:
        Page_Init_MinTemperature(logger, page);
        return NULL;
    default:
        return NULL;
    }
}
