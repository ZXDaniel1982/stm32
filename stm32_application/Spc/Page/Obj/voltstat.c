#include "spc.h"

#define Refresh_MaxVoltage_Pos (12)
#define Refresh_MaxVoltage_Msk (1 << Refresh_MaxVoltage_Pos)
#define Refresh_MinVoltage_Pos (13)
#define Refresh_MinVoltage_Msk (1 << Refresh_MinVoltage_Pos)

void Page_Init_MaxVoltage(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(Refresh_MaxVoltage_Msk);
    strncpy((char *)(page->info.Title), "Max Voltage", MAX_INFO_LEN);

    SpcUint16_t voltage;
    if (SpcData_GetMaxVoltage(&voltage)) {
        VoltageProcess(page, &voltage);
    } else {
        strncpy((char *)(page->info.Content), "Cant read maxV", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

void Page_Init_MinVoltage(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(Refresh_MinVoltage_Msk);
    strncpy((char *)(page->info.Title), "Min Voltage", MAX_INFO_LEN);

    SpcUint16_t voltage;
    if (SpcData_GetMinVoltage(&voltage)) {
        VoltageProcess(page, &voltage);
    } else {
        strncpy((char *)(page->info.Content), "Cant read minV", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_MaxVoltage(KeyEnum_t key, Logger logger, PageEntity_t *page)
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
        return Page_CreatePage(Spc_GetNextPage(logger, key, MaxVoltage), logger, page->publisher);
    case Update:
        Page_Init_MaxVoltage(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

PageEntity_t *Page_Func_MinVoltage(KeyEnum_t key, Logger logger, PageEntity_t *page)
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
        return Page_CreatePage(Spc_GetNextPage(logger, key, MinVoltage), logger, page->publisher);
    case Update:
        Page_Init_MinVoltage(logger, page);
        return NULL;
    default:
        return NULL;
    }
}
