#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

#if 0
void DMA_Init()
{
	MODIFY_REG(DMA1_Channel2->CCR,
			   (DMA_CCR_DIR | DMA_CCR_MEM2MEM | DMA_CCR_PL | DMA_CCR_CIRC |
				DMA_CCR_PINC | DMA_CCR_MINC | DMA_CCR_PSIZE | DMA_CCR_MSIZE),
			   (DMA_CCR_MINC));
	MODIFY_REG(DMA1_Channel3->CCR,
			   (DMA_CCR_DIR | DMA_CCR_MEM2MEM | DMA_CCR_PL | DMA_CCR_CIRC |
				DMA_CCR_PINC | DMA_CCR_MINC | DMA_CCR_PSIZE | DMA_CCR_MSIZE),
			   (DMA_CCR_DIR | DMA_CCR_MINC));
}

void DMA1_Channel2_IRQHandler(void)
{
	if (DMA1_Channel2->CCR & DMA_CCR_TCIE) {
		if (!(DMA1_Channel2->CCR & DMA_CCR_CIRC)) {
			CLEAR_BIT(DMA1_Channel2->CCR, (DMA_CCR_TEIE | DMA_CCR_TCIE));
			DMA1->IFCR = DMA_ISR_TCIF2;

			CLEAR_BIT(SPI1->CR2, SPI_CR2_ERRIE);
			while (SPI1->SR & SPI_SR_BSY);
			CLEAR_BIT(SPI1->CR2, SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);
		}
	} else if (DMA1_Channel2->CCR & DMA_CCR_TEIE) {
		CLEAR_BIT(DMA1_Channel2->CCR,
				  (DMA_CCR_TCIE | DMA_CCR_HTIE | DMA_CCR_TEIE));
		CLEAR_BIT(SPI1->CR2, SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);
	}
}

void DMA1_Channel3_IRQHandler(void)
{
	__IO uint32_t tmpreg_ovr = 0x00U;

	if (DMA1_Channel2->CCR & DMA_CCR_TCIE) {
		if (!(DMA1_Channel2->CCR & DMA_CCR_CIRC)) {
			CLEAR_BIT(DMA1_Channel2->CCR, (DMA_CCR_TEIE | DMA_CCR_TCIE));
			DMA1->IFCR = DMA_ISR_TCIF3;

			CLEAR_BIT(SPI1->CR2, SPI_CR2_ERRIE);
			CLEAR_BIT(SPI1->CR2, SPI_CR2_TXDMAEN);
			while (SPI1->SR & SPI_SR_BSY);

			tmpreg_ovr = SPI1->DR;
			tmpreg_ovr = SPI1->SR;
			UNUSED(tmpreg_ovr);
		}
	} else if (DMA1_Channel2->CCR & DMA_CCR_TEIE) {
		CLEAR_BIT(DMA1_Channel2->CCR,
				  (DMA_CCR_TCIE | DMA_CCR_HTIE | DMA_CCR_TEIE));
		CLEAR_BIT(SPI1->CR2, SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);
	}
}
#endif
