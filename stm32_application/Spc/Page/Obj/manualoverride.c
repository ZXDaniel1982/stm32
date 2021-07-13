#include "spc.h"
#include "spctimer.h"

#define MANUAL_OVERRIDE_POS (6)
#define MANUAL_OVERRIDE_MSK (0x1U)
#define MANUAL_OVERRIDE_POS_MSK (MANUAL_OVERRIDE_MSK << MANUAL_OVERRIDE_POS)

void ManualOverrideStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    uint64_t *mask = (uint64_t *) page->data;
    uint8_t manualoverride = (uint8_t) (((*mask) >> MANUAL_OVERRIDE_POS) & MANUAL_OVERRIDE_MSK);

    if (manualoverride) {
        strncpy((char *)(page->info.Content), "On", MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "Off", MAX_INFO_LEN);
    }
}

static void Page_Update_ManualOverride(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    uint64_t *mask = (uint64_t *) page->data;
    uint8_t manualoverride = (uint8_t) (((*mask) >> MANUAL_OVERRIDE_POS) & MANUAL_OVERRIDE_MSK);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (manualoverride) {
            return;
        } else {
            manualoverride = 1;
            MODIFY_MASK(*mask, MANUAL_OVERRIDE_POS_MSK, manualoverride << MANUAL_OVERRIDE_POS);
        }
    } else if (key == Down) {
        if (manualoverride) {
            manualoverride = 0;
            MODIFY_MASK(*mask, MANUAL_OVERRIDE_POS_MSK, manualoverride << MANUAL_OVERRIDE_POS);
        } else {
            return;
        }
    }
    ManualOverrideStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_ManualOverride(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetMaskRom(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_ManualOverride(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(uint64_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetMaskRom(page->data);
    ManualOverrideStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_ManualOverride(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        ManualOverrideStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_ManualOverride(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    ManualOverrideStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_ManualOverride(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "External Disable", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (uint64_t *) malloc(sizeof(uint64_t));
    memset(page->data, 0, sizeof(uint64_t));
    if (SpcData_GetMaskRom(page->data)) {
        ManualOverrideStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Type", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_ManualOverride(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(SystemSetup, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
    case Left:
        return Page_CreatePage(Spc_GetNextPage(logger, key, ManualOverride), logger, page->publisher);
    case Up:
    case Down:
        Page_Update_ManualOverride(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_ManualOverride(logger, page);
        return NULL;
    case Reset:
        Page_Reset_ManualOverride(logger, page);
        return NULL;
    case Flash:
        Page_Flash_ManualOverride(logger, page);
        return NULL;
    case Restore:
        Page_Restore_ManualOverride(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

