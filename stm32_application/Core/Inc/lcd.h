/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LCD_H
#define __LCD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// LCD
void LCD_Init(void);
void LCD_Clear(void);
void LCD_Fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t *color);

#ifdef __cplusplus
}
#endif

#endif /* __LCD_H */