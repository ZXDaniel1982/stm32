/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdarg.h>

#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

#define Bank1_LCD_D    ((uint32_t)0x60020000)
#define Bank1_LCD_C    ((uint32_t)0x60000000)

#define LCD_LEN 240
#define LCD_WID 320
#define LCD_TOTAL ((uint32_t) LCD_LEN * LCD_WID)

#define RED   0XF800
#define GREEN 0X07E0
#define BLUE  0X001F
#define BRED  0XF81F
#define GRED  0XFFE0
#define GBLUE 0X07FF
#define WHITE 0XFFFF
#define BLACK 0

//==============================================================================//
// Private functions
//==============================================================================//
static void LCD_WR_CMD(uint16_t index, uint16_t val)
{
	*(__IO uint16_t *) (Bank1_LCD_C) = index;
	*(__IO uint16_t *) (Bank1_LCD_D) = val;
}

static void LCD_WR_Data(uint16_t val)
{
	*(__IO uint16_t *) (Bank1_LCD_D) = val;
}

static void LCD_WR_REG(uint16_t index)
{
	*(__IO uint16_t *) (Bank1_LCD_C) = index;
}

static void lcd_rst(void)
{
	MODIFY_REG(LCD_Rst_GPIO_Port->ODR, LCD_Rst_Pin, 0);
	Delay1s();
	MODIFY_REG(LCD_Rst_GPIO_Port->ODR, LCD_Rst_Pin, LCD_Rst_Pin);
	Delay1s();

	MODIFY_REG(LCD_Light_GPIO_Port->ODR, LCD_Light_Pin, LCD_Light_Pin);
}

//==============================================================================//
// Public functions
//==============================================================================//
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
		LCD_WR_Data(WHITE);
}

void LCD_Init(void)
{
	uint32_t n;

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

void LCD_Fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t *color)
{
	uint16_t n;

	LCD_WR_CMD(0x02, (uint8_t) (x1 >> 8));
	LCD_WR_CMD(0x03, (uint8_t) x1);
	LCD_WR_CMD(0x04, (uint8_t) (x2 >> 8));
	LCD_WR_CMD(0x05, (uint8_t) x2);

	LCD_WR_CMD(0x06, (uint8_t) (y1 >> 8));
	LCD_WR_CMD(0x07, (uint8_t) y1);		//Row Start
	LCD_WR_CMD(0x08, (uint8_t) (y2 >> 8));
	LCD_WR_CMD(0x09, (uint8_t) y2);	//Row End

	LCD_WR_REG(34);

	for (n = 0; n < LCD_TOTAL; n++) {
		LCD_WR_Data(*(uint16_t *)color);
		color++;
	}
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
