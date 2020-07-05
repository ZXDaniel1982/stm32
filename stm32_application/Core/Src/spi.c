#include <stddef.h>

#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

void SPI_Init()
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
    
#ifdef BOARD_ADV1
/*    NVIC_SetPriority(DMA1_Channel2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
    NVIC_EnableIRQ(DMA1_Channel2_IRQn);
    NVIC_SetPriority(DMA1_Channel3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
    NVIC_EnableIRQ(DMA1_Channel3_IRQn);*/
#endif
}

uint8_t SPI_Transmit(uint8_t *data, uint16_t size)
{
#if 0
    /* Disable the DMA1_3 peripheral */
    CLEAR_BIT(DMA1_Channel3->CCR, DMA_CCR_EN);
    
    /* Configure the source, destination address and the data length & clear flags*/
    WRITE_REG(DMA1->IFCR, DMA_ISR_TCIF3);
    WRITE_REG(DMA1_Channel3->CNDTR, size);
    WRITE_REG(DMA1_Channel3->CPAR, (uint32_t)SPI1->DR);
    WRITE_REG(DMA1_Channel3->CMAR, (uint32_t)data);
    
    CLEAR_BIT(DMA1_Channel3->CCR , DMA_CCR_HTIE);
    SET_BIT(DMA1_Channel3->CCR , (DMA_CCR_TCIE | DMA_CCR_TEIE));
    SET_BIT(DMA1_Channel3->CCR , DMA_CCR_EN);
    
    SET_BIT(SPI1->CR2, SPI_CR2_ERRIE);
    SET_BIT(SPI1->CR2, SPI_CR2_TXDMAEN);
#endif
    uint16_t i;
    __IO uint32_t tmpreg_ovr = 0x00U;
    
    if((data == NULL) || (size == 0U)) {
        return 0;
    }

    for (i=0;i<size;i++) {
        while (!(SPI1->SR & SPI_SR_TXE)) {}
        *((__IO uint8_t*) &(SPI1->DR)) = data[i];
    }

    while (!(SPI1->SR & SPI_SR_TXE)) {}
    while (SPI1->SR & SPI_SR_BSY) {}

    tmpreg_ovr = SPI1->DR;
    tmpreg_ovr = SPI1->SR;
    UNUSED(tmpreg_ovr);

    return 1;
}

uint8_t SPI_TransmitReceive(uint8_t *txData, uint8_t *rxData, uint16_t size)
{
#if 0
    //===============RX=====================================//
    /* Disable the DMA1_2 peripheral */
    CLEAR_BIT(DMA1_Channel2->CCR, DMA_CCR_EN);
    
    /* Configure the source, destination address and the data length & clear flags*/
    WRITE_REG(DMA1->IFCR, DMA_ISR_TCIF2);
    WRITE_REG(DMA1_Channel2->CNDTR, size);
    WRITE_REG(DMA1_Channel2->CPAR, (uint32_t)SPI1->DR);
    WRITE_REG(DMA1_Channel2->CMAR, (uint32_t)rxData);
    
    CLEAR_BIT(DMA1_Channel2->CCR , DMA_CCR_HTIE);
    SET_BIT(DMA1_Channel2->CCR , (DMA_CCR_TCIE | DMA_CCR_TEIE));
    SET_BIT(DMA1_Channel2->CCR , DMA_CCR_EN);
    
    SET_BIT(SPI1->CR2, SPI_CR2_RXDMAEN);
    
    //================TX=====================================//
    /* Disable the DMA1_3 peripheral */
    CLEAR_BIT(DMA1_Channel3->CCR, DMA_CCR_EN);
    
    /* Configure the source, destination address and the data length & clear flags*/
    WRITE_REG(DMA1->IFCR, DMA_ISR_TCIF3);
    WRITE_REG(DMA1_Channel3->CNDTR, size);
    WRITE_REG(DMA1_Channel3->CPAR, (uint32_t)SPI1->DR);
    WRITE_REG(DMA1_Channel3->CMAR, (uint32_t)txData);
    
    CLEAR_BIT(DMA1_Channel3->CCR , DMA_CCR_HTIE);
    SET_BIT(DMA1_Channel3->CCR , (DMA_CCR_TCIE | DMA_CCR_TEIE));
    SET_BIT(DMA1_Channel3->CCR , DMA_CCR_EN);
    
    SET_BIT(SPI1->CR2, SPI_CR2_ERRIE);
    SET_BIT(SPI1->CR2, SPI_CR2_TXDMAEN);
#endif
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
