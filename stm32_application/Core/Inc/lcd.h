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
void LCD_WR_Data(uint16_t);
void LCD_WR_REG(uint16_t);
void LCD_SetPixel(int, int, int);
int LCD_GetPixel(int, int);

#ifdef __cplusplus
}
#endif

#endif /* __LCD_H */

