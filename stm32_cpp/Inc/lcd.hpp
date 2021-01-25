#pragma once

#include <stdint.h>
#include <logger.hpp>

class IOUT {
public:
    ~IOUT() = default;
    virtual void print(std::string) = 0;
    virtual std::shared_ptr<ILoggerHandle> CreateLogger() = 0;
};

class HX8347D
    : public IOUT {
private:
    class LcdLogger : public ILoggerHandle {
    public:
        LcdLogger(HX8347D& aDevice)
            : iDevice  (aDevice) {}

        void Write(std::string aInfo) {
            iDevice.print(aInfo);
        }
    private:
        HX8347D& iDevice;
    };
public:
    HX8347D();
public:
    void print(std::string) override;
    std::shared_ptr<ILoggerHandle> CreateLogger() override;
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
