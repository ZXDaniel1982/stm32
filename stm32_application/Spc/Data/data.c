#include <string.h>
#include "FreeRTOS.h"
#include "semphr.h"
#include "data.h"
#include "key.h"

static const SpcDataRom_t SpcDataRomDefault = {
    .SpcMaskRom = 0,
    .SpcMaintain = {.status = Opt, {10, 50}},
    .SpcLowTemp = {.status = Opt, {5, 41}},
    .SpcHighTemp = {.status = OFF, {0, 0}},
    .SpcDeadBand = {.status = Opt, {2, 1}},
    .SpcLowCurrent = {.status = Uint16OFF, 0},
    .SpcHighCurrent = {.status = Uint16OFF, 0},
    .SpcGFIAlarm = {.status = Uint16Opt, 30},
    .SpcGFITrip = {.status = Uint16Opt, 50},
    .SpcLowVoltage = {.status = Uint16OFF, 0},
    .SpcHighVoltage = {.status = Uint16OFF, 0},
    .SpcCurrentLimit = {.status = Uint16OFF, 0},
    .SpcSoftStart = {.status = Uint16OFF, 0},
    .SpcAutoTest = {.status = Uint16Opt, 24},
    .SpcPowerPrice = {.status = Uint16Opt, 5},
    .SpcTimeout = {.status = Uint16Opt, 120},
    .SpcScanSpeed = {.status = Uint16Opt, 3},
    .SpcModbusAddress = {.status = Uint16Opt, 1},
    .SpcAlarmOutput = {.status = Uint16OFF, 0},
    .SpcHeaterTest = {.status = Uint16OFF, 0},
    .HeaterName = "Spc",
    .Password = "1234"
};

extern xQueueHandle UartQueue;

static SemaphoreHandle_t DataMutex;

static SpcDataRom_t SpcDataRom;
static SpcDataRam_t SpcDataRam;

static void SpcData_Refresh(void)
{
    uint8_t val = Update;
    xQueueSend(UartQueue, &val, portMAX_DELAY);
}

void SpcDataInit(void)
{
    memset(&SpcDataRom, 0, sizeof(SpcDataRom_t));
    memset(&SpcDataRam, 0, sizeof(SpcDataRam_t));

    memcpy(&SpcDataRom, &SpcDataRomDefault, sizeof(SpcDataRom_t));

    DataMutex = xSemaphoreCreateMutex();

    // TODO, for test, delete in future
    /*SpcData_SetPower(60);
    SpcData_SetPassword((uint8_t *)"1234");

    SpcDataRom.SpcMaintain.status = Opt;
    SpcDataRom.SpcMaintain.temperature[0] = 50;
    SpcDataRom.SpcMaintain.temperature[1] = 10;*/
}

uint8_t SpcData_GetLcdDef(void)
{
    uint8_t val = 0;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    val = (uint8_t) SpcDataRom.bits.lcdDef;
    xSemaphoreGive(DataMutex);

    return val;
}

uint8_t SpcData_GetTempUint(void)
{
    uint8_t val = 0;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    val = (uint8_t) SpcDataRom.bits.tempUint;
    xSemaphoreGive(DataMutex);

    return val;
}

uint8_t SpcData_GetCtrlType(void)
{
    uint8_t val = 0;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    val = (uint8_t) SpcDataRom.bits.ctrType;
    xSemaphoreGive(DataMutex);

    return val;
}

bool SpcData_GetMaskRom(uint64_t *mask)
{
    if (mask == NULL) return false;

    memset(mask, 0, sizeof(uint64_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(mask, &(SpcDataRom.SpcMaskRom), sizeof(uint64_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetMaskRom(uint64_t *mask)
{
    if (mask == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcMaskRom), mask, sizeof(uint64_t));
    xSemaphoreGive(DataMutex);

    return true;
}

uint64_t SpcData_GetMaskRam(void)
{
    uint64_t val = 0;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    val = SpcDataRam.SpcMaskRam;
    xSemaphoreGive(DataMutex);

    return val;
}

bool SpcData_GetTemperature(SpcTemp_t *temp)
{
    if (temp == NULL) return false;

    memset(temp, 0, sizeof(SpcTemp_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(temp, &(SpcDataRam.SpcTemp), sizeof(SpcTemp_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetTemperature(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcTemp.hasValue = 1;
    SpcDataRam.SpcTemp.status = status;
    SpcDataRam.SpcTemp.temperature[0] = tempA;
    SpcDataRam.SpcTemp.temperature[1] = tempB;

    update = SpcDataRam.SpcRefreshBits.temperature;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetTempRTDA(SpcTemp_t *temp)
{
    if (temp == NULL) return false;

    memset(temp, 0, sizeof(SpcTemp_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(temp, &(SpcDataRam.SpcTempRTDA), sizeof(SpcTemp_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetTempRTDA(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcTempRTDA.hasValue = 1;
    SpcDataRam.SpcTempRTDA.status = status;
    SpcDataRam.SpcTempRTDA.temperature[0] = tempA;
    SpcDataRam.SpcTempRTDA.temperature[1] = tempB;

    update = SpcDataRam.SpcRefreshBits.tempRTDA;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetTempRTDB(SpcTemp_t *temp)
{
    if (temp == NULL) return false;

    memset(temp, 0, sizeof(SpcTemp_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(temp, &(SpcDataRam.SpcTempRTDB), sizeof(SpcTemp_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetTempRTDB(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcTempRTDB.hasValue = 1;
    SpcDataRam.SpcTempRTDB.status = status;
    SpcDataRam.SpcTempRTDB.temperature[0] = tempA;
    SpcDataRam.SpcTempRTDB.temperature[1] = tempB;

    update = SpcDataRam.SpcRefreshBits.tempRTDB;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetMaxTemperature(SpcTemp_t *temp)
{
    if (temp == NULL) return false;

    memset(temp, 0, sizeof(SpcTemp_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(temp, &(SpcDataRam.SpcMaxTemp), sizeof(SpcTemp_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetMaxTemperature(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcMaxTemp.hasValue = 1;
    SpcDataRam.SpcMaxTemp.status = status;
    SpcDataRam.SpcMaxTemp.temperature[0] = tempA;
    SpcDataRam.SpcMaxTemp.temperature[1] = tempB;

    update = SpcDataRam.SpcRefreshBits.maxtemp;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetMinTemperature(SpcTemp_t *temp)
{
    if (temp == NULL) return false;

    memset(temp, 0, sizeof(SpcTemp_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(temp, &(SpcDataRam.SpcMinTemp), sizeof(SpcTemp_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetMinTemperature(SpcTempStatus_Enum_t status, int16_t tempA, int16_t tempB)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcMinTemp.hasValue = 1;
    SpcDataRam.SpcMinTemp.status = status;
    SpcDataRam.SpcMinTemp.temperature[0] = tempA;
    SpcDataRam.SpcMinTemp.temperature[1] = tempB;

    update = SpcDataRam.SpcRefreshBits.mintemp;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

void SpcData_SetMaxCurrent(uint16_t current)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcMaxCurrent.hasValue = 1;
    SpcDataRam.SpcMaxCurrent.value = current;

    update = SpcDataRam.SpcRefreshBits.maxcurr;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetMaxCurrent(SpcUint16_t *current)
{
    if (current == NULL) return false;

    memset(current, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(current, &(SpcDataRam.SpcMaxCurrent), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetMaxGfi(uint16_t gfi)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcMaxGfi.hasValue = 1;
    SpcDataRam.SpcMaxGfi.value = gfi;

    update = SpcDataRam.SpcRefreshBits.maxgfi;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetMaxGfi(SpcUint16_t *gfi)
{
    if (gfi == NULL) return false;

    memset(gfi, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(gfi, &(SpcDataRam.SpcMaxGfi), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetPower(uint16_t power)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcPower.hasValue = 1;
    SpcDataRam.SpcPower.value = power;

    update = SpcDataRam.SpcRefreshBits.power;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetPower(SpcUint16_t *power)
{
    if (power == NULL) return false;

    memset(power, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(power, &(SpcDataRam.SpcPower), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetVoltage(uint16_t voltage)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcVoltage.hasValue = 1;
    SpcDataRam.SpcVoltage.value = voltage;

    update = SpcDataRam.SpcRefreshBits.voltage;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetVoltage(SpcUint16_t *voltage)
{
    if (voltage == NULL) return false;

    memset(voltage, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(voltage, &(SpcDataRam.SpcVoltage), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetMaxVoltage(uint16_t voltage)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcMaxVoltage.hasValue = 1;
    SpcDataRam.SpcMaxVoltage.value = voltage;

    update = SpcDataRam.SpcRefreshBits.maxvolt;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetMaxVoltage(SpcUint16_t *voltage)
{
    if (voltage == NULL) return false;

    memset(voltage, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(voltage, &(SpcDataRam.SpcMaxVoltage), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetMinVoltage(uint16_t voltage)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcMinVoltage.hasValue = 1;
    SpcDataRam.SpcMinVoltage.value = voltage;

    update = SpcDataRam.SpcRefreshBits.minvolt;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetMinVoltage(SpcUint16_t *voltage)
{
    if (voltage == NULL) return false;

    memset(voltage, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(voltage, &(SpcDataRam.SpcMinVoltage), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetCurrent(uint16_t current)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcCurrent.hasValue = 1;
    SpcDataRam.SpcCurrent.value = current;

    update = SpcDataRam.SpcRefreshBits.current;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetCurrent(SpcUint16_t *current)
{
    if (current == NULL) return false;

    memset(current, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(current, &(SpcDataRam.SpcCurrent), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetGfi(uint16_t gfi)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcGfi.hasValue = 1;
    SpcDataRam.SpcGfi.value = gfi;

    update = SpcDataRam.SpcRefreshBits.gfi;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetGfi(SpcUint16_t *gfi)
{
    if (gfi == NULL) return false;

    memset(gfi, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(gfi, &(SpcDataRam.SpcGfi), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetEnegy(uint16_t enegy)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcEnegy.hasValue = 1;
    SpcDataRam.SpcEnegy.value = enegy;

    update = SpcDataRam.SpcRefreshBits.enegy;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetEnegy(SpcUint16_t *enegy)
{
    if (enegy == NULL) return false;

    memset(enegy, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(enegy, &(SpcDataRam.SpcEnegy), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetCost(uint16_t cost)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcCost.hasValue = 1;
    SpcDataRam.SpcCost.value = cost;

    update = SpcDataRam.SpcRefreshBits.cost;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetCost(SpcUint16_t *cost)
{
    if (cost == NULL) return false;

    memset(cost, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(cost, &(SpcDataRam.SpcCost), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetOnTime(uint16_t ontime)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcOnTime.hasValue = 1;
    SpcDataRam.SpcOnTime.value = ontime;

    update = SpcDataRam.SpcRefreshBits.ontime;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetOnTime(SpcUint16_t *ontime)
{
    if (ontime == NULL) return false;

    memset(ontime, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(ontime, &(SpcDataRam.SpcOnTime), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetOnPercent(uint16_t onpercent)
{
    bool update = false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcOnPercent.hasValue = 1;
    SpcDataRam.SpcOnPercent.value = onpercent;

    update = SpcDataRam.SpcRefreshBits.onpercent;
    xSemaphoreGive(DataMutex);

    if (update)
        SpcData_Refresh();
}

bool SpcData_GetOnPercent(SpcUint16_t *onpercent)
{
    if (onpercent == NULL) return false;

    memset(onpercent, 0, sizeof(SpcUint16_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(onpercent, &(SpcDataRam.SpcOnPercent), sizeof(SpcUint16_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetMaintain(SpcTempConfig_t *maintain)
{
    if (maintain == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcMaintain), maintain, sizeof(SpcTempConfig_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetMaintain(SpcTempConfig_t *maintain)
{
    if (maintain == NULL) return false;

    memset(maintain, 0, sizeof(SpcTempConfig_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(maintain, &(SpcDataRom.SpcMaintain), sizeof(SpcTempConfig_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetLowTemp(SpcTempConfig_t *lowtemp)
{
    if (lowtemp == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcLowTemp), lowtemp, sizeof(SpcTempConfig_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetLowTemp(SpcTempConfig_t *lowtemp)
{
    if (lowtemp == NULL) return false;

    memset(lowtemp, 0, sizeof(SpcTempConfig_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(lowtemp, &(SpcDataRom.SpcLowTemp), sizeof(SpcTempConfig_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetHighTemp(SpcTempConfig_t *hightemp)
{
    if (hightemp == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcHighTemp), hightemp, sizeof(SpcTempConfig_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetHighTemp(SpcTempConfig_t *hightemp)
{
    if (hightemp == NULL) return false;

    memset(hightemp, 0, sizeof(SpcTempConfig_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(hightemp, &(SpcDataRom.SpcHighTemp), sizeof(SpcTempConfig_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetDeadBand(SpcTempConfig_t *deadband)
{
    if (deadband == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcDeadBand), deadband, sizeof(SpcTempConfig_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetDeadBand(SpcTempConfig_t *deadband)
{
    if (deadband == NULL) return false;

    memset(deadband, 0, sizeof(SpcTempConfig_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(deadband, &(SpcDataRom.SpcDeadBand), sizeof(SpcTempConfig_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetTempGroup(SpcTempGroupConfig_t *tempgroup)
{
    if (tempgroup == NULL) return false;

    memset(tempgroup, 0, sizeof(SpcTempGroupConfig_t));

    SpcData_GetMaintain(&(tempgroup->maintain));
    SpcData_GetLowTemp(&(tempgroup->lowtemp));
    SpcData_GetHighTemp(&(tempgroup->hightemp));
    SpcData_GetDeadBand(&(tempgroup->deadband));

    return true;
}

bool SpcData_SetTempGroup(SpcTempGroupConfig_t *tempgroup)
{
    if (tempgroup == NULL) return false;

    SpcData_SetMaintain(&(tempgroup->maintain));
    SpcData_SetLowTemp(&(tempgroup->lowtemp));
    SpcData_SetHighTemp(&(tempgroup->hightemp));
    SpcData_SetDeadBand(&(tempgroup->deadband));

    return true;
}

bool SpcData_SetLowCurrent(SpcUint16Config_t *lowcurrent)
{
    if (lowcurrent == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcLowCurrent), lowcurrent, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetLowCurrent(SpcUint16Config_t *lowcurrent)
{
    if (lowcurrent == NULL) return false;

    memset(lowcurrent, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(lowcurrent, &(SpcDataRom.SpcLowCurrent), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetHighCurrent(SpcUint16Config_t *highcurrent)
{
    if (highcurrent == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcHighCurrent), highcurrent, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetHighCurrent(SpcUint16Config_t *highcurrent)
{
    if (highcurrent == NULL) return false;

    memset(highcurrent, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(highcurrent, &(SpcDataRom.SpcHighCurrent), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetCurrentGroup(SpcCurrentGroupConfig_t *currentgroup)
{
    if (currentgroup == NULL) return false;

    memset(currentgroup, 0, sizeof(SpcCurrentGroupConfig_t));

    SpcData_GetLowCurrent(&(currentgroup->lowcurrent));
    SpcData_GetHighCurrent(&(currentgroup->highcurrent));

    return true;
}

bool SpcData_SetCurrentGroup(SpcCurrentGroupConfig_t *currentgroup)
{
    if (currentgroup == NULL) return false;

    SpcData_SetLowCurrent(&(currentgroup->lowcurrent));
    SpcData_SetHighCurrent(&(currentgroup->highcurrent));

    return true;
}

bool SpcData_SetGFIAlarm(SpcUint16Config_t *gfialarm)
{
    if (gfialarm == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcGFIAlarm), gfialarm, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetGFIAlarm(SpcUint16Config_t *gfialarm)
{
    if (gfialarm == NULL) return false;

    memset(gfialarm, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(gfialarm, &(SpcDataRom.SpcGFIAlarm), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetGFITrip(SpcUint16Config_t *gfitrip)
{
    if (gfitrip == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcGFITrip), gfitrip, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetGFITrip(SpcUint16Config_t *gfitrip)
{
    if (gfitrip == NULL) return false;

    memset(gfitrip, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(gfitrip, &(SpcDataRom.SpcGFITrip), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetGfiGroup(SpcGfiGroupConfig_t *gfigroup)
{
    if (gfigroup == NULL) return false;

    memset(gfigroup, 0, sizeof(SpcGfiGroupConfig_t));

    SpcData_GetGFIAlarm(&(gfigroup->gfialarm));
    SpcData_GetGFITrip(&(gfigroup->gfitrip));

    return true;
}

bool SpcData_SetGfiGroup(SpcGfiGroupConfig_t *gfigroup)
{
    if (gfigroup == NULL) return false;

    SpcData_SetGFIAlarm(&(gfigroup->gfialarm));
    SpcData_SetGFITrip(&(gfigroup->gfitrip));

    return true;
}

bool SpcData_SetLowVoltage(SpcUint16Config_t *lowvoltage)
{
    if (lowvoltage == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcLowVoltage), lowvoltage, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetLowVoltage(SpcUint16Config_t *lowvoltage)
{
    if (lowvoltage == NULL) return false;

    memset(lowvoltage, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(lowvoltage, &(SpcDataRom.SpcLowVoltage), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetHighVoltage(SpcUint16Config_t *highvoltage)
{
    if (highvoltage == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcHighVoltage), highvoltage, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetHighVoltage(SpcUint16Config_t *highvoltage)
{
    if (highvoltage == NULL) return false;

    memset(highvoltage, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(highvoltage, &(SpcDataRom.SpcHighVoltage), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetVoltageGroup(SpcVoltageGroupConfig_t *voltagegroup)
{
    if (voltagegroup == NULL) return false;

    memset(voltagegroup, 0, sizeof(SpcVoltageGroupConfig_t));

    SpcData_GetLowVoltage(&(voltagegroup->lowvoltage));
    SpcData_GetHighVoltage(&(voltagegroup->highvoltage));

    return true;
}

bool SpcData_SetVoltageGroup(SpcVoltageGroupConfig_t *voltagegroup)
{
    if (voltagegroup == NULL) return false;

    SpcData_SetLowVoltage(&(voltagegroup->lowvoltage));
    SpcData_SetHighVoltage(&(voltagegroup->highvoltage));

    return true;
}

bool SpcData_SetHeaterName(uint8_t *name)
{
    if (name == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    strncpy((char *)SpcDataRom.HeaterName, (char *)name, MAX_INFO_LEN);
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetHeaterName(uint8_t *name)
{
    if (name == NULL) return false;

    memset((char *)name, 0, MAX_INFO_LEN);

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    strncpy((char *)name, (char *)SpcDataRom.HeaterName, MAX_INFO_LEN);
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetCurrentLimit(SpcUint16Config_t *currentlimit)
{
    if (currentlimit == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcCurrentLimit), currentlimit, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetCurrentLimit(SpcUint16Config_t *currentlimit)
{
    if (currentlimit == NULL) return false;

    memset(currentlimit, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(currentlimit, &(SpcDataRom.SpcCurrentLimit), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetSoftStart(SpcUint16Config_t *softstart)
{
    if (softstart == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcSoftStart), softstart, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetSoftStart(SpcUint16Config_t *softstart)
{
    if (softstart == NULL) return false;

    memset(softstart, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(softstart, &(SpcDataRom.SpcSoftStart), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetAutoTest(SpcUint16Config_t *autotest)
{
    if (autotest == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcAutoTest), autotest, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetAutoTest(SpcUint16Config_t *autotest)
{
    if (autotest == NULL) return false;

    memset(autotest, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(autotest, &(SpcDataRom.SpcAutoTest), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetPowerPrice(SpcUint16Config_t *powerprice)
{
    if (powerprice == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcPowerPrice), powerprice, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetPowerPrice(SpcUint16Config_t *powerprice)
{
    if (powerprice == NULL) return false;

    memset(powerprice, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(powerprice, &(SpcDataRom.SpcPowerPrice), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetTimeout(SpcUint16Config_t *timeout)
{
    if (timeout == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcTimeout), timeout, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetTimeout(SpcUint16Config_t *timeout)
{
    if (timeout == NULL) return false;

    memset(timeout, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(timeout, &(SpcDataRom.SpcTimeout), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetScanSpeed(SpcUint16Config_t *scanspeed)
{
    if (scanspeed == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcScanSpeed), scanspeed, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetScanSpeed(SpcUint16Config_t *scanspeed)
{
    if (scanspeed == NULL) return false;

    memset(scanspeed, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(scanspeed, &(SpcDataRom.SpcScanSpeed), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetModbusAddress(SpcUint16Config_t *modbusaddress)
{
    if (modbusaddress == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcModbusAddress), modbusaddress, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetModbusAddress(SpcUint16Config_t *modbusaddress)
{
    if (modbusaddress == NULL) return false;

    memset(modbusaddress, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(modbusaddress, &(SpcDataRom.SpcModbusAddress), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetAlarmOutput(SpcUint16Config_t *alarmoutput)
{
    if (alarmoutput == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcAlarmOutput), alarmoutput, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetAlarmOutput(SpcUint16Config_t *alarmoutput)
{
    if (alarmoutput == NULL) return false;

    memset(alarmoutput, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(alarmoutput, &(SpcDataRom.SpcAlarmOutput), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetHeaterTest(SpcUint16Config_t *heatertest)
{
    if (heatertest == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(&(SpcDataRom.SpcHeaterTest), heatertest, sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetHeaterTest(SpcUint16Config_t *heatertest)
{
    if (heatertest == NULL) return false;

    memset(heatertest, 0, sizeof(SpcUint16Config_t));

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    memcpy(heatertest, &(SpcDataRom.SpcHeaterTest), sizeof(SpcUint16Config_t));
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_SetPassword(uint8_t *passwd)
{
    if (passwd == NULL) return false;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    strncpy((char *)SpcDataRom.Password, (char *)passwd, MAX_INFO_LEN);
    xSemaphoreGive(DataMutex);

    return true;
}

bool SpcData_GetPassword(uint8_t *passwd)
{
    if (passwd == NULL) return false;

    memset((char *)passwd, 0, MAX_INFO_LEN);

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    strncpy((char *)passwd, (char *)SpcDataRom.Password, MAX_INFO_LEN);
    xSemaphoreGive(DataMutex);

    return true;
}

void SpcData_SetRefreshMask(uint64_t val)
{
    xSemaphoreTake(DataMutex, portMAX_DELAY);
    SpcDataRam.SpcRefreshMask = val; 
    xSemaphoreGive(DataMutex);
}

uint64_t SpcData_GetRefreshMask(void)
{
    uint64_t val;

    xSemaphoreTake(DataMutex, portMAX_DELAY);
    val = SpcDataRam.SpcRefreshMask; 
    xSemaphoreGive(DataMutex);

    return val;
}

