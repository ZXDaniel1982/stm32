#pragma once

#include <memory>
#include <functional>
#include <iostream>
#include "data.hpp"

using namespace std;

const std::unordered_map<RdtStat, std::string>  kRdtStat = {
    {RdtStat::Off,    "Heater is Off"},
    {RdtStat::On,     "Heater is On"},
    {RdtStat::ManOff, "Heater is ManOn"},
    {RdtStat::ManOn,  "Heater is ManOff"},
};

class IState
{
public:
    virtual ~IState() = default;
    virtual std::shared_ptr<IState> Update(std::shared_ptr<SpcData_t>, Opt) = 0;
};

class StateInit : public IState {
public:
    std::shared_ptr<IState> Update(std::shared_ptr<SpcData_t>, Opt) override;
};

class StateDefStatus : public IState {
public:
    StateDefStatus(std::shared_ptr<SpcData_t>, DefInfo);
public:
    std::shared_ptr<IState> Update(std::shared_ptr<SpcData_t>, Opt) override;
private:
    DefInfo                     iDefInfo;
    std::unordered_map<DefInfo, std::function<void()>>     iInterFuncs;
    std::unordered_map<Opt, std::function<std::shared_ptr<IState>(const Opt&)>>     iExtFuncs;
private:
    const std::string           iTitle = std::string("Actual");
};

class StateActual : public IState {
public:
    StateActual(std::shared_ptr<SpcData_t>, DefInfo);
public:
    std::shared_ptr<IState> Update(std::shared_ptr<SpcData_t>, Opt) override;
};
