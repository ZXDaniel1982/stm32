#include "spc.h"
#include "data.h"

#define HEATER_STATUS_POS (0)
#define HEATER_STATUS_MSK (0x3)
#define HEATER_STATUS_HAS_POS (2)
#define HEATER_STATUS_HAS_MSK (0x1) 

typedef enum {
  SysStatus = 0,
  HeatStatus,
  HeatTemp
} LcdDef_Enum_t;

typedef enum {
  HeatIsOff = 0,
  HeatIsOn,
  HeatIsManOff,
  HeatIsManOn
} HeatStatus_Enum_t;

typedef struct {
  HeatStatus_Enum_t type;
  uint8_t info[MAX_INFO_LEN];
} HeatStatus_t;

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

void Page_Init_Default(Logger logger, PageEntity_t *page)
{
	//logger("\r\nDefault\r\n");
  if ((page == NULL) || (page->publisher == NULL)) return;

  uint8_t lcdDef = SpcData_GetLcdDef();
  switch (lcdDef) {
  case SysStatus:
    strncpy((char *)(page->info.Title), "Sytem Status", MAX_INFO_LEN);
    strncpy((char *)(page->info.Content), "Unsupported", MAX_INFO_LEN);
    break;
  case HeatStatus:
    {
      uint64_t mask = SpcData_GetMaskRam();
      uint8_t hasHeatStatus = (uint8_t) ((mask >> HEATER_STATUS_HAS_POS) & HEATER_STATUS_HAS_MSK);
      uint8_t heatStatus = (uint8_t) ((mask >> HEATER_STATUS_POS) & HEATER_STATUS_MSK);

      strncpy((char *)(page->info.Title), "Heater Status", MAX_INFO_LEN);

      if (hasHeatStatus) {
        const char * info = (const char *)Def_GetHeatStatus(heatStatus);
        if (NULL != info)
          strncpy((char *)(page->info.Content), info, MAX_INFO_LEN);
      }
    }
    break;
  case HeatTemp:
    {
      strncpy((char *)(page->info.Title), "Heater Temp", MAX_INFO_LEN);

      SpcTemp_t temperature;
      if (SpcData_GetTemperature(&temperature)) {
        if (temperature.hasValue) {
          uint8_t content[MAX_INFO_LEN] = {0};
          const uint8_t unit = SpcData_GetTempUint();
          snprintf((char *)content, MAX_INFO_LEN, "%d %s", temperature.temperature[unit],
            unit ? "F" : "C");
          strncpy((char *)(page->info.Content), (char *)content, MAX_INFO_LEN);
        } else {
          strncpy((char *)(page->info.Content), "No Value", MAX_INFO_LEN);
        }
      } else {
        strncpy((char *)(page->info.Content), "Cant read temp", MAX_INFO_LEN);
      }
    }
    break;
  default:
    strncpy((char *)(page->info.Title), "Default Error", MAX_INFO_LEN);
    strncpy((char *)(page->info.Content), "Unsupported Def", MAX_INFO_LEN);
    break;
  }
  page->publisher(&(page->info));
}

PageEntity_t *Page_Func_Default(KeyEnum_t key, Logger logger, PageEntity_t *page)
{
	switch (key) {
	case Prog:
		return Page_CreatePage(Program, logger, page->publisher);
	case Act:
		return Page_CreatePage(Actual, logger, page->publisher);
	default:
		return NULL;
	}
}
