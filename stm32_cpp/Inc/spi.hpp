#pragma once

#include <stdint.h>
#include <cstddef>

class ISPI {
public:
    ~ISPI() = default;
    virtual uint16_t TransmitReceive(uint8_t *, uint8_t *, uint16_t) = 0;
};

class STM32F103VET_SPI
    : public ISPI {
public:
    STM32F103VET_SPI();
public:
    uint16_t TransmitReceive(uint8_t *, uint8_t *, uint16_t) override;
}; 
