#include "spc.h"

#define Refresh_TempRTDA_Pos (2)
#define Refresh_TempRTDA_Msk (1 << Refresh_TempRTDA_Pos)
#define Refresh_TempRTDB_Pos (3)
#define Refresh_TempRTDB_Msk (1 << Refresh_TempRTDB_Pos)

void TemperatureProcess(PageEntity_t *page, SpcTemp_t *temperature)
{
  if (temperature->hasValue) {
    if (temperature->status == RTD_OPEN) {
      strncpy((char *)(page->info.Content), "RTD_OPNE", MAX_INFO_LEN);
    } else if (temperature->status == RTD_SHORT) {
      strncpy((char *)(page->info.Content), "RTD_SHORT", MAX_INFO_LEN);
    } else {
      uint8_t content[MAX_INFO_LEN] = {0};
      const uint8_t unit = SpcData_GetTempUint();
      snprintf((char *)content, MAX_INFO_LEN, "%d %s", temperature->temperature[unit],
        unit ? "F" : "C");
      strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
    }
  } else {
    strncpy((char *)(page->info.Content), "No Value", MAX_INFO_LEN);
  }
}

void Page_Init_Temperature(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(Refresh_Temperature_Msk);
  strncpy((char *)(page->info.Title), "Temperature", MAX_INFO_LEN);

  SpcTemp_t temperature;
  if (SpcData_GetTemperature(&temperature)) {
    TemperatureProcess(page, &temperature);
  } else {
    strncpy((char *)(page->info.Content), "Cant read temp", MAX_INFO_LEN);
  }
  page->publisher(&(page->info));
}

void Page_Init_TempRTDA(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(Refresh_TempRTDA_Msk);
  strncpy((char *)(page->info.Title), "RTD-A Actual", MAX_INFO_LEN);

  SpcTemp_t temperature;
  if (SpcData_GetTempRTDA(&temperature)) {
    TemperatureProcess(page, &temperature);
  } else {
    strncpy((char *)(page->info.Content), "Cant read temp", MAX_INFO_LEN);
  }
  page->publisher(&(page->info));
}

void Page_Init_TempRTDB(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(Refresh_TempRTDB_Msk);
  strncpy((char *)(page->info.Title), "RTD-B Actual", MAX_INFO_LEN);

  SpcTemp_t temperature;
  if (SpcData_GetTempRTDB(&temperature)) {
    TemperatureProcess(page, &temperature);
  } else {
    strncpy((char *)(page->info.Content), "Cant read temp", MAX_INFO_LEN);
  }
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Temperature(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(TempRTDA, logger, page->publisher);
    case Left:
        return Page_CreatePage(HeatSt, logger, page->publisher);
    case Update:
        Page_Init_Temperature(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

PageEntity_t *Page_Func_TempRTDA(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(TempRTDB, logger, page->publisher);
    case Left:
        return Page_CreatePage(Temperature, logger, page->publisher);
    case Update:
        Page_Init_TempRTDA(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

PageEntity_t *Page_Func_TempRTDB(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Left:
        return Page_CreatePage(TempRTDA, logger, page->publisher);
    case Right:
        return Page_CreatePage(Power, logger, page->publisher);
    case Update:
        Page_Init_TempRTDB(logger, page);
        return NULL;
    default:
        return NULL;
    }
}
