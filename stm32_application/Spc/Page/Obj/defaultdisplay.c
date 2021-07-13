#include "spc.h"
#include "spctimer.h"

#define DEFAULT_DISPLAY_POS (0)
#define DEFAULT_DISPLAY_MSK (0x3U)
#define DEFAULT_DISPLAY_POS_MSK (DEFAULT_DISPLAY_MSK << DEFAULT_DISPLAY_POS)

static const ByteStatus_t DefaultDisplayMap[] = {
    {SysStatus,             "System Status"},
    {HeatStatus,            "Heater Status"},
    {HeatTemp,              "Heater Temp"}
};

static const uint8_t *Def_DefaultDisplay(uint8_t mode)
{
    for (uint8_t i = 0; i < NUM_ROWS(DefaultDisplayMap); ++i) {
        if (mode == DefaultDisplayMap[i].type) {
           return DefaultDisplayMap[i].info;
        }
    }
    return NULL;
}

void DefaultDisplayStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    uint64_t *mask = (uint64_t *) page->data;
    uint8_t defaultdisplay = (uint8_t) (((*mask) >> DEFAULT_DISPLAY_POS) & DEFAULT_DISPLAY_MSK);
    strncpy((char *)(page->info.Content), (char *)Def_DefaultDisplay(defaultdisplay), MAX_INFO_LEN);
}

static void Page_Update_DefaultDisplay(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    uint64_t *mask = (uint64_t *) page->data;
    uint8_t defaultdisplay = (uint8_t) (((*mask) >> DEFAULT_DISPLAY_POS) & DEFAULT_DISPLAY_MSK);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (defaultdisplay >= HeatTemp) {
            return;
        } else {
            defaultdisplay++;
            MODIFY_MASK(*mask, DEFAULT_DISPLAY_POS_MSK, defaultdisplay << DEFAULT_DISPLAY_POS);
        }
    } else if (key == Down) {
        if (defaultdisplay <= SysStatus) {
            return;
        } else {
            defaultdisplay--;
            MODIFY_MASK(*mask, DEFAULT_DISPLAY_POS_MSK, defaultdisplay << DEFAULT_DISPLAY_POS);
        }
    }
    DefaultDisplayStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_DefaultDisplay(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetMaskRom(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_DefaultDisplay(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(uint64_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetMaskRom(page->data);
    DefaultDisplayStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_DefaultDisplay(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        DefaultDisplayStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_DefaultDisplay(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    DefaultDisplayStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_DefaultDisplay(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Default Display", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (uint64_t *) malloc(sizeof(uint64_t));
    memset(page->data, 0, sizeof(uint64_t));
    if (SpcData_GetMaskRom(page->data)) {
        DefaultDisplayStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read DD", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_DefaultDisplay(KeyEnum_t key, Logger logger, PageEntity_t *page)
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
        return Page_CreatePage(Spc_GetNextPage(logger, key, DefaultDisplay), logger, page->publisher);
    case Up:
    case Down:
        Page_Update_DefaultDisplay(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_DefaultDisplay(logger, page);
        return NULL;
    case Reset:
        Page_Reset_DefaultDisplay(logger, page);
        return NULL;
    case Flash:
        Page_Flash_DefaultDisplay(logger, page);
        return NULL;
    case Restore:
        Page_Restore_DefaultDisplay(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

