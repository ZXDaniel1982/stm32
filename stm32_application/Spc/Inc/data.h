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

/* For temperature config */
typedef enum {
  Uint16Opt = 0,
  Uint16OFF
} SpcUint16Config_Enum_t;

typedef enum {
  Opt = 0,
  OFF,
  NONE
} SpcTempConfig_Enum_t;

/* Data type in Ram */
typedef struct {
    SpcTempStatus_Enum_t status;
    uint8_t hasValue;
    int16_t temperature[2];
} SpcTemp_t;

typedef struct {
    uint8_t hasValue;
    uint16_t value;
} SpcUint16_t;

/* Data type in Rom */
typedef struct {
    SpcUint16Config_Enum_t status;
    uint16_t value;
} SpcUint16Config_t;

typedef struct {
    SpcUint16Config_t lowcurrent;
    SpcUint16Config_t highcurrent;
} SpcCurrentGroupConfig_t;

typedef struct {
    SpcUint16Config_t gfialarm;
    SpcUint16Config_t gfitrip;
} SpcGfiGroupConfig_t;

typedef struct {
    SpcUint16Config_t lowvoltage;
    SpcUint16Config_t highvoltage;
} SpcVoltageGroupConfig_t;

typedef struct {
    SpcTempConfig_Enum_t status;
    int16_t temperature[2];
} SpcTempConfig_t;

typedef struct {
    SpcTempConfig_t maintain;
    SpcTempConfig_t lowtemp;
    SpcTempConfig_t hightemp;
    SpcTempConfig_t deadband;
} SpcTempGroupConfig_t;

/* Global values */
typedef struct {
    union {
        struct {
            uint64_t lcdDef : 2;
            uint64_t tempUint : 1;
            uint64_t ctrType : 1;
            uint64_t reserve : 60;
        } bits;
        uint64_t SpcMaskRom;
    };
    SpcTempConfig_t SpcMaintain;
    SpcTempConfig_t SpcLowTemp;
    SpcTempConfig_t SpcHighTemp;
    SpcTempConfig_t SpcDeadBand;
    SpcUint16Config_t SpcLowCurrent;
    SpcUint16Config_t SpcHighCurrent;
    SpcUint16Config_t SpcGFIAlarm;
    SpcUint16Config_t SpcGFITrip;
    SpcUint16Config_t SpcLowVoltage;
    SpcUint16Config_t SpcHighVoltage;
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
            uint64_t power : 1;
            uint64_t current : 1;
            uint64_t gfi : 1;
            uint64_t voltage : 1;
            uint64_t maxtemp : 1;
            uint64_t mintemp : 1;
            uint64_t maxcurr : 1;
            uint64_t maxgfi : 1;
            uint64_t maxvolt : 1;
            uint64_t minvolt : 1;
            uint64_t enegy : 1;
            uint64_t cost : 1;
            uint64_t ontime : 1;
            uint64_t onpercent : 1;
            uint64_t reserve : 47;
        } SpcRefreshBits;
        uint64_t SpcRefreshMask;
    };
    SpcTemp_t SpcTemp;
    SpcTemp_t SpcTempRTDA;
    SpcTemp_t SpcTempRTDB;
    SpcTemp_t SpcMaxTemp;
    SpcTemp_t SpcMinTemp;
    SpcUint16_t SpcPower;
    SpcUint16_t SpcCurrent;
    SpcUint16_t SpcMaxCurrent;
    SpcUint16_t SpcGfi;
    SpcUint16_t SpcMaxGfi;
    SpcUint16_t SpcVoltage;
    SpcUint16_t SpcMaxVoltage;
    SpcUint16_t SpcMinVoltage;
    SpcUint16_t SpcEnegy;
    SpcUint16_t SpcCost;
    SpcUint16_t SpcOnTime;
    SpcUint16_t SpcOnPercent;
} SpcDataRam_t;

/* From data.c */
void SpcDataInit(void);
uint8_t SpcData_GetLcdDef(void);
uint8_t SpcData_GetTempUint(void);
uint8_t SpcData_GetCtrlType(void);
uint64_t SpcData_GetMaskRam(void);
void SpcData_SetRefreshMask(uint64_t val);
uint64_t SpcData_GetRefreshMask(void);
bool SpcData_GetTemperature(SpcTemp_t *temp);
void SpcData_SetTemperature(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB);
bool SpcData_GetTempRTDA(SpcTemp_t *temp);
void SpcData_SetTempRTDA(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB);
bool SpcData_GetTempRTDB(SpcTemp_t *temp);
void SpcData_SetTempRTDB(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB);
bool SpcData_GetMaxTemperature(SpcTemp_t *temp);
void SpcData_SetMaxTemperature(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB);
bool SpcData_GetMinTemperature(SpcTemp_t *temp);
void SpcData_SetMinTemperature(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB);
void SpcData_SetPower(uint16_t power);
bool SpcData_GetPower(SpcUint16_t *power);
void SpcData_SetCurrent(uint16_t current);
bool SpcData_GetCurrent(SpcUint16_t *current);
void SpcData_SetMaxCurrent(uint16_t current);
bool SpcData_GetMaxCurrent(SpcUint16_t *current);
void SpcData_SetGfi(uint16_t gfi);
bool SpcData_GetGfi(SpcUint16_t *gfi);
void SpcData_SetMaxGfi(uint16_t gfi);
bool SpcData_GetMaxGfi(SpcUint16_t *gfi);
void SpcData_SetVoltage(uint16_t voltage);
bool SpcData_GetVoltage(SpcUint16_t *voltage);
void SpcData_SetMaxVoltage(uint16_t voltage);
bool SpcData_GetMaxVoltage(SpcUint16_t *voltage);
void SpcData_SetMinVoltage(uint16_t voltage);
bool SpcData_GetMinVoltage(SpcUint16_t *voltage);
void SpcData_SetEnegy(uint16_t voltage);
bool SpcData_GetEnegy(SpcUint16_t *voltage);
void SpcData_SetCost(uint16_t voltage);
bool SpcData_GetCost(SpcUint16_t *voltage);
void SpcData_SetOnTime(uint16_t voltage);
bool SpcData_GetOnTime(SpcUint16_t *voltage);
void SpcData_SetOnPercent(uint16_t voltage);
bool SpcData_GetOnPercent(SpcUint16_t *voltage);
bool SpcData_SetMaintain(SpcTempConfig_t *maintain);
bool SpcData_GetMaintain(SpcTempConfig_t *maintain);
bool SpcData_SetLowTemp(SpcTempConfig_t *lowtemp);
bool SpcData_GetLowTemp(SpcTempConfig_t *lowtemp);
bool SpcData_SetHighTemp(SpcTempConfig_t *hightemp);
bool SpcData_GetHighTemp(SpcTempConfig_t *hightemp);
bool SpcData_SetDeadBand(SpcTempConfig_t *deadband);
bool SpcData_GetDeadBand(SpcTempConfig_t *deadband);
bool SpcData_GetTempGroup(SpcTempGroupConfig_t *tempgroup);
bool SpcData_SetTempGroup(SpcTempGroupConfig_t *tempgroup);
bool SpcData_SetLowCurrent(SpcUint16Config_t *lowcurrent);
bool SpcData_GetLowCurrent(SpcUint16Config_t *lowcurrent);
bool SpcData_SetHighCurrent(SpcUint16Config_t *highcurrent);
bool SpcData_GetHighCurrent(SpcUint16Config_t *highcurrent);
bool SpcData_GetCurrentGroup(SpcCurrentGroupConfig_t *currentgroup);
bool SpcData_SetCurrentGroup(SpcCurrentGroupConfig_t *currentgroup);
bool SpcData_SetGFIAlarm(SpcUint16Config_t *gfialarm);
bool SpcData_GetGFIAlarm(SpcUint16Config_t *gfialarm);
bool SpcData_SetGFITrip(SpcUint16Config_t *gfitrip);
bool SpcData_GetGFITrip(SpcUint16Config_t *gfitrip);
bool SpcData_GetGfiGroup(SpcGfiGroupConfig_t *gfigroup);
bool SpcData_SetGfiGroup(SpcGfiGroupConfig_t *gfigroup);
bool SpcData_SetLowVoltage(SpcUint16Config_t *lowvoltage);
bool SpcData_GetLowVoltage(SpcUint16Config_t *lowvoltage);
bool SpcData_SetHighVoltage(SpcUint16Config_t *highvoltage);
bool SpcData_GetHighVoltage(SpcUint16Config_t *highvoltage);
bool SpcData_GetVoltageGroup(SpcVoltageGroupConfig_t *voltagegroup);
bool SpcData_SetVoltageGroup(SpcVoltageGroupConfig_t *voltagegroup);

#ifdef __cplusplus
}
#endif

#endif /* __DATA_H */
