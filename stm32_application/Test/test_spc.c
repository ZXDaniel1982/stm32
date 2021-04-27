#include <unistd.h>
#include "spc.h"
#include "data.h"

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

bool SpcData_GetCurrent(SpcUint16_t *curr)
{
    if (curr == NULL) return false;

    SpcDataRam.SpcCurrent.hasValue = 1;
    SpcDataRam.SpcCurrent.value = 102;

    memset(curr, 0, sizeof(SpcUint16_t));
    memcpy(curr, &(SpcDataRam.SpcCurrent), sizeof(SpcUint16_t));
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
                free(Page);
                Page = PageNext;
            }
        } else {
        }
    }
}
