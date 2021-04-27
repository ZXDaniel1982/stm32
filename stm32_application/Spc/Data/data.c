#include <string.h>
#include "FreeRTOS.h"
#include "semphr.h"
#include "data.h"
#include "key.h"

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

    DataMutex = xSemaphoreCreateMutex();

    // TODO, for test, delete in future
    SpcData_SetPower(60);
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

