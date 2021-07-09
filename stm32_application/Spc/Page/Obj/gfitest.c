#include "spc.h"
#include "spctimer.h"

#define GFI_TEST_POS (16)
#define GFI_TEST_MSK (0x3U)
#define GFI_TEST_POS_MSK (GFI_TEST_MSK << GFI_TEST_POS)

static const ByteStatus_t GfiTestMap[] = {
    {GfiTest_Auto,             "Autotest Cycle"},
    {GfiTest_Now,              "Now"},
    {GfiTest_Disable,          "Disable"}
};

static const uint8_t *Def_GfiTest(uint8_t mode)
{
    for (uint8_t i = 0; i < NUM_ROWS(GfiTestMap); ++i) {
        if (mode == GfiTestMap[i].type) {
           return GfiTestMap[i].info;
        }
    }
    return NULL;
}

void GfiTestStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    uint64_t *mask = (uint64_t *) page->data;
    uint8_t gfitest = (uint8_t) (((*mask) >> GFI_TEST_POS) & GFI_TEST_MSK);
    strncpy((char *)(page->info.Content), (char *)Def_GfiTest(gfitest), MAX_INFO_LEN);
}

static void Page_Update_GfiTest(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    uint64_t *mask = (uint64_t *) page->data;
    uint8_t gfitest = (uint8_t) (((*mask) >> GFI_TEST_POS) & GFI_TEST_MSK);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (gfitest >= GfiTest_Disable) {
            return;
        } else {
            gfitest++;
            MODIFY_MASK(*mask, GFI_TEST_POS_MSK, gfitest << GFI_TEST_POS);
        }
    } else if (key == Down) {
        if (gfitest <= GfiTest_Auto) {
            return;
        } else {
            gfitest--;
            MODIFY_MASK(*mask, GFI_TEST_POS_MSK, gfitest << GFI_TEST_POS);
        }
    }
    GfiTestStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_GfiTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetMaskRom(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_GfiTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(uint64_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetMaskRom(page->data);
    GfiTestStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_GfiTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        GfiTestStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_GfiTest(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    GfiTestStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_GfiTest(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "GFI Test", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (uint64_t *) malloc(sizeof(uint64_t));
    memset(page->data, 0, sizeof(uint64_t));
    if (SpcData_GetMaskRom(page->data)) {
        GfiTestStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read GT", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_GfiTest(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    /*case Right:
        return Page_CreatePage(ResetModule, logger, page->publisher);*/
    case Left:
        return Page_CreatePage(HeaterTest, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_GfiTest(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_GfiTest(logger, page);
        return NULL;
    case Reset:
        Page_Reset_GfiTest(logger, page);
        return NULL;
    case Flash:
        Page_Flash_GfiTest(logger, page);
        return NULL;
    case Restore:
        Page_Restore_GfiTest(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

