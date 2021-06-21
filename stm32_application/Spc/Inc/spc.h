#ifndef __SPC_H
#define __SPC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "key.h"
#include "data.h"

typedef int (*Logger)(const char* fmt, ...);

#define PAGE_INDEX(PAGE_OPT, type) \
    PAGE_OPT(Default, type) \
    PAGE_OPT(Actual, type) \
    PAGE_OPT(HeatSt, type) \
    PAGE_OPT(Temperature, type) \
    PAGE_OPT(TempRTDA, type) \
    PAGE_OPT(TempRTDB, type) \
    PAGE_OPT(Power, type) \
    PAGE_OPT(Current, type) \
    PAGE_OPT(Gfi, type) \
    PAGE_OPT(Voltage, type) \
    PAGE_OPT(Statistic, type) \
    PAGE_OPT(MaxTemperature, type) \
    PAGE_OPT(MinTemperature, type) \
    PAGE_OPT(MaxCurrent, type) \
    PAGE_OPT(MaxGfi, type) \
    PAGE_OPT(MaxVoltage, type) \
    PAGE_OPT(MinVoltage, type) \
    PAGE_OPT(Enegy, type) \
    PAGE_OPT(Cost, type) \
    PAGE_OPT(OnTime, type) \
    PAGE_OPT(OnPercent, type) \
    PAGE_OPT(ResetStatistic, type) \
    PAGE_OPT(Version, type) \
    PAGE_OPT(Program, type) \
    PAGE_OPT(Maintain, type) \
    PAGE_OPT(LowTemp, type) \
    PAGE_OPT(HighTemp, type) \
    PAGE_OPT(LowCurrent, type) \
    PAGE_OPT(HighCurrent, type) \
    PAGE_OPT(GFIAlarm, type) \
    PAGE_OPT(GFITrip, type) \
    PAGE_OPT(LowVoltage, type) \
    PAGE_OPT(HighVoltage, type) \
    PAGE_OPT(HeaterSetup, type) \
    PAGE_OPT(HeaterEn, type) \
    PAGE_OPT(HeaterName, type) \
    PAGE_OPT(HeaterType, type) \
    PAGE_OPT(ManualOverride, type) \
    PAGE_OPT(DeadBand, type) \
    PAGE_OPT(ControlType, type)

#define OBJ_ENUM(TYPE, type) TYPE,
#define PAGE_INIT_DECLARE(TYPE, type) void Page_Init_##TYPE(Logger, PageEntity_t *);
#define PAGE_FUNC_DECLARE(TYPE, type) PageEntity_t *Page_Func_##TYPE(KeyEnum_t, Logger, PageEntity_t *);
#define PAGE_INIT(TYPE, type) { \
    if (TYPE == type) { \
        return Page_Init_##TYPE; \
    } \
}
#define PAGE_FUNC(TYPE, type) { \
    if (TYPE == type) { \
        return Page_Func_##TYPE; \
    } \
}

#define MAX_INFO_LEN (17)
typedef struct {
    uint8_t Title[MAX_INFO_LEN];
    uint8_t Content[MAX_INFO_LEN];
} PageInfo_t;

typedef void (*Publisher)(PageInfo_t *);

typedef enum PageEnum {
    PAGE_INDEX(OBJ_ENUM, NULL)
} PageEnum_t;

typedef struct PageEntity {
    PageEnum_t type;
    PageInfo_t info;
    void *data;
    Publisher publisher;
    struct PageEntity *(*func) (KeyEnum_t, Logger, struct PageEntity *);
} PageEntity_t;

typedef void (*PageInit) (Logger, PageEntity_t *);
typedef PageEntity_t *(*PageFunc) (KeyEnum_t, Logger, PageEntity_t *);

PAGE_INDEX(PAGE_INIT_DECLARE, NULL)
PAGE_INDEX(PAGE_FUNC_DECLARE, NULL)

static inline PageInit GetPageInit(PageEnum_t type) {
    PAGE_INDEX(PAGE_INIT, type)
    return NULL;
} 
static inline PageFunc GetPageFunc(PageEnum_t type) {
    PAGE_INDEX(PAGE_FUNC, type)
    return NULL;
}

PageEntity_t *Page_CreatePage(PageEnum_t, Logger, Publisher);

/* From page heater status*/
void HeatStProcess(PageEntity_t *page);

/* From page temperature*/
void TemperatureProcess(PageEntity_t *page, SpcTemp_t *temperature);

/* From Page current */
void CurrentProcess(PageEntity_t *page, SpcUint16_t *current);

/* From Page Gfi */
void GfiProcess(PageEntity_t *page, SpcUint16_t *gfi);

/* From Page Voltage */
void VoltageProcess(PageEntity_t *page, SpcUint16_t *voltage);

#ifdef __cplusplus
}
#endif

#endif                          /* __SPC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
