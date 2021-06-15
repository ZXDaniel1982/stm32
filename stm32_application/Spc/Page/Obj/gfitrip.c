#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxGFITrip() {
    return 500;
}

static inline int16_t FetchMinGFITrip(SpcGfiGroupConfig_t *gfigroup) {
    SpcUint16Config_t *gfialarm = &(gfigroup->gfialarm);
    if (gfialarm->status == Uint16OFF) {
        return 15;
    } else {
        return gfialarm->value;
    }
}

static void SpcData_CorrectGFITrip(SpcGfiGroupConfig_t *gfigroup)
{
    if (gfigroup == NULL) return;

    SpcUint16Config_t *gfialarm = &(gfigroup->gfialarm);
    SpcUint16Config_t *gfitrip = &(gfigroup->gfitrip);

    if ((gfialarm->status == Uint16Opt) &&
        (gfitrip->status == Uint16Opt)) {
        if (gfialarm->value >= gfitrip->value) {
            gfialarm->value = gfitrip->value - 1;
        }
    }
}

void GFITripStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcGfiGroupConfig_t *gfigroup = (SpcGfiGroupConfig_t *) page->data;
    SpcUint16Config_t *gfitrip = &(gfigroup->gfitrip);
    
    if (gfitrip->status == Uint16OFF) {
        strncpy((char *)(page->info.Content), "Off", MAX_INFO_LEN);
    } else {
        uint8_t content[MAX_INFO_LEN] = {0};
        snprintf((char *)content, MAX_INFO_LEN, "%d %s", gfitrip->value, "mA");
        strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    }
}

static void Page_Update_GFITrip(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcGfiGroupConfig_t *gfigroup = (SpcGfiGroupConfig_t *) page->data;
    SpcUint16Config_t *gfitrip = &(gfigroup->gfitrip);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (gfitrip->status == Uint16OFF) {
            return;
        } else if (gfitrip->value == FetchMaxGFITrip()) {
            gfitrip->status = Uint16OFF;
        } else if (gfitrip->value < FetchMaxGFITrip()) {
            gfitrip->value++;
        } else {
            logger("\r\nexit\r\n");
            return;
        }
    } else if (key == Down) {
        if (gfitrip->status == Uint16OFF) {
            gfitrip->status = Uint16Opt;
            gfitrip->value = FetchMaxGFITrip();
        } else if (gfitrip->value > FetchMinGFITrip(gfigroup)) {
            gfitrip->value--;
        } else {
            return;
        }
    }
    GFITripStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_GFITrip(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcGfiGroupConfig_t *gfigroup = (SpcGfiGroupConfig_t *) page->data;
    
    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_CorrectGFITrip(gfigroup);
    SpcData_SetGfiGroup(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_GFITrip(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcGfiGroupConfig_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetGfiGroup(page->data);
    GFITripStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_GFITrip(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        GFITripStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_GFITrip(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    GFITripStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_GFITrip(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "GFI Trip", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcGfiGroupConfig_t *) malloc(sizeof(SpcGfiGroupConfig_t));
    memset(page->data, 0, sizeof(SpcGfiGroupConfig_t));
    if (SpcData_GetGfiGroup(page->data)) {
        GFITripStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read High", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_GFITrip(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(LowVoltage, logger, page->publisher);
    case Left:
        return Page_CreatePage(GFIAlarm, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_GFITrip(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_GFITrip(logger, page);
        return NULL;
    case Reset:
        Page_Reset_GFITrip(logger, page);
        return NULL;
    case Flash:
        Page_Flash_GFITrip(logger, page);
        return NULL;
    case Restore:
        Page_Restore_GFITrip(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

