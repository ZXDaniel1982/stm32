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

