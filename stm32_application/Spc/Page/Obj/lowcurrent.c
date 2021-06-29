#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxLowCurrent(SpcCurrentGroupConfig_t* currentgroup) {
    SpcUint16Config_t *highcurrent = &(currentgroup->highcurrent);
    if (highcurrent->status == Uint16OFF) {
        return 290;
    } else {
        return highcurrent->value;
    }
}

static inline uint16_t FetchMinLowCurrent() {
    return 1;
}

static void SpcData_CorrectLowCurrent(SpcCurrentGroupConfig_t *currentgroup)
{
    if (currentgroup == NULL) return;

    SpcUint16Config_t *lowcurrent = &(currentgroup->lowcurrent);
    SpcUint16Config_t *highcurrent = &(currentgroup->highcurrent);

    if ((lowcurrent->status == Uint16Opt) &&
        (highcurrent->status == Uint16Opt)) {
        if (lowcurrent->value >= highcurrent->value) {
            highcurrent->value = lowcurrent->value + 1;
        }
    }
}

void LowCurrentStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcCurrentGroupConfig_t *currentgroup = (SpcCurrentGroupConfig_t *) page->data;
    SpcUint16Config_t *lowcurrent = &(currentgroup->lowcurrent);
    
    if (lowcurrent->status == Uint16OFF) {
        strncpy((char *)(page->info.Content), "Off", MAX_INFO_LEN);
    } else {
        uint8_t content[MAX_INFO_LEN] = {0};
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", lowcurrent->value, "A");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    }
}

static void Page_Update_LowCurrent(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcCurrentGroupConfig_t *currentgroup = (SpcCurrentGroupConfig_t *) page->data;
    SpcUint16Config_t *lowcurrent = &(currentgroup->lowcurrent);

    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);

    if (key == Up) {
        if (lowcurrent->status == Uint16OFF) {
            return;
        } else if (lowcurrent->value == FetchMaxLowCurrent(currentgroup)) {
            lowcurrent->status = Uint16OFF;
        } else if (lowcurrent->value < FetchMaxLowCurrent(currentgroup)) {
            lowcurrent->value++;
        } else {
            return;
        }
    } else if (key == Down) {
        if (lowcurrent->status == Uint16OFF) {
            lowcurrent->status = Uint16Opt;
            lowcurrent->value = FetchMaxLowCurrent(currentgroup);
        } else if (lowcurrent->value > FetchMinLowCurrent()) {
            lowcurrent->value--;
        } else {
            return;
        }
    }
    LowCurrentStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_LowCurrent(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcCurrentGroupConfig_t *currentgroup = (SpcCurrentGroupConfig_t *) page->data;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_CorrectLowCurrent(currentgroup);
    SpcData_SetCurrentGroup(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_LowCurrent(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcCurrentGroupConfig_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetCurrentGroup(page->data);
    LowCurrentStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_LowCurrent(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        LowCurrentStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_LowCurrent(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    LowCurrentStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_LowCurrent(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Low Current Alm", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcCurrentGroupConfig_t *) malloc(sizeof(SpcCurrentGroupConfig_t));
    memset(page->data, 0, sizeof(SpcCurrentGroupConfig_t));
    if (SpcData_GetCurrentGroup(page->data)) {
        LowCurrentStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Low", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_LowCurrent(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(HighCurrent, logger, page->publisher);
    case Left:
        return Page_CreatePage(HighTemp, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_LowCurrent(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_LowCurrent(logger, page);
        return NULL;
    case Reset:
        Page_Reset_LowCurrent(logger, page);
        return NULL;
    case Flash:
        Page_Flash_LowCurrent(logger, page);
        return NULL;
    case Restore:
        Page_Restore_LowCurrent(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

