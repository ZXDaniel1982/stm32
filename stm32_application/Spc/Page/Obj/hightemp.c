#include "spc.h"
#include "spctimer.h"

static inline int16_t FetchMaxMaint(bool unit) {
  return unit ? 932 : 500;
}

static inline int16_t FetchMinMaint(bool unit) {
  return unit ? -58 : -50;
}

void HighTempStoreProcess(PageEntity_t *page)
{
  if ((page == NULL) || (page->data == NULL)) return;

  SpcTempConfig_t *hightemp = (SpcTempConfig_t *) page->data;
  if (hightemp->status == OFF) {
      strncpy((char *)(page->info.Content), "Off", MAX_INFO_LEN);
  } else if (hightemp->status == NONE) {
      strncpy((char *)(page->info.Content), "None", MAX_INFO_LEN);
  } else {
      uint8_t content[MAX_INFO_LEN] = {0};
      const uint8_t unit = SpcData_GetTempUint();
      snprintf((char *)content, MAX_INFO_LEN, "%d %s", hightemp->temperature[unit],
        unit ? "F" : "C");
      strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
  }
}

static void Page_Update_HighTemp(Logger logger, PageEntity_t *page, KeyEnum_t key)
{
  SpcTempConfig_t *hightemp = (SpcTempConfig_t *) page->data;
  const uint8_t unit = SpcData_GetTempUint();

  SpcTimer_StopTimer(Restore);
  SpcTimer_StartTimer(Flash, 40, true);
  
  if (key == Up) {
    if (hightemp->status == OFF) {
      return;
    } else if (hightemp->status == NONE) {
      hightemp->status = OFF;
    } else if (hightemp->temperature[unit] == FetchMaxMaint(unit)) {
      hightemp->status = NONE;
    } else if (hightemp->temperature[unit] < FetchMaxMaint(unit)) {
      hightemp->temperature[unit]++;
    } else {
      logger("\r\nexit\r\n");
      return;
    }
  } else if (key == Down) {
    if (hightemp->status == OFF) {
      hightemp->status = NONE;
    } else if (hightemp->status == NONE) {
      hightemp->status = Opt;
      hightemp->temperature[unit] = FetchMaxMaint(unit);
    } else if (hightemp->temperature[unit] > FetchMinMaint(unit)) {
      hightemp->temperature[unit]--;
    } else {
      return;
    }
  }
  HighTempStoreProcess(page);
  page->publisher(&(page->info));
}

static void Page_Config_HighTemp(Logger logger, PageEntity_t *page)
{
  if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

  
  SpcTimer_StopTimer(Flash);
  SpcTimer_StartTimer(Restore, 40, false);

  SpcData_SetHighTemp(page->data);
  strncpy((char *)(page->info.Content), "Stored", MAX_INFO_LEN);
  page->publisher(&(page->info));
}

static void Page_Reset_HighTemp(Logger logger, PageEntity_t *page)
{
  if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;
  
  memset(page->data, 0, sizeof(SpcTempConfig_t));

  SpcTimer_StopTimer(Flash);
  SpcTimer_StopTimer(Restore);

  SpcData_GetHighTemp(page->data);
  HighTempStoreProcess(page);
  page->publisher(&(page->info));
}

static void Page_Flash_HighTemp(Logger logger, PageEntity_t *page)
{
  if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

  static bool flash = false;

  if (flash) {
    memset(page->info.Content, 0, MAX_INFO_LEN);
  } else {
    HighTempStoreProcess(page);
  }

  flash = !flash;
  page->publisher(&(page->info));
}

static void Page_Restore_HighTemp(Logger logger, PageEntity_t *page)
{
  if ((page == NULL) || (page->publisher == NULL) || (page->data == NULL)) return;

  SpcTimer_StopTimer(Flash);
  SpcTimer_StopTimer(Restore);
  
  HighTempStoreProcess(page);
  page->publisher(&(page->info));
}

void Page_Init_HighTemp(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(DISABLE_REFRESH);
  strncpy((char *)(page->info.Title), "High Temp Alarm", MAX_INFO_LEN);

  if (page->data != NULL) free(page->data);
  page->data = (SpcTempConfig_t *) malloc(sizeof(SpcTempConfig_t));
  memset(page->data, 0, sizeof(SpcTempConfig_t));
  if (SpcData_GetHighTemp(page->data)) {
    HighTempStoreProcess(page);
  } else {
    strncpy((char *)(page->info.Content), "Cant read High", MAX_INFO_LEN);
  }
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_HighTemp(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    /*case Right:
        return Page_CreatePage(TempRTDA, logger, page->publisher);*/
    case Left:
        return Page_CreatePage(LowTemp, logger, page->publisher);
    case Up:
    case Down:
        Page_Update_HighTemp(logger, page, key);
        return NULL;
    case Enter:
        Page_Config_HighTemp(logger, page);
        return NULL;
    case Reset:
        Page_Reset_HighTemp(logger, page);
        return NULL;
    case Flash:
        Page_Flash_HighTemp(logger, page);
        return NULL;
    case Restore:
        Page_Restore_HighTemp(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

