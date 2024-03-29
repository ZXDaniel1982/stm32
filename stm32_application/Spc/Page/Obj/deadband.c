#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxDeadBand(bool unit) {
    return unit ? 10 : 5;
}

static inline int16_t FetchMinDeadBand() {
    return 1;
}

static void SpcData_CorrectDeadBand(SpcTempGroupConfig_t *tempgroup)
{
    if (tempgroup == NULL) return;

    const uint8_t unit = SpcData_GetTempUint();
    const uint8_t proctrl = SpcData_GetCtrlType();
    SpcTempConfig_t *maintain = &(tempgroup->maintain);
    SpcTempConfig_t *lowtemp = &(tempgroup->lowtemp);
    SpcTempConfig_t *hightemp = &(tempgroup->hightemp);
    SpcTempConfig_t *deadband = &(tempgroup->deadband);

    if (maintain->status != Opt) return;

    if (lowtemp->status == Opt) {
        int16_t maxtemp = proctrl ? maintain->temperature[unit] :
            maintain->temperature[unit] - deadband->temperature[unit];
        if (lowtemp->temperature[unit] >= maxtemp) {
            lowtemp->temperature[unit] = maxtemp - 1;
        }
    }
    if (hightemp->status == Opt) {
        int16_t maxtemp = proctrl ? maintain->temperature[unit] :
            maintain->temperature[unit] + deadband->temperature[unit];
        if (hightemp->temperature[unit] <= maxtemp) {
            hightemp->temperature[unit] = maxtemp + 1;
        }
    }
}

void DeadBandStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcTempGroupConfig_t *tempgroup = (SpcTempGroupConfig_t *) page->data;
    uint8_t content[MAX_INFO_LEN] = {0};
    const uint8_t unit = SpcData_GetTempUint();
    snprintf((char *)content, MAX_INFO_LEN, "%d %s", tempgroup->deadband.temperature[unit],
        unit ? "F" : "C");
    strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
}

static void Page_Update_DeadBand(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcTempGroupConfig_t *tempgroup = (SpcTempGroupConfig_t *) page->data;
    const uint8_t unit = SpcData_GetTempUint();

    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);

    if (key == Up) {
        if (tempgroup->deadband.temperature[unit] < FetchMaxDeadBand(unit)) {
            tempgroup->deadband.temperature[unit]++;
        }
    } else if (key == Down) {
        if (tempgroup->maintain.temperature[unit] > FetchMinDeadBand()) {
            tempgroup->maintain.temperature[unit]--;
        }
    }
    DeadBandStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_DeadBand(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;


    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_CorrectDeadBand(page->data);
    SpcData_SetTempGroup(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_DeadBand(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcTempGroupConfig_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetTempGroup(page->data);
    DeadBandStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_DeadBand(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        DeadBandStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_DeadBand(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    DeadBandStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_DeadBand(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "DeadBand Temp", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcTempGroupConfig_t *) malloc(sizeof(SpcTempGroupConfig_t));
    memset(page->data, 0, sizeof(SpcTempGroupConfig_t));
    if (SpcData_GetTempGroup(page->data)) {
        DeadBandStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Main", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_DeadBand(KeyEnum_t key, Logger logger, PageEntity_t *page)
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
        return Page_CreatePage(Spc_GetNextPage(logger, key, DeadBand), logger, page->publisher);
    case Up:
    case Down:
        Page_Update_DeadBand(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_DeadBand(logger, page);
        return NULL;
    case Reset:
        Page_Reset_DeadBand(logger, page);
        return NULL;
    case Flash:
        Page_Flash_DeadBand(logger, page);
        return NULL;
    case Restore:
        Page_Restore_DeadBand(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

