#pragma once

class ITIMER {
public:
    ~ITIMER() = default;
};

class STM32F103VET_TIMER
    : public ITIMER {
public:
    STM32F103VET_TIMER();
}; 