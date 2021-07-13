#include "spc.h"
#include "spctimer.h"

#define BAUDRATE_POS (13)
#define BAUDRATE_MSK (0x7U)
#define BAUDRATE_POS_MSK (BAUDRATE_MSK << BAUDRATE_POS)

static const ByteStatus_t BaudrateMap[] = {
    {Baudrate1200,              "1200"},
    {Baudrate2400,              "2400"},
    {Baudrate4800,              "4800"},
    {Baudrate9600,              "9600"},
    {Baudrate19200,             "19200"},
    {Baudrate115200,            "115200"}
};

static const uint8_t *Def_Baudrate(uint8_t mode)
{
    for (uint8_t i = 0; i < NUM_ROWS(BaudrateMap); ++i) {
        if (mode == BaudrateMap[i].type) {
           return BaudrateMap[i].info;
        }
    }
    return NULL;
}

void BaudrateStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    uint64_t *mask = (uint64_t *) page->data;
    uint8_t baudrate = (uint8_t) (((*mask) >> BAUDRATE_POS) & BAUDRATE_MSK);
    strncpy((char *)(page->info.Content), (char *)Def_Baudrate(baudrate), MAX_INFO_LEN);
}

static void Page_Update_Baudrate(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    uint64_t *mask = (uint64_t *) page->data;
    uint8_t baudrate = (uint8_t) (((*mask) >> BAUDRATE_POS) & BAUDRATE_MSK);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (baudrate >= HighTempCutOffMode) {
            return;
        } else {
            baudrate++;
            MODIFY_MASK(*mask, BAUDRATE_POS_MSK, baudrate << BAUDRATE_POS);
        }
    } else if (key == Down) {
        if (baudrate <= OneRtdMode) {
            return;
        } else {
            baudrate--;
            MODIFY_MASK(*mask, BAUDRATE_POS_MSK, baudrate << BAUDRATE_POS);
        }
    }
    BaudrateStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_Baudrate(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetMaskRom(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_Baudrate(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(uint64_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetMaskRom(page->data);
    BaudrateStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_Baudrate(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        BaudrateStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_Baudrate(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    BaudrateStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_Baudrate(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Baud Rate", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (uint64_t *) malloc(sizeof(uint64_t));
    memset(page->data, 0, sizeof(uint64_t));
    if (SpcData_GetMaskRom(page->data)) {
        BaudrateStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read BR", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Baudrate(KeyEnum_t key, Logger logger, PageEntity_t *page)
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
        return Page_CreatePage(Spc_GetNextPage(logger, key, Baudrate), logger, page->publisher);
    case Up:
    case Down:
        Page_Update_Baudrate(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_Baudrate(logger, page);
        return NULL;
    case Reset:
        Page_Reset_Baudrate(logger, page);
        return NULL;
    case Flash:
        Page_Flash_Baudrate(logger, page);
        return NULL;
    case Restore:
        Page_Restore_Baudrate(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

