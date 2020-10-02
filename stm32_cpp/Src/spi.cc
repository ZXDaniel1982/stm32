#include "spi.hpp"
#include "stm32f1xx.h"
#include "common.h"

STM32F103VET_SPI::STM32F103VET_SPI()
{
    /* Disble the selected SPI peripheral */
    SPI1->CR1 &= (~SPI_CR1_SPE);

    /*----------------------- SPIx CR1 & CR2 Configuration ---------------------*/
    /* Configure : SPI Mode, Communication Mode, Data size, Clock polarity and phase, NSS management,
        Communication speed, First bit and CRC calculation state */
    MODIFY_REG(SPI1->CR1, (SPI_CR1_CPHA | SPI_CR1_CPOL | SPI_CR1_MSTR | SPI_CR1_BR | SPI_CR1_LSBFIRST |
                SPI_CR1_SSI | SPI_CR1_SSM | SPI_CR1_RXONLY | SPI_CR1_DFF | SPI_CR1_CRCNEXT |
                SPI_CR1_CRCEN | SPI_CR1_BIDIOE | SPI_CR1_BIDIMODE),
                (SPI_CR1_MSTR | SPI_CR1_SSI | SPI_CR1_CPOL | SPI_CR1_CPHA | SPI_CR1_SSM | SPI_CR1_BR_1 |
                SPI_CR1_BR_0));

    /* Configure : NSS management */
    MODIFY_REG(SPI1->CR2, SPI_CR2_SSOE, (SPI_CR1_SSM >> 16U));

    CLEAR_BIT(SPI1->I2SCFGR, SPI_I2SCFGR_I2SMOD);

    /* Enable SPI peripheral */
    SPI1->CR1 |= SPI_CR1_SPE;
}

uint16_t
STM32F103VET_SPI::TransmitReceive(uint8_t *txData, uint8_t *rxData, uint16_t size)
{
    if((txData == NULL) || (rxData == NULL ) || (size == 0U)) {
        return 0;
    }

    uint16_t i;
    for (i=0;i<size;i++) {
        while (!(SPI1->SR & SPI_SR_TXE)) {}
        *((__IO uint8_t*) &(SPI1->DR)) = txData[i];

        while (!(SPI1->SR & SPI_SR_RXNE)) {}
        rxData[i] = SPI1->DR;
    }

    while (!(SPI1->SR & SPI_SR_TXE)) {}
    while (SPI1->SR & SPI_SR_BSY) {}

    __IO uint32_t tmpreg_ovr = 0x00U;
    tmpreg_ovr = SPI1->DR;
    tmpreg_ovr = SPI1->SR;
    UNUSED(tmpreg_ovr);

    return 1;
}
