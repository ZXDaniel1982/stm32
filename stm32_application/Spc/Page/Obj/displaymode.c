#include "spc.h"
#include "spctimer.h"

#define DISPLAY_MODE_POS (12)
#define DISPLAY_MODE_MSK (0x1U)
#define DISPLAY_MODE_POS_MSK (DISPLAY_MODE_MSK << DISPLAY_MODE_POS)

void DisplayModeStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    uint64_t *mask = (uint64_t *) page->data;
    uint8_t displaymode = (uint8_t) (((*mask) >> DISPLAY_MODE_POS) & DISPLAY_MODE_MSK);

    if (displaymode) {
        strncpy((char *)(page->info.Content), "Advanced", MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "Normal", MAX_INFO_LEN);
    }
}

static void Page_Update_DisplayMode(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    uint64_t *mask = (uint64_t *) page->data;
    uint8_t displaymode = (uint8_t) (((*mask) >> DISPLAY_MODE_POS) & DISPLAY_MODE_MSK);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (displaymode) {
            return;
        } else {
            displaymode = 1;
            MODIFY_MASK(*mask, DISPLAY_MODE_POS_MSK, displaymode << DISPLAY_MODE_POS);
        }
    } else if (key == Down) {
        if (displaymode) {
            displaymode = 0;
            MODIFY_MASK(*mask, DISPLAY_MODE_POS_MSK, displaymode << DISPLAY_MODE_POS);
        } else {
            return;
        }
    }
    DisplayModeStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_DisplayMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetMaskRom(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_DisplayMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(uint64_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetMaskRom(page->data);
    DisplayModeStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_DisplayMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        DisplayModeStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_DisplayMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    DisplayModeStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_DisplayMode(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Display Mode", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (uint64_t *) malloc(sizeof(uint64_t));
    memset(page->data, 0, sizeof(uint64_t));
    if (SpcData_GetMaskRom(page->data)) {
        DisplayModeStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read DM", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_DisplayMode(KeyEnum_t key, Logger logger, PageEntity_t *page)
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
        return Page_CreatePage(Spc_GetNextPage(logger, key, DisplayMode), logger, page->publisher);
    case Up:
    case Down:
        Page_Update_DisplayMode(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_DisplayMode(logger, page);
        return NULL;
    case Reset:
        Page_Reset_DisplayMode(logger, page);
        return NULL;
    case Flash:
        Page_Flash_DisplayMode(logger, page);
        return NULL;
    case Restore:
        Page_Restore_DisplayMode(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

