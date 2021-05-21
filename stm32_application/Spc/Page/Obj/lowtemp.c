#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxMaint(bool unit) {
  return unit ? 932 : 500;
}

static inline int16_t FetchMinMaint(bool unit) {
  return unit ? -58 : -50;
}

void LowTempStoreProcess(PageEntity_t *page)
{
  if ((page == NULL) || (page->data == NULL)) return;

  SpcTempConfig_t *lowtemp = (SpcTempConfig_t *) page->data;
  if (lowtemp->status == OFF) {
      strncpy((char *)(page->info.Content), "Off", MAX_INFO_LEN);
  } else if (lowtemp->status == NONE) {
      strncpy((char *)(page->info.Content), "None", MAX_INFO_LEN);
  } else {
      uint8_t content[MAX_INFO_LEN] = {0};
      const uint8_t unit = SpcData_GetTempUint();
      snprintf((char *)content, MAX_INFO_LEN, "%d %s", lowtemp->temperature[unit],
        unit ? "F" : "C");
      strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
  }
}

static void Page_Update_LowTemp(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
  SpcTempConfig_t *lowtemp = (SpcTempConfig_t *) page->data;
  const uint8_t unit = SpcData_GetTempUint();

  SpcTimer_StopTimer(Restore);
  SpcTimer_StartTimer(Flash, 40, true);
  
  if (key == Up) {
    if (lowtemp->status == OFF) {
      return;
    } else if (lowtemp->status == NONE) {
      lowtemp->status = OFF;
    } else if (lowtemp->temperature[unit] == FetchMaxMaint(unit)) {
      lowtemp->status = NONE;
    } else if (lowtemp->temperature[unit] < FetchMaxMaint(unit)) {
      lowtemp->temperature[unit]++;
    } else {
      logger("\r\nexit\r\n");
      return;
    }
  } else if (key == Down) {
    if (lowtemp->status == OFF) {
      lowtemp->status = NONE;
    } else if (lowtemp->status == NONE) {
      lowtemp->status = Opt;
      lowtemp->temperature[unit] = FetchMaxMaint(unit);
    } else if (lowtemp->temperature[unit] > FetchMinMaint(unit)) {
      lowtemp->temperature[unit]--;
    } else {
      return;
    }
  }
  LowTempStoreProcess(page);
  page->publisher(&(page->info));
}

static void Page_Config_LowTemp(Logger logger, PageEntity_t *page)
{
  if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

  
  SpcTimer_StopTimer(Flash);
  SpcTimer_StartTimer(Restore, 40, false);

  SpcData_SetLowTemp(page->data);
  strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
  page->publisher(&(page->info));
}

static void Page_Reset_LowTemp(Logger logger, PageEntity_t *page)
{
  if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;
  
  memset(page->data, 0, sizeof(SpcTempConfig_t));

  SpcTimer_StopTimer(Flash);
  SpcTimer_StopTimer(Restore);

  SpcData_GetLowTemp(page->data);
  LowTempStoreProcess(page);
  page->publisher(&(page->info));
}

static void Page_Flash_LowTemp(Logger logger, PageEntity_t *page)
{
  if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

  static bool flash = false;

  if (flash) {
    memset(page->info.Content, 0, MAX_INFO_LEN);
  } else {
    LowTempStoreProcess(page);
  }

  flash = !flash;
  page->publisher(&(page->info));
}

static void Page_Restore_LowTemp(Logger logger, PageEntity_t *page)
{
  if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

  SpcTimer_StopTimer(Flash);
  SpcTimer_StopTimer(Restore);
  
  LowTempStoreProcess(page);
  page->publisher(&(page->info));
}

void Page_Init_LowTemp(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(DISABLE_REFRESH);
  strncpy((char *)(page->info.Title), "Low Temp Alarm", MAX_INFO_LEN);

  if (page->data != NULL) free(page->data);
  page->data = (SpcTempConfig_t *) malloc(sizeof(SpcTempConfig_t));
  memset(page->data, 0, sizeof(SpcTempConfig_t));
  if (SpcData_GetLowTemp(page->data)) {
    LowTempStoreProcess(page);
  } else {
    strncpy((char *)(page->info.Content), "Cant read Low", MAX_INFO_LEN);
  }
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_LowTemp(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(HighTemp, logger, page->publisher);
    case Left:
        return Page_CreatePage(Maintain, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_LowTemp(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_LowTemp(logger, page);
        return NULL;
    case Reset:
        Page_Reset_LowTemp(logger, page);
        return NULL;
    case Flash:
        Page_Flash_LowTemp(logger, page);
        return NULL;
    case Restore:
        Page_Restore_LowTemp(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

