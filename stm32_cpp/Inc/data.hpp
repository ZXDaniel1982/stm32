#pragma once

#include <unordered_map>

enum class DataStatus {
    Normal = 0,
    Short,
    Open,
    Out,
    Off,
    None,
    Disable,
    Continue,

    Max
};

enum class RtdChan {
    Chan1 = 0,
    Chan2,
    Stack,

    Max
};

enum class RdtStat {
    Off = 0,
    On,
    ManOff,
    ManOn
};

enum class DefInfo {
    SysStatus = 0,
    HeaterStatus,
    HeaterTemp,
};

enum class Opt {
    Empty = 0,
    Actual,
    Prog,
    Enter,
    Right,
    Left,
    Up,
    Down,
    Reset,
    Alarm,
};

typedef struct {
    DataStatus status;
    int16_t tempf;
    int16_t tempc;
} SpcTemperature_t;

typedef struct {
    std::unordered_map<RtdChan, SpcTemperature_t> temp;
    int16_t gfi;
    int16_t PowerPercent;
    int16_t Current;
    int16_t Voltage;
} SpcMeasure_t;

typedef struct
{
    DataStatus status;
    int16_t val;
} SpcConfInt16_t;

typedef struct
{
    uint32_t unit:1;
    uint32_t heater_en:1;
    uint32_t manual:1;
    uint32_t ctl_type:1;
    uint32_t rtdMod:3;
    uint32_t rtd_fail_mod:1;
    uint32_t password_en:1;
    uint32_t defInfo:2;
    uint32_t rdtStat:2;
    uint32_t usr_advanced:1;
    uint32_t baud:3;
    uint32_t gfi_test_mod:2;
    uint32_t heater_type:1;
    uint32_t reservd:12;
} SpcSysConfBytes_t;

typedef union
{
    uint32_t word;
    SpcSysConfBytes_t bytes;
} SpcSysConf_t;

typedef struct
{
    SpcTemperature_t MaintainTemp;
    SpcTemperature_t LowTemp;
    SpcTemperature_t HighTemp;
    SpcTemperature_t DeadBand;
    SpcConfInt16_t   LowCurrent;
    SpcConfInt16_t   HighCurrent;
    SpcConfInt16_t   GFIAlarm;
    SpcConfInt16_t   GFITrip;
    SpcConfInt16_t   LowVoltage;
    SpcConfInt16_t   HighVoltage;
    SpcConfInt16_t   LimitedCurrent;
    SpcConfInt16_t   SoftStartTime;
    SpcConfInt16_t   AutoTestTime;
    SpcConfInt16_t   DisplayTime;
    SpcConfInt16_t   CostPerKWH;
    SpcConfInt16_t   ScanSpeed;
    SpcConfInt16_t   ModbusAdd;
    SpcConfInt16_t   BaudRate;
    SpcConfInt16_t   AlarmOutTest;
    SpcConfInt16_t   HeaterTest;
    SpcConfInt16_t   GFTest;

    SpcSysConf_t system;
} SpcConfig_t;

typedef struct
{
    SpcTemperature_t maxTemp;
    SpcTemperature_t minTemp;
    int16_t   MaxCurrent;
    int16_t   MaxGFCurrent;
    int16_t   MaxVoltage;
    int16_t   MinVoltage;
    int16_t   EnergyUsed;
    int16_t   HeaterOnTime;
    int32_t   EnergyCost;
    int32_t   RunTime;
} SpcStatistic_t;

typedef struct {
	std::string name;
	std::string password;
    SpcMeasure_t measure;
    SpcConfig_t config;
    SpcStatistic_t status;
} SpcData_t;
