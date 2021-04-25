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

#define DISABLE_REFRESH (0)

/* Operational mask */
#define HEATER_STATUS_POS (0)
#define HEATER_STATUS_MSK (0x3)
#define HEATER_STATUS_HAS_POS (2)
#define HEATER_STATUS_HAS_MSK (0x1) 

/* Page refresh mask */
#define Refresh_Heatst_Pos (0)
#define Refresh_Heatst_Msk (1 << Refresh_Heatst_Pos)

#define Refresh_Temperature_Pos (1)
#define Refresh_Temperature_Msk (1 << Refresh_Temperature_Pos)

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
typedef enum {
  Normal = 0,
  RTD_OPEN,
  RTD_SHORT
} SpcTempStatus_Enum_t;

typedef struct {
    SpcTempStatus_Enum_t status;
    uint8_t hasValue;
    int16_t temperature[2];
} SpcTemp_t;

typedef struct {
    uint8_t hasValue;
    uint16_t value;
} SpcUint16_t;

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
        } SpcMaskBits;
        uint64_t SpcMaskRam;
    };
    union {
        struct {
            uint64_t heatStatus : 1;
            uint64_t temperature : 1;
            uint64_t tempRTDA : 1;
            uint64_t tempRTDB : 1;
            uint64_t voltage : 1;
            uint64_t current : 1;
            uint64_t reserve : 58;
        } SpcRefreshBits;
        uint64_t SpcRefreshMask;
    };
    SpcTemp_t SpcTemp;
    SpcTemp_t SpcTempRTDA;
    SpcTemp_t SpcTempRTDB;
    SpcUint16_t SpcVoltage;
    SpcUint16_t SpcCurrent;
} SpcDataRam_t;

/* From data.c */
void SpcDataInit(void);
uint8_t SpcData_GetLcdDef(void);
uint8_t SpcData_GetTempUint(void);
uint64_t SpcData_GetMaskRam(void);
void SpcData_SetRefreshMask(uint64_t val);
uint64_t SpcData_GetRefreshMask(void);
bool SpcData_GetTemperature(SpcTemp_t *temp);
void SpcData_SetTemperature(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB);
bool SpcData_GetTempRTDA(SpcTemp_t *temp);
void SpcData_SetTempRTDA(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB);
bool SpcData_GetTempRTDB(SpcTemp_t *temp);
void SpcData_SetTempRTDB(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB);
void SpcData_SetVoltage(uint16_t voltage);
bool SpcData_GetVoltage(SpcUint16_t *voltage);
void SpcData_SetCurrent(uint16_t current);
bool SpcData_GetCurrent(SpcUint16_t *current);

#ifdef __cplusplus
}
#endif

#endif /* __DATA_H */
