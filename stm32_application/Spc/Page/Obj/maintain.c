#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxMaint(bool unit) {
  return unit ? 932 : 500;
}

static inline int16_t FetchMinMaint(bool unit) {
  return unit ? -58 : -50;
}

static void SpcData_CorrectMaintain(SpcTempGroupConfig_t *tempgroup)
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

void MaintainStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcTempGroupConfig_t *tempgroup = (SpcTempGroupConfig_t *) page->data;
    if (tempgroup->maintain.status == OFF) {
        strncpy((char *)(page->info.Content), "Off", MAX_INFO_LEN);
    } else if (tempgroup->maintain.status == NONE) {
        strncpy((char *)(page->info.Content), "None", MAX_INFO_LEN);
    } else {
        uint8_t content[MAX_INFO_LEN] = {0};
        const uint8_t unit = SpcData_GetTempUint();
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", tempgroup->maintain.temperature[unit],
            unit ? "F" : "C");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    }
}

static void Page_Update_Maintain(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcTempGroupConfig_t *tempgroup = (SpcTempGroupConfig_t *) page->data;
    const uint8_t unit = SpcData_GetTempUint();

    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);

    if (key == Up) {
        if (tempgroup->maintain.status == OFF) {
            return;
        } else if (tempgroup->maintain.status == NONE) {
            tempgroup->maintain.status = OFF;
        } else if (tempgroup->maintain.temperature[unit] == FetchMaxMaint(unit)) {
            tempgroup->maintain.status = NONE;
        } else if (tempgroup->maintain.temperature[unit] < FetchMaxMaint(unit)) {
            tempgroup->maintain.temperature[unit]++;
        } else {
            logger("\r\nexit\r\n");
            return;
        }
    } else if (key == Down) {
        if (tempgroup->maintain.status == OFF) {
            tempgroup->maintain.status = NONE;
        } else if (tempgroup->maintain.status == NONE) {
            tempgroup->maintain.status = Opt;
            tempgroup->maintain.temperature[unit] = FetchMaxMaint(unit);
        } else if (tempgroup->maintain.temperature[unit] > FetchMinMaint(unit)) {
            tempgroup->maintain.temperature[unit]--;
        } else {
            return;
        }
    }
    MaintainStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_Maintain(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;


    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_CorrectMaintain(page->data);
    SpcData_SetTempGroup(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_Maintain(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcTempGroupConfig_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetTempGroup(page->data);
    MaintainStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_Maintain(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        MaintainStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_Maintain(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    MaintainStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_Maintain(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Maintain Temp", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcTempGroupConfig_t *) malloc(sizeof(SpcTempGroupConfig_t));
    memset(page->data, 0, sizeof(SpcTempGroupConfig_t));
    if (SpcData_GetTempGroup(page->data)) {
        MaintainStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Main", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Maintain(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(LowTemp, logger, page->publisher);
    case Left:
        return Page_CreatePage(Program, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_Maintain(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_Maintain(logger, page);
        return NULL;
    case Reset:
        Page_Reset_Maintain(logger, page);
        return NULL;
    case Flash:
        Page_Flash_Maintain(logger, page);
        return NULL;
    case Restore:
        Page_Restore_Maintain(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

