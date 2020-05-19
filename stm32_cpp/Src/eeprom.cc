#include "eeprom.hpp"
#include "stm32f1xx.h"
 
#define EEPROM_ID 0xbf41
SST25VF016B::SST25VF016B(
    std::shared_ptr<ISPI> aSpi,
    std::shared_ptr<ILCD> aLcd)
    :   iSpi   (aSpi)
    ,   iLcd   (aLcd)
{
    uint8_t i;
    for (i=0;i<5;++i) {
        if (EEPROM_ID == ReadID()) {
            aLcd->print("EEPROM initaion success");
            return;
        }
    }
    aLcd->print("EEPROM initaion failed");
}

void
SST25VF016B::Select_Flash()
{
    MODIFY_REG(GPIOA->ODR, GPIO_BSRR_BS4, 0);
}

void
SST25VF016B::NotSelect_Flash()
{
    MODIFY_REG(GPIOA->ODR, GPIO_BSRR_BS4, GPIO_BSRR_BS4);
}

uint16_t
SST25VF016B::ReadID()
{
    uint8_t Temp = 0;
    uint8_t Ret = 0;
    uint16_t id = 0;
    Select_Flash();

    //????ID??    
    Temp = 0xAB;
    iSpi->TransmitReceive(&Temp, &Ret, 1);

    Temp = 0x00;
    iSpi->TransmitReceive(&Temp, &Ret, 1);

    Temp = 0x00;
    iSpi->TransmitReceive(&Temp, &Ret, 1);

    Temp = 0x00;
    iSpi->TransmitReceive(&Temp, &Ret, 1);

    //?????16??    
    Temp = 0xFF;
    iSpi->TransmitReceive(&Temp, &Ret, 1);
    id = ((uint16_t) Ret) << 8;

    Temp = 0xFF;
    iSpi->TransmitReceive(&Temp, &Ret, 1);
    id += (uint16_t) Ret;

    NotSelect_Flash();

    return id;
}
