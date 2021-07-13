#include "spc.h"

#define PrivNormal_Msk              (0)
#define PrivMaintainNone_Pos        (0)
#define PrivMaintainNone_Msk        (1ul << PrivMaintainNone_Pos)
#define PrivMaintainOff_Pos         (1)
#define PrivMaintainOff_Msk         (1ul << PrivMaintainOff_Pos)
#define PrivAdvanced_Pos            (2)
#define PrivAdvanced_Msk            (1ul << PrivAdvanced_Pos)
#define PrivProport_Pos             (3)
#define PrivProport_Msk             (1ul << PrivProport_Pos)
#define PrivSelfRegular_Pos         (4)
#define PrivSelfRegular_Msk         (1ul << PrivSelfRegular_Pos)

static const PagePrivilege_t kPagePrivilege[] = {
    {Actual, PrivNormal_Msk},
    {HeatSt, PrivNormal_Msk},
    {Temperature, PrivMaintainOff_Msk | PrivMaintainNone_Msk},
    {TempRTDA, PrivMaintainOff_Msk | PrivAdvanced_Msk},
    {TempRTDB, PrivMaintainOff_Msk | PrivAdvanced_Msk},
    {Power, PrivAdvanced_Msk},
    {Current, PrivNormal_Msk},
    {Gfi, PrivNormal_Msk},
    {Voltage, PrivNormal_Msk},
    {Statistic, PrivAdvanced_Msk},
    {MaxTemperature, PrivMaintainOff_Msk | PrivAdvanced_Msk},
    {MinTemperature, PrivMaintainOff_Msk | PrivAdvanced_Msk},
    {MaxCurrent, PrivAdvanced_Msk},
    {MaxGfi, PrivAdvanced_Msk},
    {MaxVoltage, PrivAdvanced_Msk},
    {MinVoltage, PrivAdvanced_Msk},
    {Enegy, PrivAdvanced_Msk},
    {Cost, PrivAdvanced_Msk},
    {OnTime, PrivAdvanced_Msk},
    {OnPercent, PrivAdvanced_Msk},
    {ResetStatistic, PrivAdvanced_Msk},
    {Version, PrivAdvanced_Msk},
    {Program, PrivNormal_Msk},
    {Maintain, PrivNormal_Msk},
    {LowTemp, PrivMaintainOff_Msk},
    {HighTemp, PrivMaintainOff_Msk},
    {LowCurrent, PrivNormal_Msk},
    {HighCurrent, PrivNormal_Msk},
    {GFIAlarm, PrivNormal_Msk},
    {GFITrip, PrivNormal_Msk},
    {LowVoltage, PrivNormal_Msk},
    {HighVoltage, PrivNormal_Msk},
    {HeaterSetup, PrivNormal_Msk},
    {HeaterEn, PrivNormal_Msk},
    {HeaterName, PrivAdvanced_Msk},
    {HeaterType, PrivAdvanced_Msk},
    {ManualOverride, PrivAdvanced_Msk},
    {DeadBand, PrivAdvanced_Msk | PrivMaintainOff_Msk | PrivProport_Msk},
    {ControlType, PrivAdvanced_Msk | PrivMaintainOff_Msk | PrivSelfRegular_Msk},
    {CurrentLimit, PrivAdvanced_Msk | PrivSelfRegular_Msk},
    {SoftStart, PrivAdvanced_Msk},
    {AutoTest, PrivAdvanced_Msk},
    {RtdOptMode, PrivAdvanced_Msk | PrivMaintainOff_Msk},
    {RtdFailMode, PrivAdvanced_Msk | PrivMaintainOff_Msk},
    {SystemSetup, PrivNormal_Msk},
    {PasswdEn, PrivNormal_Msk},
    {Password, PrivAdvanced_Msk},
    {TempUnits, PrivAdvanced_Msk},
    {PowerPrice, PrivAdvanced_Msk},
    {DisplayMode, PrivNormal_Msk},
    {DefaultDisplay, PrivAdvanced_Msk},
    {Timeout, PrivAdvanced_Msk},
    {ScanSpeed, PrivNormal_Msk},
    {ModbusAddress, PrivAdvanced_Msk},
    {Baudrate, PrivAdvanced_Msk},
    {ResetModule, PrivAdvanced_Msk},
    {SystemTest, PrivAdvanced_Msk},
    {AlarmOutput, PrivAdvanced_Msk},
    {HeaterTest, PrivAdvanced_Msk},
    {GfiTest, PrivAdvanced_Msk}
};

static const PageValidator_t kPageValidator[] = {
    {PrivMaintainNone_Msk,  MaintainIsNone},
    {PrivMaintainOff_Msk,   MaintainIsOff},
    {PrivAdvanced_Msk,      MenuIsNotAdvance},
    {PrivProport_Msk,       ControlIsProport},
    {PrivSelfRegular_Msk,   HeaterIsSelfRegular}
};

static bool Spc_PageIsConflict(uint8_t index)
{
    for (uint8_t i = 0; i < NUM_ROWS(kPageValidator); ++i) {
        if (kPagePrivilege[index].mask & kPageValidator[i].mask) {
           if (kPageValidator[i].validator()) return true;
        }
    }
    return false;
}

PageEnum_t Spc_GetNextPage(Logger logger, KeyEnum_t key, PageEnum_t type)
{
    if ((key != Left) && (key != Right)) {
        logger("\r\nInvalid Key\r\n");
        return Default;
    }

    uint8_t totalIndex = NUM_ROWS(kPagePrivilege);
    uint8_t currentIndex = totalIndex + 1;
    for (uint8_t i = 0; i < totalIndex; ++i) {
        if (type == kPagePrivilege[i].type) {
           currentIndex = i;
           break;
        }
    }

    if (currentIndex == totalIndex + 1) {
        logger("\r\nInvalid Page\r\n");
        return Default;
    }

    while (1) {
        if (key == Right) currentIndex = (currentIndex + totalIndex + 1) % totalIndex;
        else if (key == Left) currentIndex = (currentIndex + totalIndex - 1) % totalIndex;

        if (Spc_PageIsConflict(currentIndex)) continue;

        return kPagePrivilege[currentIndex].type;
    }
}
