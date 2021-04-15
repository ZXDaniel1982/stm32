/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DATA_H
#define __DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define NUM_ROWS(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))

#define MAX_INFO_LEN (16)

#define HEATER_STATUS_POS (0)
#define HEATER_STATUS_MSK (0x3)
#define HEATER_STATUS_HAS_POS (2)
#define HEATER_STATUS_HAS_MSK (0x1) 

/* For Default display */
typedef enum {
  SysStatus = 0,
  HeatStatus,
  HeatTemp
} LcdDef_Enum_t;

/* For Heater status */
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

/* For temperature */
typedef struct {
    uint8_t hasValue;
    int16_t temperature[2];
} SpcTemp_t;

/* Global values */
typedef struct {
    union {
        struct {
            uint64_t lcdDef : 2;
            uint64_t tempUint : 1;
            uint64_t reserve : 61;
        } bits;
        uint64_t SpcMaskRom;
    };
} SpcDataRom_t;

typedef struct {
    union {
        struct {
            uint64_t heatStatus : 2;
            uint64_t hasHeatStatus : 1;
            uint64_t reserve : 61;
        } bits;
        uint64_t SpcMaskRam;
    };
    SpcTemp_t SpcTemp;
    SpcTemp_t SpcTempChan1;
    SpcTemp_t SpcTempChan2;
} SpcDataRam_t;

/* From data.c */
void SpcDataInit(void);
uint8_t SpcData_GetLcdDef(void);
uint8_t SpcData_GetTempUint(void);
uint64_t SpcData_GetMaskRam(void);
bool SpcData_GetTemperature(SpcTemp_t *temp);

#ifdef __cplusplus
}
#endif

#endif /* __DATA_H */
