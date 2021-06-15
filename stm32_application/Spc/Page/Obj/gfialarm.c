#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxGFIAlarm(SpcGfiGroupConfig_t* gfigroup) {
    SpcUint16Config_t *gfitrip = &(gfigroup->gfitrip);
    if (gfitrip->status == Uint16OFF) {
        return 495;
    } else {
        return gfitrip->value;
    }
}

static inline uint16_t FetchMinGFIAlarm() {
    return 10;
}

static void SpcData_CorrectGFIAlarm(SpcGfiGroupConfig_t *gfigroup)
{
    if (gfigroup == NULL) return;

    SpcUint16Config_t *gfialarm = &(gfigroup->gfialarm);
    SpcUint16Config_t *gfitrip = &(gfigroup->gfitrip);

    if ((gfialarm->status == Uint16Opt) &&
        (gfitrip->status == Uint16Opt)) {
        if (gfialarm->value >= gfitrip->value) {
            gfitrip->value = gfialarm->value + 1;
        }
    }
}

void GFIAlarmStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcGfiGroupConfig_t *gfigroup = (SpcGfiGroupConfig_t *) page->data;
    SpcUint16Config_t *gfialarm = &(gfigroup->gfialarm);
    
    if (gfialarm->status == Uint16OFF) {
        strncpy((char *)(page->info.Content), "Off", MAX_INFO_LEN);
    } else {
        uint8_t content[MAX_INFO_LEN] = {0};
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", gfialarm->value, "mA");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    }
}

static void Page_Update_GFIAlarm(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcGfiGroupConfig_t *gfigroup = (SpcGfiGroupConfig_t *) page->data;
    SpcUint16Config_t *gfialarm = &(gfigroup->gfialarm);

    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);

    if (key == Up) {
        if (gfialarm->status == Uint16OFF) {
            return;
        } else if (gfialarm->value == FetchMaxGFIAlarm(gfigroup)) {
            gfialarm->status = Uint16OFF;
        } else if (gfialarm->value < FetchMaxGFIAlarm(gfigroup)) {
            gfialarm->value++;
        } else {
            logger("\r\nexit\r\n");
            return;
        }
    } else if (key == Down) {
        if (gfialarm->status == Uint16OFF) {
            gfialarm->status = Uint16Opt;
            gfialarm->value = FetchMaxGFIAlarm(gfigroup);
        } else if (gfialarm->value > FetchMinGFIAlarm()) {
            gfialarm->value--;
        } else {
            logger("\r\nexit\r\n");
            return;
        }
    }
    GFIAlarmStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_GFIAlarm(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcGfiGroupConfig_t *gfigroup = (SpcGfiGroupConfig_t *) page->data;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_CorrectGFIAlarm(gfigroup);
    SpcData_SetGfiGroup(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_GFIAlarm(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcGfiGroupConfig_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetGfiGroup(page->data);
    GFIAlarmStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_GFIAlarm(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        GFIAlarmStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_GFIAlarm(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    GFIAlarmStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_GFIAlarm(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "GFI Alarm", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcGfiGroupConfig_t *) malloc(sizeof(SpcGfiGroupConfig_t));
    memset(page->data, 0, sizeof(SpcGfiGroupConfig_t));
    if (SpcData_GetGfiGroup(page->data)) {
        GFIAlarmStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Low", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_GFIAlarm(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(GFITrip, logger, page->publisher);
    case Left:
        return Page_CreatePage(HighCurrent, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_GFIAlarm(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_GFIAlarm(logger, page);
        return NULL;
    case Reset:
        Page_Reset_GFIAlarm(logger, page);
        return NULL;
    case Flash:
        Page_Flash_GFIAlarm(logger, page);
        return NULL;
    case Restore:
        Page_Restore_GFIAlarm(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

