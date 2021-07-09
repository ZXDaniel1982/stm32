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

    strncpy(SpcDataRom.Password, "1234", MAX_INFO_LEN);
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

uint8_t SpcData_GetCtrlType(void)
{
    SpcDataRom.bits.ctrType = 1;
    return (uint8_t) SpcDataRom.bits.ctrType;
}

bool SpcData_GetMaskRom(uint64_t *mask)
{
    if (mask == NULL) return false;

    memset(mask, 0, sizeof(uint64_t));
    memcpy(mask, &(SpcDataRom.SpcMaskRom), sizeof(uint64_t));
    return true;
}

bool SpcData_SetMaskRom(uint64_t *mask)
{
    if (mask == NULL) return false;

    memcpy(&(SpcDataRom.SpcMaskRom), mask, sizeof(uint64_t));
    return true;
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

bool SpcData_SetLowTemp(SpcTempConfig_t *lowtemp)
{
    if (lowtemp == NULL) return false;

    memcpy(&(SpcDataRom.SpcLowTemp), lowtemp, sizeof(SpcTempConfig_t));

    return true;
}

bool SpcData_GetLowTemp(SpcTempConfig_t *lowtemp)
{
    if (lowtemp == NULL) return false;

    memset(lowtemp, 0, sizeof(SpcTempConfig_t));
    memcpy(lowtemp, &(SpcDataRom.SpcLowTemp), sizeof(SpcTempConfig_t));

    return true;
}

bool SpcData_SetHighTemp(SpcTempConfig_t *hightemp)
{
    if (hightemp == NULL) return false;

    memcpy(&(SpcDataRom.SpcHighTemp), hightemp, sizeof(SpcTempConfig_t));

    return true;
}

bool SpcData_GetHighTemp(SpcTempConfig_t *hightemp)
{
    if (hightemp == NULL) return false;

    memset(hightemp, 0, sizeof(SpcTempConfig_t));
    memcpy(hightemp, &(SpcDataRom.SpcHighTemp), sizeof(SpcTempConfig_t));

    return true;
}

bool SpcData_SetDeadBand(SpcTempConfig_t *deadband)
{
    if (deadband == NULL) return false;

    memcpy(&(SpcDataRom.SpcDeadBand), deadband, sizeof(SpcTempConfig_t));

    return true;
}

bool SpcData_GetDeadBand(SpcTempConfig_t *deadband)
{
    if (deadband == NULL) return false;

    memset(deadband, 0, sizeof(SpcTempConfig_t));
    memcpy(deadband, &(SpcDataRom.SpcDeadBand), sizeof(SpcTempConfig_t));

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

    memcpy(&(SpcDataRom.SpcLowCurrent), lowcurrent, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetLowCurrent(SpcUint16Config_t *lowcurrent)
{
    if (lowcurrent == NULL) return false;

    memset(lowcurrent, 0, sizeof(SpcUint16Config_t));
    memcpy(lowcurrent, &(SpcDataRom.SpcLowCurrent), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetHighCurrent(SpcUint16Config_t *highcurrent)
{
    if (highcurrent == NULL) return false;

    memcpy(&(SpcDataRom.SpcHighCurrent), highcurrent, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetHighCurrent(SpcUint16Config_t *highcurrent)
{
    if (highcurrent == NULL) return false;

    memset(highcurrent, 0, sizeof(SpcUint16Config_t));
    memcpy(highcurrent, &(SpcDataRom.SpcHighCurrent), sizeof(SpcUint16Config_t));
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

    memcpy(&(SpcDataRom.SpcGFIAlarm), gfialarm, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetGFIAlarm(SpcUint16Config_t *gfialarm)
{
    if (gfialarm == NULL) return false;

    memset(gfialarm, 0, sizeof(SpcUint16Config_t));
    memcpy(gfialarm, &(SpcDataRom.SpcGFIAlarm), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetGFITrip(SpcUint16Config_t *gfitrip)
{
    if (gfitrip == NULL) return false;

    memcpy(&(SpcDataRom.SpcGFITrip), gfitrip, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetGFITrip(SpcUint16Config_t *gfitrip)
{
    if (gfitrip == NULL) return false;

    memset(gfitrip, 0, sizeof(SpcUint16Config_t));
    memcpy(gfitrip, &(SpcDataRom.SpcGFITrip), sizeof(SpcUint16Config_t));
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

    memcpy(&(SpcDataRom.SpcLowVoltage), lowvoltage, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetLowVoltage(SpcUint16Config_t *lowvoltage)
{
    if (lowvoltage == NULL) return false;

    memset(lowvoltage, 0, sizeof(SpcUint16Config_t));
    memcpy(lowvoltage, &(SpcDataRom.SpcLowVoltage), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetHighVoltage(SpcUint16Config_t *highvoltage)
{
    if (highvoltage == NULL) return false;

    memcpy(&(SpcDataRom.SpcHighVoltage), highvoltage, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetHighVoltage(SpcUint16Config_t *highvoltage)
{
    if (highvoltage == NULL) return false;

    memset(highvoltage, 0, sizeof(SpcUint16Config_t));
    memcpy(highvoltage, &(SpcDataRom.SpcHighVoltage), sizeof(SpcUint16Config_t));
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

    strncpy((char *)SpcDataRom.HeaterName, (char *)name, MAX_INFO_LEN);
    return true;
}

bool SpcData_GetHeaterName(uint8_t *name)
{
    if (name == NULL) return false;

    memset((char *)name, 0, MAX_INFO_LEN);
    strncpy((char *)name, (char *)SpcDataRom.HeaterName, MAX_INFO_LEN);
    return true;
}

bool SpcData_SetCurrentLimit(SpcUint16Config_t *currentlimit)
{
    if (currentlimit == NULL) return false;

    memcpy(&(SpcDataRom.SpcCurrentLimit), currentlimit, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetCurrentLimit(SpcUint16Config_t *currentlimit)
{
    if (currentlimit == NULL) return false;

    memset(currentlimit, 0, sizeof(SpcUint16Config_t));
    memcpy(currentlimit, &(SpcDataRom.SpcCurrentLimit), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetSoftStart(SpcUint16Config_t *softstart)
{
    if (softstart == NULL) return false;

    memcpy(&(SpcDataRom.SpcSoftStart), softstart, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetSoftStart(SpcUint16Config_t *softstart)
{
    if (softstart == NULL) return false;

    memset(softstart, 0, sizeof(SpcUint16Config_t));
    memcpy(softstart, &(SpcDataRom.SpcSoftStart), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetAutoTest(SpcUint16Config_t *autotest)
{
    if (autotest == NULL) return false;

    memcpy(&(SpcDataRom.SpcAutoTest), autotest, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetAutoTest(SpcUint16Config_t *autotest)
{
    if (autotest == NULL) return false;

    memset(autotest, 0, sizeof(SpcUint16Config_t));
    memcpy(autotest, &(SpcDataRom.SpcAutoTest), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetPowerPrice(SpcUint16Config_t *powerprice)
{
    if (powerprice == NULL) return false;

    memcpy(&(SpcDataRom.SpcPowerPrice), powerprice, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetPowerPrice(SpcUint16Config_t *powerprice)
{
    if (powerprice == NULL) return false;

    memset(powerprice, 0, sizeof(SpcUint16Config_t));
    memcpy(powerprice, &(SpcDataRom.SpcPowerPrice), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetTimeout(SpcUint16Config_t *timeout)
{
    if (timeout == NULL) return false;

    memcpy(&(SpcDataRom.SpcTimeout), timeout, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetTimeout(SpcUint16Config_t *timeout)
{
    if (timeout == NULL) return false;

    memset(timeout, 0, sizeof(SpcUint16Config_t));
    memcpy(timeout, &(SpcDataRom.SpcTimeout), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetScanSpeed(SpcUint16Config_t *scanspeed)
{
    if (scanspeed == NULL) return false;

    memcpy(&(SpcDataRom.SpcScanSpeed), scanspeed, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetScanSpeed(SpcUint16Config_t *scanspeed)
{
    if (scanspeed == NULL) return false;

    memset(scanspeed, 0, sizeof(SpcUint16Config_t));
    memcpy(scanspeed, &(SpcDataRom.SpcScanSpeed), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetModbusAddress(SpcUint16Config_t *modbusaddress)
{
    if (modbusaddress == NULL) return false;

    memcpy(&(SpcDataRom.SpcModbusAddress), modbusaddress, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetModbusAddress(SpcUint16Config_t *modbusaddress)
{
    if (modbusaddress == NULL) return false;

    memset(modbusaddress, 0, sizeof(SpcUint16Config_t));
    memcpy(modbusaddress, &(SpcDataRom.SpcModbusAddress), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetAlarmOutput(SpcUint16Config_t *alarmoutput)
{
    if (alarmoutput == NULL) return false;

    memcpy(&(SpcDataRom.SpcAlarmOutput), alarmoutput, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetAlarmOutput(SpcUint16Config_t *alarmoutput)
{
    if (alarmoutput == NULL) return false;

    memset(alarmoutput, 0, sizeof(SpcUint16Config_t));
    memcpy(alarmoutput, &(SpcDataRom.SpcAlarmOutput), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetHeaterTest(SpcUint16Config_t *heatertest)
{
    if (heatertest == NULL) return false;

    memcpy(&(SpcDataRom.SpcHeaterTest), heatertest, sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_GetHeaterTest(SpcUint16Config_t *heatertest)
{
    if (heatertest == NULL) return false;

    memset(heatertest, 0, sizeof(SpcUint16Config_t));
    memcpy(heatertest, &(SpcDataRom.SpcHeaterTest), sizeof(SpcUint16Config_t));
    return true;
}

bool SpcData_SetPassword(uint8_t *passwd)
{
    if (passwd == NULL) return false;

    strncpy((char *)SpcDataRom.Password, (char *)passwd, MAX_INFO_LEN);
    return true;
}

bool SpcData_GetPassword(uint8_t *passwd)
{
    if (passwd == NULL) return false;

    memset((char *)passwd, 0, MAX_INFO_LEN);
    strncpy((char *)passwd, (char *)SpcDataRom.Password, MAX_INFO_LEN);
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
