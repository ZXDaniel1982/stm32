#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxHighCurrent() {
    return 300;
}

static inline int16_t FetchMinHighCurrent(SpcCurrentGroupConfig_t *currentgroup) {
    SpcUint16Config_t *lowcurrent = &(currentgroup->lowcurrent);
    if (lowcurrent->status == Uint16OFF) {
        return 10;
    } else {
        return lowcurrent->value;
    }
}

static void SpcData_CorrectHighCurrent(SpcCurrentGroupConfig_t *currentgroup)
{
    if (currentgroup == NULL) return;

    SpcUint16Config_t *lowcurrent = &(currentgroup->lowcurrent);
    SpcUint16Config_t *highcurrent = &(currentgroup->highcurrent);

    if ((lowcurrent->status == Uint16Opt) &&
        (highcurrent->status == Uint16Opt)) {
        if (lowcurrent->value >= highcurrent->value) {
            lowcurrent->value = highcurrent->value - 1;
        }
    }
}

void HighCurrentStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcCurrentGroupConfig_t *currentgroup = (SpcCurrentGroupConfig_t *) page->data;
    SpcUint16Config_t *highcurrent = &(currentgroup->highcurrent);
    
    if (highcurrent->status == Uint16OFF) {
        strncpy((char *)(page->info.Content), "Off", MAX_INFO_LEN);
    } else {
        uint8_t content[MAX_INFO_LEN] = {0};
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", highcurrent->value, "A");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    }
}

static void Page_Update_HighCurrent(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcCurrentGroupConfig_t *currentgroup = (SpcCurrentGroupConfig_t *) page->data;
    SpcUint16Config_t *highcurrent = &(currentgroup->highcurrent);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (highcurrent->status == Uint16OFF) {
            return;
        } else if (highcurrent->value == FetchMaxHighCurrent()) {
            highcurrent->status = Uint16OFF;
        } else if (highcurrent->value < FetchMaxHighCurrent()) {
            highcurrent->value++;
        } else {
            logger("\r\nexit\r\n");
            return;
        }
    } else if (key == Down) {
        if (highcurrent->status == Uint16OFF) {
            highcurrent->status = Uint16Opt;
            highcurrent->value = FetchMaxHighCurrent();
        } else if (highcurrent->value > FetchMinHighCurrent(currentgroup)) {
            highcurrent->value--;
        } else {
            return;
        }
    }
    HighCurrentStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_HighCurrent(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcCurrentGroupConfig_t *currentgroup = (SpcCurrentGroupConfig_t *) page->data;
    
    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_CorrectHighCurrent(currentgroup);
    SpcData_SetCurrentGroup(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_HighCurrent(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcCurrentGroupConfig_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetCurrentGroup(page->data);
    HighCurrentStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_HighCurrent(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        HighCurrentStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_HighCurrent(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    HighCurrentStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_HighCurrent(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "High Curr Alm", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcCurrentGroupConfig_t *) malloc(sizeof(SpcCurrentGroupConfig_t));
    memset(page->data, 0, sizeof(SpcCurrentGroupConfig_t));
    if (SpcData_GetCurrentGroup(page->data)) {
        HighCurrentStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read High", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_HighCurrent(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(HeaterSetup, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
    case Left:
        return Page_CreatePage(Spc_GetNextPage(logger, key, HighCurrent), logger, page->publisher);
    case Up:
    case Down:
        Page_Update_HighCurrent(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_HighCurrent(logger, page);
        return NULL;
    case Reset:
        Page_Reset_HighCurrent(logger, page);
        return NULL;
    case Flash:
        Page_Flash_HighCurrent(logger, page);
        return NULL;
    case Restore:
        Page_Restore_HighCurrent(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

