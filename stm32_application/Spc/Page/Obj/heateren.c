#include "spc.h"
#include "spctimer.h"

#define HEATER_EN_POS (4)
#define HEATER_EN_MSK (0x1U)
#define HEATER_EN_POS_MSK (HEATER_EN_MSK << HEATER_EN_POS)

void HeaterEnStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    uint64_t *mask = (uint64_t *) page->data;
    uint8_t heateren = (uint8_t) (((*mask) >> HEATER_EN_POS) & HEATER_EN_MSK);

    if (heateren) {
        strncpy((char *)(page->info.Content), "Enable", MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "Disable", MAX_INFO_LEN);
    }
}

static void Page_Update_HeaterEn(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    uint64_t *mask = (uint64_t *) page->data;
    uint8_t heateren = (uint8_t) (((*mask) >> HEATER_EN_POS) & HEATER_EN_MSK);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (heateren) {
            return;
        } else {
            heateren = 1;
            MODIFY_MASK(*mask, HEATER_EN_POS_MSK, heateren << HEATER_EN_POS);
        }
    } else if (key == Down) {
        if (heateren) {
            heateren = 0;
            MODIFY_MASK(*mask, HEATER_EN_POS_MSK, heateren << HEATER_EN_POS);
        } else {
            return;
        }
    }
    HeaterEnStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_HeaterEn(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetMaskRom(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_HeaterEn(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(uint64_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetMaskRom(page->data);
    HeaterEnStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_HeaterEn(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        HeaterEnStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_HeaterEn(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    HeaterEnStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_HeaterEn(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Enable Heater", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (uint64_t *) malloc(sizeof(uint64_t));
    memset(page->data, 0, sizeof(uint64_t));
    if (SpcData_GetMaskRom(page->data)) {
        HeaterEnStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read EN", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_HeaterEn(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(HeaterName, logger, page->publisher);
    case Left:
        return Page_CreatePage(HeaterSetup, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_HeaterEn(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_HeaterEn(logger, page);
        return NULL;
    case Reset:
        Page_Reset_HeaterEn(logger, page);
        return NULL;
    case Flash:
        Page_Flash_HeaterEn(logger, page);
        return NULL;
    case Restore:
        Page_Restore_HeaterEn(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

