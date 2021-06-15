#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxHighVoltage() {
    return 280;
}

static inline int16_t FetchMinHighVoltage(SpcVoltageGroupConfig_t *voltagegroup) {
    SpcUint16Config_t *lowvoltage = &(voltagegroup->lowvoltage);
    if (lowvoltage->status == Uint16OFF) {
        return 95;
    } else {
        return lowvoltage->value;
    }
}

static void SpcData_CorrectHighVoltage(SpcVoltageGroupConfig_t *voltagegroup)
{
    if (voltagegroup == NULL) return;

    SpcUint16Config_t *lowvoltage = &(voltagegroup->lowvoltage);
    SpcUint16Config_t *highvoltage = &(voltagegroup->highvoltage);

    if ((lowvoltage->status == Uint16Opt) &&
        (highvoltage->status == Uint16Opt)) {
        if (lowvoltage->value >= highvoltage->value) {
            lowvoltage->value = highvoltage->value - 1;
        }
    }
}

void HighVoltageStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcVoltageGroupConfig_t *voltagegroup = (SpcVoltageGroupConfig_t *) page->data;
    SpcUint16Config_t *highvoltage = &(voltagegroup->highvoltage);
    
    if (highvoltage->status == Uint16OFF) {
        strncpy((char *)(page->info.Content), "Off", MAX_INFO_LEN);
    } else {
        uint8_t content[MAX_INFO_LEN] = {0};
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", highvoltage->value, "V");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    }
}

static void Page_Update_HighVoltage(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcVoltageGroupConfig_t *voltagegroup = (SpcVoltageGroupConfig_t *) page->data;
    SpcUint16Config_t *highvoltage = &(voltagegroup->highvoltage);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (highvoltage->status == Uint16OFF) {
            return;
        } else if (highvoltage->value == FetchMaxHighVoltage()) {
            highvoltage->status = Uint16OFF;
        } else if (highvoltage->value < FetchMaxHighVoltage()) {
            highvoltage->value++;
        } else {
            logger("\r\nexit\r\n");
            return;
        }
    } else if (key == Down) {
        if (highvoltage->status == Uint16OFF) {
            highvoltage->status = Uint16Opt;
            highvoltage->value = FetchMaxHighVoltage();
        } else if (highvoltage->value > FetchMinHighVoltage(voltagegroup)) {
            highvoltage->value--;
        } else {
            return;
        }
    }
    HighVoltageStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_HighVoltage(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcVoltageGroupConfig_t *voltagegroup = (SpcVoltageGroupConfig_t *) page->data;
    
    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_CorrectHighVoltage(voltagegroup);
    SpcData_SetVoltageGroup(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_HighVoltage(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcVoltageGroupConfig_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetVoltageGroup(page->data);
    HighVoltageStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_HighVoltage(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        HighVoltageStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_HighVoltage(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    HighVoltageStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_HighVoltage(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "High Volt Alm", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcVoltageGroupConfig_t *) malloc(sizeof(SpcVoltageGroupConfig_t));
    memset(page->data, 0, sizeof(SpcVoltageGroupConfig_t));
    if (SpcData_GetVoltageGroup(page->data)) {
        HighVoltageStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read High", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_HighVoltage(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    /*case Right:
        return Page_CreatePage(VoltageRTDA, logger, page->publisher);*/
    case Left:
        return Page_CreatePage(LowVoltage, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_HighVoltage(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_HighVoltage(logger, page);
        return NULL;
    case Reset:
        Page_Reset_HighVoltage(logger, page);
        return NULL;
    case Flash:
        Page_Flash_HighVoltage(logger, page);
        return NULL;
    case Restore:
        Page_Restore_HighVoltage(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

