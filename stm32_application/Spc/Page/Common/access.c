#include "spc.h"

bool MaintainIsNone()
{
    SpcTempConfig_t maintain = {0};

    if (SpcData_GetMaintain(&maintain)) {
        if (maintain.status == NONE) return true;
    }
    return false;
}

bool MaintainIsOff()
{
    SpcTempConfig_t maintain = {0};

    if (SpcData_GetMaintain(&maintain)) {
        if (maintain.status == OFF) return true;
    }
    return false;
}

bool MenuIsNotAdvance()
{
    if (SpcData_GetAdvance()) {
        return false;
    }
    return true;
}

bool ControlIsProport()
{
    if (SpcData_GetCtrlType()) {
        return true;
    }
    return false;
}

bool HeaterIsSelfRegular()
{
    if (SpcData_GetHeaterType()) {
        return true;
    }
    return false;
}
