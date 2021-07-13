#include "spc.h"
#include "spctimer.h"

#define TEMP_UNITS_POS (2)
#define TEMP_UNITS_MSK (0x1U)
#define TEMP_UNITS_POS_MSK (TEMP_UNITS_MSK << TEMP_UNITS_POS)

void TempUnitsStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    uint64_t *mask = (uint64_t *) page->data;
    uint8_t tempunits = (uint8_t) (((*mask) >> TEMP_UNITS_POS) & TEMP_UNITS_MSK);

    if (tempunits) {
        strncpy((char *)(page->info.Content), "F", MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "C", MAX_INFO_LEN);
    }
}

static void Page_Update_TempUnits(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    uint64_t *mask = (uint64_t *) page->data;
    uint8_t tempunits = (uint8_t) (((*mask) >> TEMP_UNITS_POS) & TEMP_UNITS_MSK);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (tempunits) {
            return;
        } else {
            tempunits = 1;
            MODIFY_MASK(*mask, TEMP_UNITS_POS_MSK, tempunits << TEMP_UNITS_POS);
        }
    } else if (key == Down) {
        if (tempunits) {
            tempunits = 0;
            MODIFY_MASK(*mask, TEMP_UNITS_POS_MSK, tempunits << TEMP_UNITS_POS);
        } else {
            return;
        }
    }
    TempUnitsStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_TempUnits(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetMaskRom(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_TempUnits(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(uint64_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetMaskRom(page->data);
    TempUnitsStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_TempUnits(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        TempUnitsStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_TempUnits(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    TempUnitsStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_TempUnits(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Units", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (uint64_t *) malloc(sizeof(uint64_t));
    memset(page->data, 0, sizeof(uint64_t));
    if (SpcData_GetMaskRom(page->data)) {
        TempUnitsStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Uni", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_TempUnits(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        if (!MenuIsNotAdvance())
            return Page_CreatePage(SystemTest, logger, page->publisher);
        else
            return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
    case Left:
        return Page_CreatePage(Spc_GetNextPage(logger, key, TempUnits), logger, page->publisher);
    case Up:
    case Down:
        Page_Update_TempUnits(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_TempUnits(logger, page);
        return NULL;
    case Reset:
        Page_Reset_TempUnits(logger, page);
        return NULL;
    case Flash:
        Page_Flash_TempUnits(logger, page);
        return NULL;
    case Restore:
        Page_Restore_TempUnits(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

