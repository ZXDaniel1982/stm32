#include "helper.hpp"

void ShowTemper(SpcTemperature_t aTemp, bool Celsius)
{
    auto dataStatus = static_cast<DataStatus>(aTemp.status);

    cout << "Heater Temp" << endl;
    if (kDataStat.find(dataStatus) != kDataStat.end()) {
    } else {
        if (Celsius) {}
        else {}
    }
}