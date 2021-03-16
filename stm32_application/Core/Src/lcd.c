/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdarg.h>

#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

#define Bank1_LCD_D    ((uint32_t)0x60020000)	//???????
#define Bank1_LCD_C    ((uint32_t)0x60000000)	//???????

#define LCD_LEN 240
#define LCD_WID 320
#define LCD_TOTAL ((uint32_t) LCD_LEN * LCD_WID)

#define LCD_CLR_COL ((LCD_LEN) / (LCD_CHAR_LEN))
#define LCD_CLR_ROW ((LCD_WID) / (LCD_CHAR_WID))

#define RED   0XF800
#define GREEN 0X07E0
#define BLUE  0X001F
#define BRED  0XF81F
#define GRED  0XFFE0
#define GBLUE 0X07FF
#define BLACK 0
#define WHITE 0xFFFF

//==============================================================================//
// Private functions
//==============================================================================//
static void LCD_WR_CMD(uint16_t index, uint16_t val)
{
	*(__IO uint16_t *) (Bank1_LCD_C) = index;
	*(__IO uint16_t *) (Bank1_LCD_D) = val;
}

static void lcd_rst(void)
{
	MODIFY_REG(LCD_Rst_GPIO_Port->ODR, LCD_Rst_Pin, 0);
	Delay1s();
	MODIFY_REG(LCD_Rst_GPIO_Port->ODR, LCD_Rst_Pin, LCD_Rst_Pin);
	Delay1s();

	MODIFY_REG(LCD_Light_GPIO_Port->ODR, LCD_Light_Pin, LCD_Light_Pin);
}

void LCD_WR_Data(uint16_t val)
{
	*(__IO uint16_t *) (Bank1_LCD_D) = val;
}

void LCD_WR_REG(uint16_t index)
{
	*(__IO uint16_t *) (Bank1_LCD_C) = index;
}

uint16_t LCD_RD_Data(void)
{
  uint16_t color = 0, a1 = 0, a2 = 0, a3 = 0;

  color = *(__IO uint16_t *) (Bank1_LCD_D);
  a1 = *(__IO uint16_t *) (Bank1_LCD_D);
  a2 = *(__IO uint16_t *) (Bank1_LCD_D);
  a3 = *(__IO uint16_t *) (Bank1_LCD_D);
  color = (uint16_t)((((a1>>11)&0x1f)<<11) |
                     (((a1>>2)&0x3f)<<5)  |
                     ((a2>>11)&0x1f));
  return color;
}

void LCD_Clear(void)
{
	uint32_t n;

	LCD_WR_CMD(0x02, 0x00);
	LCD_WR_CMD(0x03, 0x00);		//Column Start
	LCD_WR_CMD(0x04, (uint8_t) ((LCD_LEN - 1) >> 8));
	LCD_WR_CMD(0x05, (uint8_t) (LCD_LEN - 1));	//Column End

	LCD_WR_CMD(0x06, 0);
	LCD_WR_CMD(0x07, 0);		//Row Start
	LCD_WR_CMD(0x08, (uint8_t) ((LCD_WID - 1) >> 8));
	LCD_WR_CMD(0x09, (uint8_t) (LCD_WID - 1));	//Row End

	LCD_WR_REG(34);

	for (n = 0; n < LCD_TOTAL; n++)
		LCD_WR_Data(WHITE);		//????? 
}

void LCD_Init(void)
{
	unsigned int n;

	lcd_rst();

	LCD_WR_CMD(0xEA, 0x00);		//PTBA[15:8]
	LCD_WR_CMD(0xEB, 0x20);		//PTBA[7:0]
	LCD_WR_CMD(0xEC, 0x0C);		//STBA[15:8]
	LCD_WR_CMD(0xED, 0xC4);		//STBA[7:0]
	LCD_WR_CMD(0xE8, 0x38);		//OPON[7:0]
	LCD_WR_CMD(0xE9, 0x10);		//OPON1[7:0]
	LCD_WR_CMD(0xF1, 0x01);		//OTPS1B
	LCD_WR_CMD(0xF2, 0x10);		//GEN
	//Gamma 2.2 Setting
	LCD_WR_CMD(0x40, 0x01);		//
	LCD_WR_CMD(0x41, 0x00);		//
	LCD_WR_CMD(0x42, 0x00);		//
	LCD_WR_CMD(0x43, 0x10);		//
	LCD_WR_CMD(0x44, 0x0e);		//
	LCD_WR_CMD(0x45, 0x24);		//
	LCD_WR_CMD(0x46, 0x04);		//
	LCD_WR_CMD(0x47, 0x50);		//
	LCD_WR_CMD(0x48, 0x02);		//
	LCD_WR_CMD(0x49, 0x13);		//
	LCD_WR_CMD(0x4A, 0x19);		//
	LCD_WR_CMD(0x4B, 0x19);		//
	LCD_WR_CMD(0x4C, 0x16);		//
	LCD_WR_CMD(0x50, 0x1b);		//
	LCD_WR_CMD(0x51, 0x31);		//
	LCD_WR_CMD(0x52, 0x2f);		//
	LCD_WR_CMD(0x53, 0x3f);		//
	LCD_WR_CMD(0x54, 0x3f);		//
	LCD_WR_CMD(0x55, 0x3E);		//
	LCD_WR_CMD(0x56, 0x2f);		//
	LCD_WR_CMD(0x57, 0x7b);		//
	LCD_WR_CMD(0x58, 0x09);		//
	LCD_WR_CMD(0x59, 0x06);		//
	LCD_WR_CMD(0x5A, 0x06);		//
	LCD_WR_CMD(0x5B, 0x0c);		//
	LCD_WR_CMD(0x5C, 0x1d);		//
	LCD_WR_CMD(0x5D, 0xCC);		//

	//Power Voltage Setting
	LCD_WR_CMD(0x1B, 0x1B);
	LCD_WR_CMD(0x1A, 0x01);
	LCD_WR_CMD(0x24, 0x2f);
	LCD_WR_CMD(0x25, 0x57);
	//****VCOM offset**///
	LCD_WR_CMD(0x23, 0x88);
	//Power on Setting
	LCD_WR_CMD(0x18, 0x34);
	LCD_WR_CMD(0x19, 0x01);
	LCD_WR_CMD(0x01, 0x00);
	LCD_WR_CMD(0x1F, 0x88);
	Delay1s();
	LCD_WR_CMD(0x1F, 0x80);
	Delay1s();
	LCD_WR_CMD(0x1F, 0x90);
	Delay1s();
	LCD_WR_CMD(0x1F, 0xd0);
	Delay1s();
	LCD_WR_CMD(0x17, 0x05);
	//SET PANEL
	LCD_WR_CMD(0x36, 0x00);
	LCD_WR_CMD(0x28, 0x38);
	Delay1s();
	LCD_WR_CMD(0x28, 0x3f);
	LCD_WR_CMD(0x16, 0X18);
	LCD_WR_CMD(0x02, 0x00);
	LCD_WR_CMD(0x03, 0x00);
	LCD_WR_CMD(0x04, 0x00);
	LCD_WR_CMD(0x05, 0xEF);

	LCD_WR_CMD(0x06, 0x00);
	LCD_WR_CMD(0x07, 0x00);
	LCD_WR_CMD(0x08, 0x01);
	LCD_WR_CMD(0x09, 0x3F);

	LCD_WR_REG(34);
	for (n = 0; n < LCD_TOTAL; n++)
		LCD_WR_Data(WHITE);		//????? 

	//LCD_WR_CMD(0x16, 0x18|0x80|0x40);
}

void LCD_SetPixel(int x, int y, int color)
{
  uartprintf("%s : x(%d) y(%d) color(%x)\r\n", __func__, x, y, color);
	LCD_WR_CMD(0x02, (uint8_t)(x >> 8));
	LCD_WR_CMD(0x03, (uint8_t)x);		//Column Start

	LCD_WR_CMD(0x06, (uint8_t)(y >> 8));
	LCD_WR_CMD(0x07, (uint8_t)y);		//Row Start
	
  LCD_WR_REG(34);
  LCD_WR_Data(color);
}

int LCD_GetPixel(int x, int y)
{
  uint16_t color = 0;

  uartprintf("%s : x(%d) y(%d)\r\n", __func__, x, y);

	LCD_WR_CMD(0x02, (uint8_t)(x >> 8));
	LCD_WR_CMD(0x03, (uint8_t)x);		//Column Start

	LCD_WR_CMD(0x06, (uint8_t)(y >> 8));
	LCD_WR_CMD(0x07, (uint8_t)y);		//Row Start

  LCD_WR_REG(22);
  color = LCD_RD_Data();

  return color;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
