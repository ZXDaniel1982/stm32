#pragma once

#include <stdint.h>

class ILCD {
public:
    ~ILCD() = default;
    virtual void print(const char* fmt, ...) = 0;
};

class HX8347D
    : public ILCD {
public:
    HX8347D();
public:
    void print(const char* fmt, ...) override;
private:
    void lcd_rst();
    void LCD_Clear();
    void LCD_WR_CMD(unsigned int, unsigned int);
    void LCD_WR_Data(unsigned int);
    void LCD_WR_REG(unsigned int);
    void TFT_ShowString(uint8_t, uint16_t, const uint8_t *);
    void TFT_ShowChar(uint8_t, uint16_t, uint8_t);
private:
    uint16_t POINT_COLOR;
    uint16_t strIndex;
};
