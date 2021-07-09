#include "spc.h"
#include "spctimer.h"

#define MAX_HEATERNAME_LEN (15)

static const uint8_t kMapCharactor[] = {
    ' ',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

static uint8_t HeaterNameGetCharactor(uint8_t charator)
{
    for (uint8_t i=0;i<NUM_ROWS(kMapCharactor);i++) {
        if (charator == kMapCharactor[i]) {
            return i;
        }
    }
    return 0;
}

void HeaterNameStoreProcess(PageEntity_t *page)
{
    if ((page == NULL) || (page->data == NULL)) return;
    SpcStringConfig_t *heatername = (SpcStringConfig_t *) (page->data);
    strncpy((char *)(page->info.Content), (char *)(heatername->value), MAX_INFO_LEN);
}

static void Page_Update_HeaterName(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
    SpcStringConfig_t *heatername = (SpcStringConfig_t *) (page->data);
    uint8_t index = heatername->index;
    
    SpcTimer_StopTimer(Restore);
    SpcTimer_StartTimer(Flash, 40, true);
  
    if (key == Up) {
        if (heatername->value[index] == '\0') {
            heatername->value[index] = ' ';
        } else {
            uint8_t charator = HeaterNameGetCharactor(heatername->value[index]);
            uint8_t charatorNum = NUM_ROWS(kMapCharactor);
            charator = (charator + charatorNum + 1) % charatorNum;
            if ((index == 0) && (charator == 0)) charator++;
            heatername->value[index] = kMapCharactor[charator];
        }
    } else if (key == Down) {
        if (heatername->value[index] == '\0') {
            heatername->value[index] = ' ';
        } else {
            uint8_t charator = HeaterNameGetCharactor(heatername->value[index]);
            uint8_t charatorNum = NUM_ROWS(kMapCharactor);
            charator = (charator + charatorNum - 1) % charatorNum;
            if ((index == 0) && (charator == 0)) charator = charatorNum - 1;
            heatername->value[index] = kMapCharactor[charator];
        }
    }
    HeaterNameStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Config_HeaterName(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcStringConfig_t *heatername = (SpcStringConfig_t *) (page->data);
    if (heatername->index == MAX_HEATERNAME_LEN) {
        SpcTimer_StopTimer(Flash);
        SpcTimer_StartTimer(Restore, 40, false);

        SpcData_SetHeaterName(heatername->value);
        strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
    } else {
        heatername->index++;
        if (heatername->value[heatername->index] == '\0')
            heatername->value[heatername->index] = ' ';
    }
    page->publisher(&(page->info));
}

static void Page_Reset_HeaterName(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    memset(page->data, 0, sizeof(SpcStringConfig_t));

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    SpcStringConfig_t *heatername = (SpcStringConfig_t *) (page->data);
    SpcData_GetHeaterName(heatername->value);
    HeaterNameStoreProcess(page);
    page->publisher(&(page->info));
}

static void Page_Flash_HeaterName(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcStringConfig_t *heatername = (SpcStringConfig_t *) (page->data);
    static bool flash = false;
    if (flash) {
        uint8_t index = heatername->index;
        strncpy((char *)(page->info.Content), (char *)(heatername->value), MAX_INFO_LEN);
        page->info.Content[index] = '-';
    } else {
        HeaterNameStoreProcess(page);
    }

    flash = !flash;
    page->publisher(&(page->info));
}

static void Page_Restore_HeaterName(Logger logger, PageEntity_t *page)
{
    if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

    SpcTimer_StopTimer(Flash);
    SpcTimer_StopTimer(Restore);

    HeaterNameStoreProcess(page);
    page->publisher(&(page->info));
}

void Page_Init_HeaterName(Logger logger, PageEntity_t *page)
{
    //logger("\r\nHeaterName\r\n");
    if ((page == NULL) || (page->publisher == NULL)) return;

    SpcData_SetRefreshMask(DISABLE_REFRESH);
    strncpy((char *)(page->info.Title), "Heater ID", MAX_INFO_LEN);

    if (page->data != NULL) free(page->data);
    page->data = (SpcStringConfig_t *) malloc(sizeof(SpcStringConfig_t));
    memset(page->data, 0, sizeof(SpcStringConfig_t));
    SpcStringConfig_t *heatername = (SpcStringConfig_t *) (page->data);
    if (SpcData_GetHeaterName(heatername->value)) {
        if (heatername->value[0] == '\0' || heatername->value[0] == ' ') {
            heatername->value[0] = '0';
        }
        HeaterNameStoreProcess(page);
    } else {
        strncpy((char *)(page->info.Content), "Cant read name", MAX_INFO_LEN);
    }
    page->publisher(&(page->info));
}

PageEntity_t *Page_Func_HeaterName(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(HeaterType, logger, page->publisher);
    case Left:
        return Page_CreatePage(HeaterEn, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_HeaterName(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_HeaterName(logger, page);
        return NULL;
    case Reset:
        Page_Reset_HeaterName(logger, page);
        return NULL;
    case Flash:
        Page_Flash_HeaterName(logger, page);
        return NULL;
    case Restore:
        Page_Restore_HeaterName(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

