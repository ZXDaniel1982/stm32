#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxAutoTest() {
    return 720;
}

static inline uint16_t FetchMinAutoTest() {
    return 1;
}

void AutoTestStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcUint16Config_t *autotest = (SpcUint16Config_t *) page->data;
    
    uint8_t content[MAX_INFO_LEN] = {0};
    snprintf((char *)content, MAX_INFO_LEN, "%d %s", autotest->value, "%");
    strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
}

static void Page_Update_AutoTest(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcUint16Config_t *autotest = (SpcUint16Config_t *) page->data;

    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);

    if (key == Up) {
        if (autotest->value < FetchMaxAutoTest()) {
            autotest->value++;
        } else {
            return;
        }
    } else if (key == Down) {
        if (autotest->value > FetchMinAutoTest()) {
            autotest->value--;
        } else {
            return;
        }
    }
    AutoTestStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_AutoTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetAutoTest(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_AutoTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcUint16Config_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetAutoTest(page->data);
    AutoTestStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_AutoTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        AutoTestStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_AutoTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    AutoTestStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_AutoTest(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Auto Test Cycle", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcUint16Config_t *) malloc(sizeof(SpcUint16Config_t));
    memset(page->data, 0, sizeof(SpcUint16Config_t));
    if (SpcData_GetAutoTest(page->data)) {
        AutoTestStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read ATC", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_AutoTest(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(RtdOptMode, logger, page->publisher);
    case Left:
        return Page_CreatePage(SoftStart, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_AutoTest(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_AutoTest(logger, page);
        return NULL;
    case Reset:
        Page_Reset_AutoTest(logger, page);
        return NULL;
    case Flash:
        Page_Flash_AutoTest(logger, page);
        return NULL;
    case Restore:
        Page_Restore_AutoTest(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

