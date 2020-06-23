#include "state.hpp"
#include "helper.hpp"

// Init state
std::shared_ptr<IState>
StateInit::Update(
    std::shared_ptr<SpcData_t>      aData,
    Opt                             aOpt)
{
    auto mod = static_cast<DefInfo>(aData->config.system.bytes.defInfo);
    return std::make_shared<StateDefStatus>(aData, mod);
}

// Show default info
StateDefStatus::StateDefStatus(
    std::shared_ptr<SpcData_t>      aData,
    DefInfo                         aDefInfo)
    : iDefInfo      (aDefInfo)
{
    // Internal action
    iInterFuncs.try_emplace(DefInfo::SysStatus, [&]() {
    });
    iInterFuncs.try_emplace(DefInfo::HeaterStatus, [&]() {
        auto rdtStat = static_cast<RdtStat>(aData->config.system.bytes.rdtStat);
    });
    iInterFuncs.try_emplace(DefInfo::HeaterTemp, [&]() {
        auto unit = static_cast<bool>(aData->config.system.bytes.unit);
        ShowTemper(aData->config.MaintainTemp, unit);
    });

    // External action
    iExtFuncs.try_emplace(Opt::Empty, [&](const Opt& aOpt)->std::shared_ptr<IState> {
        if (aOpt == Opt::Empty) {
            if (iInterFuncs.find(iDefInfo) != iInterFuncs.end()) {
                auto func = iInterFuncs.at(iDefInfo);
                if (func) func();
            }
        }
        return {};
    });
    iExtFuncs.try_emplace(Opt::Actual, [&](const Opt& aOpt)->std::shared_ptr<IState> {
        if (aOpt == Opt::Actual) {
            return std::make_shared<StateActual>(aData, iDefInfo);
        }
        return {};
    });
    Update(aData, Opt::Empty);
}

std::shared_ptr<IState>
StateDefStatus::Update(
    std::shared_ptr<SpcData_t>      aData,
    Opt                             aOpt)
{
    if (iExtFuncs.find(aOpt) != iExtFuncs.end()) {
        auto func = iExtFuncs.at(aOpt);
        return func(aOpt);
    }
    return {};
}

// Actual
StateActual::StateActual(
    std::shared_ptr<SpcData_t>      aData,
    DefInfo                         aDefInfo)
{}

std::shared_ptr<IState>
StateActual::Update(
    std::shared_ptr<SpcData_t>      aData,
    Opt                             aOpt)
{
    return {};
}
