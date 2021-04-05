#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>

#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"


SemaphoreHandle_t UartMutex;
xQueueHandle UartQueue;

//======================================================================//
// Private functions
//======================================================================//
static void USART_SpcCmd(uint8_t val)
{
	xQueueSendFromISR(UartQueue, &val, pdFALSE);
}

void USART_Init()
{
	if (READ_BIT(USART1->CR1, USART_CR1_UE) != (USART_CR1_UE)) {
		MODIFY_REG(USART1->CR1,
				   (USART_CR1_M | USART_CR1_PCE | USART_CR1_PS | USART_CR1_TE |
					USART_CR1_RE), (USART_CR1_TE | USART_CR1_RE));

		MODIFY_REG(USART1->CR2, USART_CR2_STOP, 0);

		MODIFY_REG(USART1->CR3, USART_CR3_RTSE | USART_CR3_CTSE, 0);

		USART1->BRR = 0x271;
	}

	CLEAR_BIT(USART1->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
	CLEAR_BIT(USART1->CR3, (USART_CR3_SCEN | USART_CR3_IREN | USART_CR3_HDSEL));

	SET_BIT(USART1->CR1, USART_CR1_UE);
	SET_BIT(USART1->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));

	NVIC_EnableIRQ(USART1_IRQn);
  NVIC_SetPriority(USART1_IRQn, 5);

  UartQueue = xQueueCreate(1, sizeof(uint8_t));
	UartMutex = xSemaphoreCreateMutex();
}

void USART_SendData(uint8_t * data, uint16_t len)
{
	uint16_t i;

	for (i = 0; i < len; i++) {
		while ((USART1->SR & USART_SR_TXE) == 0) {}
		USART1->DR = data[i];
	}
}

void USART1_IRQHandler(void)
{
	uint8_t buf;

	if ((USART1->SR & USART_CR1_RXNEIE) != 0) {
		buf = USART1->DR;
		USART_SpcCmd(buf);
	}
}

//==============================================================================//
// Public functions
//==============================================================================//
int uartprintf(const char *fmt, ...)
{
	uint8_t cmd[255] = { 0 };

	xSemaphoreTake(UartMutex, portMAX_DELAY);

	va_list ap;

	va_start(ap, fmt);
	vsnprintf((char *) cmd, sizeof(cmd), fmt, ap);

	USART_SendData(cmd, strlen((char *) cmd));
	va_end(ap);

	xSemaphoreGive(UartMutex);

	return 0;
}
