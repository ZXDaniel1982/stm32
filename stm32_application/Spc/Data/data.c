#include <string.h>
#include "FreeRTOS.h"
#include "semphr.h"
#include "data.h"

static SemaphoreHandle_t DataMutex;

static SpcDataRom_t SpcDataRom;
static SpcDataRam_t SpcDataRam;

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

