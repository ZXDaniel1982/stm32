#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxPowerPrice() {
    return 100;
}

static inline uint16_t FetchMinPowerPrice() {
    return 1;
}

void PowerPriceStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    SpcUint16Config_t *powerprice = (SpcUint16Config_t *) page->data;
    
    uint8_t content[MAX_INFO_LEN] = {0};
    snprintf((char *)content, MAX_INFO_LEN, "%d %s", powerprice->value, "$");
    strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
}

static void Page_Update_PowerPrice(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcUint16Config_t *powerprice = (SpcUint16Config_t *) page->data;

    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);

    if (key == Up) {
        if (powerprice->value < FetchMaxPowerPrice()) {
            powerprice->value++;
        } else {
            return;
        }
    } else if (key == Down) {
        if (powerprice->value > FetchMinPowerPrice()) {
            powerprice->value--;
        } else {
            return;
        }
    }
    PowerPriceStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_PowerPrice(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetPowerPrice(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_PowerPrice(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcUint16Config_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetPowerPrice(page->data);
    PowerPriceStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_PowerPrice(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        PowerPriceStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_PowerPrice(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    PowerPriceStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_PowerPrice(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Operational PowerPrice", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcUint16Config_t *) malloc(sizeof(SpcUint16Config_t));
    memset(page->data, 0, sizeof(SpcUint16Config_t));
    if (SpcData_GetPowerPrice(page->data)) {
        PowerPriceStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Cst", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_PowerPrice(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(DisplayMode, logger, page->publisher);
    case Left:
        return Page_CreatePage(TempUnits, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_PowerPrice(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_PowerPrice(logger, page);
        return NULL;
    case Reset:
        Page_Reset_PowerPrice(logger, page);
        return NULL;
    case Flash:
        Page_Flash_PowerPrice(logger, page);
        return NULL;
    case Restore:
        Page_Restore_PowerPrice(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

