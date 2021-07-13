#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxHeaterTest() {
    return 24;
}

static inline uint16_t FetchMinHeaterTest() {
    return 1;
}

void HeaterTestStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcUint16Config_t *heatertest = (SpcUint16Config_t *) page->data;
    
    uint8_t content[MAX_INFO_LEN] = {0};
    snprintf((char *)content, MAX_INFO_LEN, "%d %s", heatertest->value, "hours");
    strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
}

static void Page_Update_HeaterTest(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcUint16Config_t *heatertest = (SpcUint16Config_t *) page->data;

    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);

    if (key == Up) {
        if (heatertest->value < FetchMaxHeaterTest()) {
            heatertest->value++;
        } else {
            return;
        }
    } else if (key == Down) {
        if (heatertest->value > FetchMinHeaterTest()) {
            heatertest->value--;
        } else {
            return;
        }
    }
    HeaterTestStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_HeaterTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetHeaterTest(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_HeaterTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcUint16Config_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetHeaterTest(page->data);
    HeaterTestStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_HeaterTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        HeaterTestStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_HeaterTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    HeaterTestStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_HeaterTest(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Heater Test", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcUint16Config_t *) malloc(sizeof(SpcUint16Config_t));
    memset(page->data, 0, sizeof(SpcUint16Config_t));
    if (SpcData_GetHeaterTest(page->data)) {
        HeaterTestStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Ht", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_HeaterTest(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
    case Left:
        return Page_CreatePage(Spc_GetNextPage(logger, key, HeaterTest), logger, page->publisher);
    case Up:
    case Down:
        Page_Update_HeaterTest(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_HeaterTest(logger, page);
        return NULL;
    case Reset:
        Page_Reset_HeaterTest(logger, page);
        return NULL;
    case Flash:
        Page_Flash_HeaterTest(logger, page);
        return NULL;
    case Restore:
        Page_Restore_HeaterTest(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

