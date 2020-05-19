#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>

#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

#define USART_MAX_LEN 255

uint8_t UsartTxBuf[USART_MAX_LEN] = {0};

uint8_t txBuf[USART_MAX_LEN] = {0};
uint8_t rxBuf[USART_MAX_LEN] = {0};
uint8_t rxCnt = 0;

void USART_Init()
{
    if (READ_BIT(USART1->CR1, USART_CR1_UE) != (USART_CR1_UE)) {
        MODIFY_REG(USART1->CR1,
               (USART_CR1_M | USART_CR1_PCE | USART_CR1_PS | USART_CR1_TE | USART_CR1_RE),
               (USART_CR1_TE |USART_CR1_RE));

        MODIFY_REG(USART1->CR2, USART_CR2_STOP, 0);

        MODIFY_REG(USART1->CR3, USART_CR3_RTSE | USART_CR3_CTSE, 0);

        USART1->BRR = 0x271;
    }

    CLEAR_BIT(USART1->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
    CLEAR_BIT(USART1->CR3, (USART_CR3_SCEN | USART_CR3_IREN | USART_CR3_HDSEL));

    USART1->CR1 |= USART_CR1_UE;
}

void USART_RxProcess(uint8_t val)
{
    if (rxCnt >= USART_MAX_LEN) {
        memset(rxBuf, 0, USART_MAX_LEN);
        rxCnt = 0;
    }

    if ((val == 0x7f) || (val == 0x08)) {
        if (rxCnt == 0) return;
        rxBuf[rxCnt-1] = '\0';
        rxCnt--;
			  uartprintf("\b \b");
    } else if (val == 0x0d) {
			  uartprintf("\r\n");
        execute_command(rxBuf);
        memset(rxBuf, 0, USART_MAX_LEN);
        rxCnt = 0;
			  uartprintf("\r\nstm32 > ");
    } else {
        rxBuf[rxCnt] = val;
        rxCnt++;
			  USART_SendData(&val, 1);
    }
}

void USART_SendData(uint8_t *data, uint16_t len)
{
    uint16_t i;

    for (i=0;i<len;i++) {
        while ((USART1->SR &USART_SR_TXE) == 0) {}
        USART1->DR= data[i]; 
    }
}

void uartprintf(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);

    memset(UsartTxBuf, 0, USART_MAX_LEN);
    vsnprintf((char *)UsartTxBuf, USART_MAX_LEN, fmt, ap);
    
    USART_SendData(UsartTxBuf,strlen((char *)UsartTxBuf));
}
