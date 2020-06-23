#pragma once

#include "state.hpp"

const std::unordered_map<DataStatus, std::string> kDataStat = {
    {DataStatus::Short,     "RTD Short"},
    {DataStatus::Open,      "RTD Open"},
};

void ShowTemper(SpcTemperature_t, bool);
