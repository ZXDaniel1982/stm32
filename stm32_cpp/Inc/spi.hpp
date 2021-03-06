#pragma once

#include <stdint.h>
#include <cstddef>

class ISPI {
public:
    ~ISPI() = default;
    virtual uint8_t Transmit(uint8_t *, uint16_t) = 0;
    virtual uint8_t TransmitReceive(uint8_t *, uint8_t *, uint16_t) = 0;
};

class STM32F103VET_SPI
    : public ISPI {
public:
    STM32F103VET_SPI();
public:
	uint8_t Transmit(uint8_t *, uint16_t) override;
    uint8_t TransmitReceive(uint8_t *, uint8_t *, uint16_t) override;
}; 
