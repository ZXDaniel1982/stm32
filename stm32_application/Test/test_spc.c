#include <unistd.h>
#include "spc.h"
#include "data.h"
#include "spctimer.h"

static SpcDataRom_t SpcDataRom;
static SpcDataRam_t SpcDataRam;

static uint8_t KeyIn;

static void Demo_Publish(PageInfo_t * info)
{
    printf("%s\n", info->Title);
    printf("%s\n", info->Content);
}

void SpcDataInit(void)
{
    memset(&SpcDataRom, 0, sizeof(SpcDataRom_t));
    memset(&SpcDataRam, 0, sizeof(SpcDataRam_t));
    
    SpcDataRom.SpcMaintain.status = Opt;
    SpcDataRom.SpcMaintain.temperature[0] = 50;
    SpcDataRom.SpcMaintain.temperature[1] = 10;
}

uint8_t SpcData_GetLcdDef(void)
{
    SpcDataRom.bits.lcdDef = 2;
    return (uint8_t) SpcDataRom.bits.lcdDef;
}

uint8_t SpcData_GetTempUint(void)
{
    SpcDataRom.bits.tempUint = 1;
    return (uint8_t) SpcDataRom.bits.tempUint;
}

uint64_t SpcData_GetMaskRam(void)
{
    SpcDataRam.SpcMaskBits.hasHeatStatus = 1;
    SpcDataRam.SpcMaskBits.heatStatus = 1;
    return SpcDataRam.SpcMaskRam;
}

bool SpcData_GetTemperature(SpcTemp_t *temp)
{
    if (temp == NULL) return false;

    SpcDataRam.SpcTemp.hasValue = 1;
    SpcDataRam.SpcTemp.temperature[0] = 16;
    SpcDataRam.SpcTemp.temperature[1] = 32;

    memset(temp, 0, sizeof(SpcTemp_t));
    memcpy(temp, &(SpcDataRam.SpcTemp), sizeof(SpcTemp_t));

    return true;
}

bool SpcData_GetTempRTDA(SpcTemp_t *temp)
{
    if (temp == NULL) return false;

    SpcDataRam.SpcTempRTDA.hasValue = 1;
    SpcDataRam.SpcTempRTDA.status = RTD_SHORT;
    SpcDataRam.SpcTempRTDA.temperature[0] = 160;
    SpcDataRam.SpcTempRTDA.temperature[1] = 320;

    memset(temp, 0, sizeof(SpcTemp_t));
    memcpy(temp, &(SpcDataRam.SpcTempRTDA), sizeof(SpcTemp_t));

    return true;
}

bool SpcData_GetTempRTDB(SpcTemp_t *temp)
{
    if (temp == NULL) return false;

    SpcDataRam.SpcTempRTDB.hasValue = 1;
    SpcDataRam.SpcTempRTDB.status = RTD_OPEN;
    SpcDataRam.SpcTempRTDB.temperature[0] = 16;
    SpcDataRam.SpcTempRTDB.temperature[1] = 32;

    memset(temp, 0, sizeof(SpcTemp_t));
    memcpy(temp, &(SpcDataRam.SpcTempRTDB), sizeof(SpcTemp_t));

    return true;
}

bool SpcData_GetMaxTemperature(SpcTemp_t *temp)
{
    if (temp == NULL) return false;

    SpcDataRam.SpcMaxTemp.hasValue = 1;
    SpcDataRam.SpcMaxTemp.temperature[0] = 16;
    SpcDataRam.SpcMaxTemp.temperature[1] = 32;

    memset(temp, 0, sizeof(SpcTemp_t));
    memcpy(temp, &(SpcDataRam.SpcMaxTemp), sizeof(SpcTemp_t));

    return true;
}

bool SpcData_GetMinTemperature(SpcTemp_t *temp)
{
    if (temp == NULL) return false;

    SpcDataRam.SpcMinTemp.hasValue = 1;
    SpcDataRam.SpcMinTemp.temperature[0] = 16;
    SpcDataRam.SpcMinTemp.temperature[1] = 32;

    memset(temp, 0, sizeof(SpcTemp_t));
    memcpy(temp, &(SpcDataRam.SpcMinTemp), sizeof(SpcTemp_t));

    return true;
}

bool SpcData_GetPower(SpcUint16_t *power)
{
    if (power == NULL) return false;

    SpcDataRam.SpcPower.hasValue = 1;
    SpcDataRam.SpcPower.value = 102;

    memset(power, 0, sizeof(SpcUint16_t));
    memcpy(power, &(SpcDataRam.SpcPower), sizeof(SpcUint16_t));
}

bool SpcData_GetVoltage(SpcUint16_t *volt)
{
    if (volt == NULL) return false;

    SpcDataRam.SpcVoltage.hasValue = 1;
    SpcDataRam.SpcVoltage.value = 102;

    memset(volt, 0, sizeof(SpcUint16_t));
    memcpy(volt, &(SpcDataRam.SpcVoltage), sizeof(SpcUint16_t));
}

bool SpcData_GetMaxVoltage(SpcUint16_t *volt)
{
    if (volt == NULL) return false;

    SpcDataRam.SpcMaxVoltage.hasValue = 1;
    SpcDataRam.SpcMaxVoltage.value = 150;

    memset(volt, 0, sizeof(SpcUint16_t));
    memcpy(volt, &(SpcDataRam.SpcMaxVoltage), sizeof(SpcUint16_t));
}

bool SpcData_GetMinVoltage(SpcUint16_t *volt)
{
    if (volt == NULL) return false;

    SpcDataRam.SpcMinVoltage.hasValue = 1;
    SpcDataRam.SpcMinVoltage.value = 80;

    memset(volt, 0, sizeof(SpcUint16_t));
    memcpy(volt, &(SpcDataRam.SpcMinVoltage), sizeof(SpcUint16_t));
}

bool SpcData_GetCurrent(SpcUint16_t *curr)
{
    if (curr == NULL) return false;

    SpcDataRam.SpcCurrent.hasValue = 1;
    SpcDataRam.SpcCurrent.value = 102;

    memset(curr, 0, sizeof(SpcUint16_t));
    memcpy(curr, &(SpcDataRam.SpcCurrent), sizeof(SpcUint16_t));
}

bool SpcData_GetMaxCurrent(SpcUint16_t *curr)
{
    if (curr == NULL) return false;

    SpcDataRam.SpcMaxCurrent.hasValue = 1;
    SpcDataRam.SpcMaxCurrent.value = 102;

    memset(curr, 0, sizeof(SpcUint16_t));
    memcpy(curr, &(SpcDataRam.SpcMaxCurrent), sizeof(SpcUint16_t));
}

bool SpcData_GetGfi(SpcUint16_t *gfi)
{
    if (gfi == NULL) return false;

    SpcDataRam.SpcGfi.hasValue = 1;
    SpcDataRam.SpcGfi.value = 102;

    memset(gfi, 0, sizeof(SpcUint16_t));
    memcpy(gfi, &(SpcDataRam.SpcGfi), sizeof(SpcUint16_t));
}

bool SpcData_GetMaxGfi(SpcUint16_t *gfi)
{
    if (gfi == NULL) return false;

    SpcDataRam.SpcMaxGfi.hasValue = 1;
    SpcDataRam.SpcMaxGfi.value = 102;

    memset(gfi, 0, sizeof(SpcUint16_t));
    memcpy(gfi, &(SpcDataRam.SpcMaxGfi), sizeof(SpcUint16_t));
}

bool SpcData_GetEnegy(SpcUint16_t *enegy)
{
    if (enegy == NULL) return false;

    SpcDataRam.SpcEnegy.hasValue = 1;
    SpcDataRam.SpcEnegy.value = 102;

    memset(enegy, 0, sizeof(SpcUint16_t));
    memcpy(enegy, &(SpcDataRam.SpcEnegy), sizeof(SpcUint16_t));
}

bool SpcData_GetCost(SpcUint16_t *cost)
{
    if (cost == NULL) return false;

    SpcDataRam.SpcCost.hasValue = 1;
    SpcDataRam.SpcCost.value = 102;

    memset(cost, 0, sizeof(SpcUint16_t));
    memcpy(cost, &(SpcDataRam.SpcCost), sizeof(SpcUint16_t));
}

bool SpcData_GetOnTime(SpcUint16_t *ontime)
{
    if (ontime == NULL) return false;

    SpcDataRam.SpcOnTime.hasValue = 1;
    SpcDataRam.SpcOnTime.value = 1000;

    memset(ontime, 0, sizeof(SpcUint16_t));
    memcpy(ontime, &(SpcDataRam.SpcOnTime), sizeof(SpcUint16_t));
}

bool SpcData_GetOnPercent(SpcUint16_t *onpercent)
{
    if (onpercent == NULL) return false;

    SpcDataRam.SpcOnPercent.hasValue = 1;
    SpcDataRam.SpcOnPercent.value = 78;

    memset(onpercent, 0, sizeof(SpcUint16_t));
    memcpy(onpercent, &(SpcDataRam.SpcOnPercent), sizeof(SpcUint16_t));
}

bool SpcData_SetMaintain(SpcTempConfig_t *maintain)
{
    if (maintain == NULL) return false;

    memcpy(&(SpcDataRom.SpcMaintain), maintain, sizeof(SpcTempConfig_t));

    return true;
}

bool SpcData_GetMaintain(SpcTempConfig_t *maintain)
{
    if (maintain == NULL) return false;

    memset(maintain, 0, sizeof(SpcTempConfig_t));
    memcpy(maintain, &(SpcDataRom.SpcMaintain), sizeof(SpcTempConfig_t));

    return true;
}

void SpcData_SetRefreshMask(uint64_t val)
{
    SpcDataRam.SpcRefreshMask = val; 
}

uint64_t SpcData_GetRefreshMask(void)
{
    return SpcDataRam.SpcRefreshMask; 
}

void main()
{
    PageEntity_t *Page = NULL;
    PageEntity_t *PageNext = NULL;

    SpcDataInit();
    SpcTimer_Init();

    printf("Spc mainloop task\r\n");
    Page = Page_CreatePage(Default, printf, Demo_Publish);
    if (Page == NULL) {
        printf("Failed to create page\r\n");
    }
    while (1) {
        /* Block to wait for prvTask1() to notify this task. */
        printf("Please input key: ");
        scanf ("%d", (int *)(&KeyIn));
        if (Page->func != NULL) {
            PageNext = Page->func(KeyIn, printf, Page);
            if (PageNext != NULL) {
                if (Page->data != NULL) free(Page->data);
                free(Page);
                Page = PageNext;
            }
        } else {
        }
        if (KeyIn == 1) {
          if (Page != NULL) {
            if (Page->data != NULL) free(Page->data);
            free(Page);
            return;
          }
          return;
        }

        SpcTimer_UpdateTimer();
    }
}
