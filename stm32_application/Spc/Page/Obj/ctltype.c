#include "spc.h"
#include "spctimer.h"

#define CONTROL_TYPE_POS (3)
#define CONTROL_TYPE_MSK (0x1U)
#define CONTROL_TYPE_POS_MSK (CONTROL_TYPE_MSK << CONTROL_TYPE_POS)

void ControlTypeStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;

    uint64_t *mask = (uint64_t *) page->data;
    uint8_t ctltype = (uint8_t) (((*mask) >> CONTROL_TYPE_POS) & CONTROL_TYPE_MSK);

    if (ctltype) {
        strncpy((char *)(page->info.Content), "Proportional", MAX_INFO_LEN);
    } else {
        strncpy((char *)(page->info.Content), "On_off", MAX_INFO_LEN);
    }
}

static void Page_Update_ControlType(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    uint64_t *mask = (uint64_t *) page->data;
    uint8_t ctltype = (uint8_t) (((*mask) >> CONTROL_TYPE_POS) & CONTROL_TYPE_MSK);
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (ctltype) {
            return;
        } else {
            ctltype = 1;
            MODIFY_MASK(*mask, CONTROL_TYPE_POS_MSK, ctltype << CONTROL_TYPE_POS);
        }
    } else if (key == Down) {
        if (ctltype) {
            ctltype = 0;
            MODIFY_MASK(*mask, CONTROL_TYPE_POS_MSK, ctltype << CONTROL_TYPE_POS);
        } else {
            return;
        }
    }
    ControlTypeStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_ControlType(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StartTimer(Restore, 40, false);

    SpcData_SetMaskRom(page->data);
    strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    page->publisher(&(page->info));
}

static void Page_Reset_ControlType(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(uint64_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcData_GetMaskRom(page->data);
    ControlTypeStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_ControlType(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    static bool flash = false;

    if (flash) {
        memset(page->info.Content, 0, MAX_INFO_LEN);
    } else {
        ControlTypeStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_ControlType(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    ControlTypeStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_ControlType(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Control Type", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (uint64_t *) malloc(sizeof(uint64_t));
    memset(page->data, 0, sizeof(uint64_t));
    if (SpcData_GetMaskRom(page->data)) {
        ControlTypeStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read Type", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_ControlType(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    /*case Right:
        return Page_CreatePage(ManualOverride, logger, page->publisher);*/
    case Left:
        return Page_CreatePage(DeadBand, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_ControlType(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_ControlType(logger, page);
        return NULL;
    case Reset:
        Page_Reset_ControlType(logger, page);
        return NULL;
    case Flash:
        Page_Flash_ControlType(logger, page);
        return NULL;
    case Restore:
        Page_Restore_ControlType(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

