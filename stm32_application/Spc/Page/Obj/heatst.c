#include "spc.h"

static const HeatStatus_t HeatStatusMap[] = {
  {HeatIsOff,     "Heater is Off"},
  {HeatIsOn,      "Heater is On"},
  {HeatIsManOff,  "Heater is ManOff"},
  {HeatIsManOn,   "Heater is ManOn"}
};

static const uint8_t *Def_GetHeatStatus(uint8_t status)
{
  for (uint8_t i = 0; i < NUM_ROWS(HeatStatusMap); ++i) {
    if (status == HeatStatusMap[i].type) {
      return HeatStatusMap[i].info;
    }
  }
  return NULL;
}

void HeatStProcess(PageEntity_t *page)
{
  uint64_t mask = SpcData_GetMaskRam();
  uint8_t hasHeatStatus = (uint8_t) ((mask >> HEATER_STATUS_HAS_POS) & HEATER_STATUS_HAS_MSK);
  uint8_t heatStatus = (uint8_t) ((mask >> HEATER_STATUS_POS) & HEATER_STATUS_MSK);

  strncpy((char *)(page->info.Title), "Heater Status", MAX_INFO_LEN);

  if (hasHeatStatus) {
    const char * info = (const char *)Def_GetHeatStatus(heatStatus);
    if (NULL != info)
      strncpy((char *)(page->info.Content), info, MAX_INFO_LEN);
    else
      strncpy((char *)(page->info.Content), "Unsupported", MAX_INFO_LEN);
  } else {
    strncpy((char *)(page->info.Content), "No Heat St", MAX_INFO_LEN);
  }
}

void Page_Init_HeatSt(Logger logger, PageEntity_t *page)
{
    //logger("\r\nActual\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  SpcData_SetRefreshMask(Refresh_Heatst_Msk);
  HeatStProcess(page);
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_HeatSt(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
    switch (key) {
    case Act:
    case Left:
        return Page_CreatePage(Actual, logger, page->publisher);
    case Prog:
        return Page_CreatePage(Program, logger, page->publisher);
    case Def:
        return Page_CreatePage(Default, logger, page->publisher);
    case Right:
        return Page_CreatePage(Temperature, logger, page->publisher);
    case Update:
        Page_Init_HeatSt(logger, page);
        return NULL;
    default:
        return NULL;
    }
}

