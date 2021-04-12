/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H
#define __USART_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void USART_SendData(uint8_t *data, uint16_t len);
void uartAssert(unsigned long ulLine, const char * const pcFileName);

#ifdef __cplusplus
}
#endif

#endif /* __USART_H */
