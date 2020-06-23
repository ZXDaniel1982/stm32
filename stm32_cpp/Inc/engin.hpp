#pragma once

#include "state.hpp"

class IEngine
{
public:
    virtual ~IEngine() = default;
    virtual void Update(Opt) = 0;
};

class SpcEngin : public IEngine {
public:
    SpcEngin();
public:
    void Update(Opt) override;
private:
    std::shared_ptr<SpcData_t>      iData;
    std::shared_ptr<IState>         iCurrentState;
};
