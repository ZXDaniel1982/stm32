#include "spc.h"
#include "spctimer.h"

#define RTD_FAIL_MODE_POS (10)
#define RTD_FAIL_MODE_MSK (0x1U)
#define RTD_FAIL_MODE_POS_MSK (RTD_FAIL_MODE_MSK << RTD_FAIL_MODE_POS)

void RtdFailModeStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    uint64_t *mask = (uint64_t *) page->data;
    uint8_t rtdfailmode = (uint8_t) (((*mask) >> RTD_FAIL_MODE_POS) & RTD_FAIL_MODE_MSK);

    if (rtdfailmode) {
        strncpy((char *)(page->info.Content), "Off", MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "On", MAX_INFO_LEN);
    }
}

static void Page_Update_RtdFailMode(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    uint64_t *mask = (uint64_t *) page->data;
    uint8_t rtdfailmode = (uint8_t) (((*mask) >> RTD_FAIL_MODE_POS) & RTD_FAIL_MODE_MSK);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (rtdfailmode) {
            return;
        } else {
            rtdfailmode = 1;
            MODIFY_MASK(*mask, RTD_FAIL_MODE_POS_MSK, rtdfailmode << RTD_FAIL_MODE_POS);
        }
    } else if (key == Down) {
        if (rtdfailmode) {
            rtdfailmode = 0;
            MODIFY_MASK(*mask, RTD_FAIL_MODE_POS_MSK, rtdfailmode << RTD_FAIL_MODE_POS);
        } else {
            return;
        }
    }
    RtdFailModeStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_RtdFailMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetMaskRom(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_RtdFailMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(uint64_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetMaskRom(page->data);
    RtdFailModeStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_RtdFailMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        RtdFailModeStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_RtdFailMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    RtdFailModeStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_RtdFailMode(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "RTD Failure Mode", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (uint64_t *) malloc(sizeof(uint64_t));
    memset(page->data, 0, sizeof(uint64_t));
    if (SpcData_GetMaskRom(page->data)) {
        RtdFailModeStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Fai", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_RtdFailMode(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(SystemSetup, logger, page->publisher);
    case Left:
        return Page_CreatePage(RtdOptMode, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_RtdFailMode(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_RtdFailMode(logger, page);
        return NULL;
    case Reset:
        Page_Reset_RtdFailMode(logger, page);
        return NULL;
    case Flash:
        Page_Flash_RtdFailMode(logger, page);
        return NULL;
    case Restore:
        Page_Restore_RtdFailMode(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

