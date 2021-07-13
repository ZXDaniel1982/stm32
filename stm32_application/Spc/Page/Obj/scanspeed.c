#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxScanSpeed() {
    return 10;
}

static inline uint16_t FetchMinScanSpeed() {
    return 3;
}

void ScanSpeedStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcUint16Config_t *scanspeed = (SpcUint16Config_t *) page->data;
    
    uint8_t content[MAX_INFO_LEN] = {0};
    snprintf((char *)content, MAX_INFO_LEN, "%d %s", scanspeed->value, "seconds");
    strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
}

static void Page_Update_ScanSpeed(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcUint16Config_t *scanspeed = (SpcUint16Config_t *) page->data;

    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);

    if (key == Up) {
        if (scanspeed->value < FetchMaxScanSpeed()) {
            scanspeed->value++;
        } else {
            return;
        }
    } else if (key == Down) {
        if (scanspeed->value > FetchMinScanSpeed()) {
            scanspeed->value--;
        } else {
            return;
        }
    }
    ScanSpeedStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_ScanSpeed(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetScanSpeed(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_ScanSpeed(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcUint16Config_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetScanSpeed(page->data);
    ScanSpeedStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_ScanSpeed(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        ScanSpeedStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_ScanSpeed(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    ScanSpeedStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_ScanSpeed(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Scan Speed", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcUint16Config_t *) malloc(sizeof(SpcUint16Config_t));
    memset(page->data, 0, sizeof(SpcUint16Config_t));
    if (SpcData_GetScanSpeed(page->data)) {
        ScanSpeedStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read SSp", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_ScanSpeed(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        if (!MenuIsNotAdvance())
            return Page_CreatePage(SystemTest, logger, page->publisher);
        else
            return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
    case Left:
        return Page_CreatePage(Spc_GetNextPage(logger, key, ScanSpeed), logger, page->publisher);
    case Up:
    case Down:
        Page_Update_ScanSpeed(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_ScanSpeed(logger, page);
        return NULL;
    case Reset:
        Page_Reset_ScanSpeed(logger, page);
        return NULL;
    case Flash:
        Page_Flash_ScanSpeed(logger, page);
        return NULL;
    case Restore:
        Page_Restore_ScanSpeed(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

