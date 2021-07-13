#include "spc.h"
#include "spctimer.h"

#define RTD_OPT_MODE_POS (7)
#define RTD_OPT_MODE_MSK (0x7U)
#define RTD_OPT_MODE_POS_MSK (RTD_OPT_MODE_MSK << RTD_OPT_MODE_POS)

static const ByteStatus_t RtdOptModeMap[] = {
    {OneRtdMode,            "One RTD Mode"},
    {BackupMode,            "Backup Mode"},
    {AverageMode,           "Average Mode"},
    {LowestMode,            "Lowest Mode"},
    {HighestMode,           "Highest Mode"},
    {HighTempCutOffMode,    "High Temp Cutoff"}
};

static const uint8_t *Def_RtdOptMode(uint8_t mode)
{
    for (uint8_t i = 0; i < NUM_ROWS(RtdOptModeMap); ++i) {
        if (mode == RtdOptModeMap[i].type) {
           return RtdOptModeMap[i].info;
        }
    }
    return NULL;
}

void RtdOptModeStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    uint64_t *mask = (uint64_t *) page->data;
    uint8_t rtdoptmode = (uint8_t) (((*mask) >> RTD_OPT_MODE_POS) & RTD_OPT_MODE_MSK);
    strncpy((char *)(page->info.Content), (char *)Def_RtdOptMode(rtdoptmode), MAX_INFO_LEN);
}

static void Page_Update_RtdOptMode(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    uint64_t *mask = (uint64_t *) page->data;
    uint8_t rtdoptmode = (uint8_t) (((*mask) >> RTD_OPT_MODE_POS) & RTD_OPT_MODE_MSK);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (rtdoptmode >= HighTempCutOffMode) {
            return;
        } else {
            rtdoptmode++;
            MODIFY_MASK(*mask, RTD_OPT_MODE_POS_MSK, rtdoptmode << RTD_OPT_MODE_POS);
        }
    } else if (key == Down) {
        if (rtdoptmode <= OneRtdMode) {
            return;
        } else {
            rtdoptmode--;
            MODIFY_MASK(*mask, RTD_OPT_MODE_POS_MSK, rtdoptmode << RTD_OPT_MODE_POS);
        }
    }
    RtdOptModeStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_RtdOptMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetMaskRom(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_RtdOptMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(uint64_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetMaskRom(page->data);
    RtdOptModeStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_RtdOptMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        RtdOptModeStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_RtdOptMode(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    RtdOptModeStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_RtdOptMode(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "RTD Operation", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (uint64_t *) malloc(sizeof(uint64_t));
    memset(page->data, 0, sizeof(uint64_t));
    if (SpcData_GetMaskRom(page->data)) {
        RtdOptModeStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Opt", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_RtdOptMode(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(SystemSetup, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
    case Left:
        return Page_CreatePage(Spc_GetNextPage(logger, key, RtdOptMode), logger, page->publisher);
    case Up:
    case Down:
        Page_Update_RtdOptMode(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_RtdOptMode(logger, page);
        return NULL;
    case Reset:
        Page_Reset_RtdOptMode(logger, page);
        return NULL;
    case Flash:
        Page_Flash_RtdOptMode(logger, page);
        return NULL;
    case Restore:
        Page_Restore_RtdOptMode(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

