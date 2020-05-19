#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

/*
 *   Remember how to use it
 *
 *   unsigned char SST25_buffer[4096];
 *   SST25_W_BLOCK(0, SST25_buffer,4096);  //将册数数据写入到SST25VF016B的0页里
 *   SST25_R_BLOCK(0, SST25_buffer,4096);  //从SST25VF016B的0页里读出数据
 */

/* Select SPI FLASH: ChipSelect pin low  */
#define Select_Flash()     MODIFY_REG(SST_CS_GPIO_Port->ODR, SST_CS_Pin, 0)
/* Deselect SPI FLASH: ChipSelect pin high */
#define NotSelect_Flash()  MODIFY_REG(SST_CS_GPIO_Port->ODR, SST_CS_Pin, SST_CS_Pin)

static void wip(void);
static void wsr(void);
static void wen(void);
static void wdis(void);
static uint8_t rdsr(void);
static uint16_t SPI_Flash_ReadID(void);
static void EEPRom_SendByte(uint8_t byte);

/*----------------------------------------------------------------------------*/
/* Private functions                                                           */
/*----------------------------------------------------------------------------*/
static void EEPRom_SendByte(uint8_t byte)
{
    uint8_t val = byte;
    SPI_Transmit(&val, 1);
}

static uint16_t SPI_Flash_ReadID(void)
{
    uint8_t Temp = 0;
    uint8_t Ret = 0;
    uint16_t id = 0;
    Select_Flash();

    //????ID??    
    Temp = 0xAB;
    SPI_TransmitReceive(&Temp, &Ret, 1);

    Temp = 0x00;
    SPI_TransmitReceive(&Temp, &Ret, 1);

    Temp = 0x00;
    SPI_TransmitReceive(&Temp, &Ret, 1);

    Temp = 0x00;
    SPI_TransmitReceive(&Temp, &Ret, 1);

    //?????16??    
    Temp = 0xFF;
    SPI_TransmitReceive(&Temp, &Ret, 1);
    id = ((uint16_t) Ret) << 8;

    Temp = 0xFF;
    SPI_TransmitReceive(&Temp, &Ret, 1);
    id += (uint16_t) Ret;

    NotSelect_Flash();

    return id;
}

static uint8_t rdsr(void)
{
    uint8_t busy;

    Select_Flash();
    EEPRom_SendByte(0x05);
    SPI_TransmitReceive(&busy, &busy, 1);
    NotSelect_Flash();
    return (busy);
}

static void wip(void)
{
    uint8_t a = 1;
    while ((a & 0x01) == 1) a = rdsr();
}

static void wsr(void)
{
    Select_Flash();
    EEPRom_SendByte(0x50);
    NotSelect_Flash();

    Select_Flash();
    EEPRom_SendByte(0x01);
    EEPRom_SendByte(0x00);
    NotSelect_Flash();

    wip();
}

static void wen(void)
{
    Select_Flash();
    EEPRom_SendByte(0x06);
    NotSelect_Flash();
}

static void wdis(void)
{
    Select_Flash();
    EEPRom_SendByte(0x04);
    NotSelect_Flash();

    wip();
}

void EEProm_SectorErrase(uint32_t addr)
{
    wsr();
    wen();

    Select_Flash();
    EEPRom_SendByte(0x20);
    EEPRom_SendByte((uint8_t) ((addr & 0xffffff) >> 16)); //addh
    EEPRom_SendByte((uint8_t) ((addr & 0xffff) >> 8));    //addl 
    EEPRom_SendByte((uint8_t) (addr & 0xff)); //wtt
    NotSelect_Flash();

    wip();
}

void EEPROM_Write(uint32_t addr, uint8_t * buf, uint16_t len)
{
    uint16_t i = 0, a2;

    wsr();
    wen();
    Select_Flash();
    EEPRom_SendByte(0xad);
    EEPRom_SendByte((uint8_t) ((addr & 0xffffff) >> 16));
    EEPRom_SendByte((uint8_t) ((addr & 0xffff) >> 8));
    EEPRom_SendByte((uint8_t) (addr & 0xff));
    EEPRom_SendByte(buf[0]);
    EEPRom_SendByte(buf[1]);
    NotSelect_Flash();

    i = 2;
    while (i < len) {
        a2 = 120;
        while (a2 > 0) a2--;

        Select_Flash();
        EEPRom_SendByte(0xad);
        EEPRom_SendByte(buf[i]);
        i++;
        EEPRom_SendByte(buf[i]);
        i++;
        NotSelect_Flash();
    }

    a2 = 100;
    while (a2 > 0) a2--;

    wdis();
    Select_Flash();
    wip();
}

void EEPROM_Read(uint32_t addr, uint8_t *buf, uint16_t len)
{
    uint16_t i = 0;

    Select_Flash();
    EEPRom_SendByte(0x0b);
    EEPRom_SendByte((uint8_t) ((addr & 0xffffff) >> 16));
    EEPRom_SendByte((uint8_t) ((addr & 0xffff) >> 8));
    EEPRom_SendByte((uint8_t) (addr & 0xff));
    EEPRom_SendByte(0);

    while (i < len) {
        SPI_TransmitReceive(&(buf[i]), &(buf[i]), 1);
        i++;
    }
    NotSelect_Flash();
}

/*----------------------------------------------------------------------------*/
/* Public functions                                                           */
/*----------------------------------------------------------------------------*/
#define EEPROM_ID 0xbf41
void EEPROM_Init()
{
    uint8_t i;
    for (i=0;i<5;++i) {
        if (EEPROM_ID == SPI_Flash_ReadID()) {
            tftprintf("EEPROM initaion success");
            return;
        }
    }
    tftprintf("EEPROM initaion failed");
}
