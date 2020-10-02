#pragma once

#include <memory>
#include "lcd.hpp"
#include "spi.hpp"

class SST25VF016B {
public:
    SST25VF016B(
        std::shared_ptr<ISPI>,
        std::shared_ptr<IDeviceLogger>);
private:
    void Select_Flash();
    void NotSelect_Flash();
    uint16_t ReadID();
private:
    std::shared_ptr<ISPI>  iSpi;
};
