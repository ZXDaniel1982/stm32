#include "engin.hpp"

SpcEngin::SpcEngin()
    :   iData           (std::make_shared<SpcData_t>())
    ,   iCurrentState   (std::make_shared<StateInit>())
{
    Update(Opt::Empty);
}

void
SpcEngin::Update(Opt aOpt)
{
    auto state = iCurrentState->Update(iData, aOpt);

    if (state) {
        iCurrentState = std::move(state);
    }
}
