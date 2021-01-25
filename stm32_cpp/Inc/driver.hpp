 
#pragma once

#include <memory>
#include <list>
#include <unordered_set>
#include "lcd.hpp"
#include "sd.hpp"
#include "spi.hpp"
#include "timer.hpp"
#include "eeprom.hpp"
#include "common.h"

struct GPIOConfig {
    uint32_t clear;
    uint32_t set;
};

class STM32F103VET_RCC {
public:
    STM32F103VET_RCC();
};

class STM32F103VET_IO {
public:
    STM32F103VET_IO();
};

class STM32F103VET_USART {
public:
    STM32F103VET_USART();
};

class STM32F103VET_FSMC {
public:
    STM32F103VET_FSMC();
};

class HardwareDriver {
public:
    ~HardwareDriver() = default;
};

class STM32F103VET
    : public HardwareDriver {
public:
    STM32F103VET(std::shared_ptr<IDeviceLogger>);
private:
    std::unique_ptr<STM32F103VET_RCC>      iRCC;
    std::unique_ptr<STM32F103VET_IO>       iIO;
    std::unique_ptr<STM32F103VET_USART>    iUsart;
    std::shared_ptr<STM32F103VET_SPI>      iSpi;
    std::unique_ptr<STM32F103VET_FSMC>     iFSMC;
    std::shared_ptr<HX8347D>               iLcd;
    std::unique_ptr<STM32F103VET_SD>       iSd;
    std::unique_ptr<SST25VF016B>           iEEPROM;
    std::unique_ptr<STM32F103VET_TIMER>    iTimer;
};
