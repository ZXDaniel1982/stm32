#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxHighTemp(bool unit) {
    return unit ? 932 : 500;
}

static inline int16_t FetchMinHighTemp(SpcTempGroupConfig_t *tempgroup, bool unit) {
    SpcTempConfig_t *maintain = &(tempgroup->maintain);
    SpcTempConfig_t *lowtemp = &(tempgroup->lowtemp);
    SpcTempConfig_t *deadband = &(tempgroup->deadband);
    if (maintain->status == Opt) {
        if (SpcData_GetCtrlType()) {
            return (maintain->temperature[unit] + 1);
        } else {
            return (maintain->temperature[unit] + deadband->temperature[unit] + 1);
        }
    } else if (lowtemp->status == OFF) {
        return unit ? -57 : -49;
    } else {
        return (lowtemp->temperature[unit] + 1);
    }
}

static void SpcData_CorrectHighTemp(SpcTempGroupConfig_t *tempgroup)
{
    if (tempgroup == NULL) return;

    const uint8_t unit = SpcData_GetTempUint();
    SpcTempConfig_t *lowtemp = &(tempgroup->lowtemp);
    SpcTempConfig_t *hightemp = &(tempgroup->hightemp);

    if ((lowtemp->status == Opt) &&
        (hightemp->status == Opt)) {
        if (lowtemp->temperature[unit] >= hightemp->temperature[unit]) {
            lowtemp->temperature[unit] = hightemp->temperature[unit] - 1;
        }
    }
}

void HighTempStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcTempGroupConfig_t *tempgroup = (SpcTempGroupConfig_t *) page->data;
    SpcTempConfig_t *maintain = &(tempgroup->maintain);
    SpcTempConfig_t *hightemp = &(tempgroup->hightemp);
    
    if (maintain->status == OFF) {
        strncpy((char *)(page->info.Content), "--", MAX_INFO_LEN);
        return;
    }
    
    if (hightemp->status == OFF) {
        strncpy((char *)(page->info.Content), "Off", MAX_INFO_LEN);
    } else {
        uint8_t content[MAX_INFO_LEN] = {0};
        const uint8_t unit = SpcData_GetTempUint();
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", hightemp->temperature[unit],
            unit ? "F" : "C");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    }
}

static void Page_Update_HighTemp(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcTempGroupConfig_t *tempgroup = (SpcTempGroupConfig_t *) page->data;
    SpcTempConfig_t *maintain = &(tempgroup->maintain);
    SpcTempConfig_t *hightemp = &(tempgroup->hightemp);
    const uint8_t unit = SpcData_GetTempUint();

    if (maintain->status == OFF) return;
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (hightemp->status == OFF) {
            return;
        } else if (hightemp->temperature[unit] == FetchMaxHighTemp(unit)) {
            hightemp->status = OFF;
        } else if (hightemp->temperature[unit] < FetchMaxHighTemp(unit)) {
            hightemp->temperature[unit]++;
        } else {
            logger("\r\nexit\r\n");
            return;
        }
    } else if (key == Down) {
        if (hightemp->status == OFF) {
            hightemp->status = Opt;
            hightemp->temperature[unit] = FetchMaxHighTemp(unit);
        } else if (hightemp->temperature[unit] > FetchMinHighTemp(tempgroup, unit)) {
            hightemp->temperature[unit]--;
        } else {
            return;
        }
    }
    HighTempStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_HighTemp(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTempGroupConfig_t *tempgroup = (SpcTempGroupConfig_t *) page->data;
    if (tempgroup->maintain.status == OFF) return;
    
    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_CorrectHighTemp(tempgroup);
    SpcData_SetTempGroup(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_HighTemp(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTempGroupConfig_t *tempgroup = (SpcTempGroupConfig_t *) page->data;
    if (tempgroup->maintain.status == OFF) return;
    
    memset(page->data, 0, sizeof(SpcTempGroupConfig_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetTempGroup(page->data);
    HighTempStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_HighTemp(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTempGroupConfig_t *tempgroup = (SpcTempGroupConfig_t *) page->data;
    if (tempgroup->maintain.status == OFF) return;
    
    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        HighTempStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_HighTemp(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTempGroupConfig_t *tempgroup = (SpcTempGroupConfig_t *) page->data;
    if (tempgroup->maintain.status == OFF) return;
    
    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    HighTempStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_HighTemp(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "High Temp Alarm", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcTempGroupConfig_t *) malloc(sizeof(SpcTempGroupConfig_t));
    memset(page->data, 0, sizeof(SpcTempGroupConfig_t));
    if (SpcData_GetTempGroup(page->data)) {
        HighTempStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read High", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_HighTemp(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(LowCurrent, logger, page->publisher);
    case Left:
        return Page_CreatePage(LowTemp, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_HighTemp(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_HighTemp(logger, page);
        return NULL;
    case Reset:
        Page_Reset_HighTemp(logger, page);
        return NULL;
    case Flash:
        Page_Flash_HighTemp(logger, page);
        return NULL;
    case Restore:
        Page_Restore_HighTemp(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

