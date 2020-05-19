#include <string.h>
#include <stdlib.h>

#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "sdio.h"
#include "common.h"

#define BOOTARGS_ADDR          (0)

#define EEPROM_PAGE_SIZE       (4096)
#define IMAGE_EEP_ARGS_ADDR    (EEPROM_PAGE_SIZE)
#define IMAGE_EEPROM_ADDR      (IMAGE_EEP_ARGS_ADDR + EEPROM_PAGE_SIZE)

#define SDCARD_PAGE_SIZE       (512)
#define IMAGE_SDCARD_ARGS_ADDR (0)
#define IMAGE_SDCARD_ADDR      (IMAGE_SDCARD_ARGS_ADDR + SDCARD_PAGE_SIZE)

#define BOOTARGS_HEADER        (0x4455)
#define BOOTARGS_TAIL          (0x5566)
#define IMAGEARGS_HEADER       (0x2233)
#define IMAGEARGS_TAIL         (0x8899)

#define IMAGE_BUFFER_SIZE      (512)

static Bootargs_t Bootargs;

static uint8_t ImageBuf[IMAGE_BUFFER_SIZE];

static pFunction JumpToApplication;
static uint32_t JumpAddress;

static void boot_printenv(uint8_t *command);
static void boot_setenv(uint8_t *command);
static void boot_saveenv(uint8_t *command);
static void boot_backup(uint8_t *command);
static BootState_t GetImageInfo(Imageargs_t *iargs, uint8_t *src);
static void ImageCopyEepToFlash(void);
static void ImageCopySdToFlash(void);
static void ImageCopySdToEep(void);

static const cmdType_t commands[] = {
    {"printenv", boot_printenv},
    {"setenv",   boot_setenv},
    {"saveenv",  boot_saveenv},
    {"backup",   boot_backup},
    {"bootm",    bootm}
};

//==================================================================================
// Private functions
//==================================================================================
static void boot_printenv(uint8_t *command)
{
    uartprintf("ImageSrcConfig=%s\r\n", Bootargs.confSrc);
    uartprintf("ImageSrcState=%s\r\n",  Bootargs.statSrc);
    uartprintf("ImageVersion=%d\r\n",   Bootargs.version);
}

static void boot_setenv(uint8_t *command)
{
    uint8_t *name = NULL;
    uint8_t *val = NULL;

    if (command == NULL) {
        uartprintf("Not a valid command\r\n");
        return;
    }
    
    name = (uint8_t *)strtok((char *)command, " ");
    if (name == NULL) {
        uartprintf("Please provide a command\r\n");
        return;
    }
    
    name = (uint8_t *)strtok(NULL, " ");
    if (name == NULL) {
        uartprintf("Please provide a parameter name\r\n");
        return;
    }
    
    val = (uint8_t *)strtok(NULL, " ");
    if (val == NULL) {
        uartprintf("Please provide a value\r\n");
        return;
    }

    if (strcmp((char *)name, "ImageSrcConfig") == 0) {
        strcpy((char *)Bootargs.confSrc, (char *)val);
    } else if (strcmp((char *)name, "ImageSrcState") == 0) {
        strcpy((char *)Bootargs.statSrc, (char *)val);
    } else if (strcmp((char *)name, "ImageVersion") == 0) {
        Bootargs.version = atoi((char *)val);
    } else {
        uartprintf("Not a valid parameter\r\n");
        return;
    }
    
    return;
}

static void boot_saveenv(uint8_t *command)
{
    EEProm_SectorErrase(BOOTARGS_ADDR);
    EEPROM_Write(BOOTARGS_ADDR, (uint8_t *) &Bootargs, sizeof(Bootargs_t));
    return;
}

static void boot_backup(uint8_t *command)
{
    Imageargs_t iargs;
    if (GetImageInfo(&iargs, "SD") == STM32_SUCCESS) {
        ImageCopySdToEep();
    } else {
        uartprintf("Could not find valid image at SD\r\n");
    }
    return;
}

static BootState_t GetImageInfo(Imageargs_t *iargs, uint8_t *src)
{
    if (NULL == iargs)
        return STM32_FALSE;

    memset(iargs, 0, sizeof(Imageargs_t));
    if (strcmp((char *)src, "EEPROM") == 0) { // read version from eeprom
        EEPROM_Read(IMAGE_EEP_ARGS_ADDR, (uint8_t *) iargs, sizeof(Imageargs_t));
        if ((IMAGEARGS_HEADER == iargs->header) &&
            (IMAGEARGS_TAIL == iargs->tail)) {
            return STM32_SUCCESS;
        } else {
            return STM32_FALSE;
        }
    } else { // read version from sd card
        memset(ImageBuf, 0, IMAGE_BUFFER_SIZE);
        if (SD_ReadBlock((uint32_t *)ImageBuf, IMAGE_SDCARD_ARGS_ADDR, IMAGE_BUFFER_SIZE) == SD_OK) {
                    memcpy(iargs, ImageBuf, sizeof(Imageargs_t));

            if ((IMAGEARGS_HEADER == iargs->header) &&
                (IMAGEARGS_TAIL == iargs->tail)) {
                return STM32_SUCCESS;
            } else {
                return STM32_FALSE;
            }
        } else {
                      uartprintf("Read SD Block fail\r\n");
            return STM32_FALSE;
        }
    }
}

static void ImageCopyEepToFlash()
{
    Imageargs_t iargs;
    uint32_t eepAddr = IMAGE_EEPROM_ADDR;
    uint32_t flashAddr = APP_DEFAULT_ADD;
    uint32_t size;

      uartprintf("\r\nCopying Image from EEPROM to Flash ...\r\n");
    if (GetImageInfo(&iargs, "EEPROM") == STM32_SUCCESS) {
        size = iargs.size;

        while (size > 0) {
            if ((flashAddr % FLASH_PAGE_SIZE) == 0) {
                FLASH_Erase(flashAddr);
            }

            memset(ImageBuf, 0xff, IMAGE_BUFFER_SIZE);
            EEPROM_Read(eepAddr, ImageBuf, IMAGE_BUFFER_SIZE);
            FLASH_Program((uint8_t *)flashAddr, ImageBuf, IMAGE_BUFFER_SIZE);

            eepAddr += IMAGE_BUFFER_SIZE;
            flashAddr += IMAGE_BUFFER_SIZE;

            if (size < IMAGE_BUFFER_SIZE) {
                size = 0;
            } else {
                size -= IMAGE_BUFFER_SIZE;
            }
        }
    } else {
        uartprintf("Could not find valid image at EEPROM\r\n");
    }
    return;
}

static void ImageCopySdToFlash()
{
    Imageargs_t iargs;
    uint32_t sdAddr = IMAGE_SDCARD_ADDR;
    uint32_t flashAddr = APP_DEFAULT_ADD;
    uint32_t size;

      uartprintf("\r\nCopying Image from SD to Flash ...\r\n");
      FLASH_Unlock();
    if (GetImageInfo(&iargs, "SD") == STM32_SUCCESS) {
        size = iargs.size;

        while (size > 0) {
            if ((flashAddr % FLASH_PAGE_SIZE) == 0) {
                FLASH_Erase(flashAddr);
            }

            memset(ImageBuf, 0xff, IMAGE_BUFFER_SIZE);
            SD_ReadBlock((uint32_t *)ImageBuf, sdAddr, IMAGE_BUFFER_SIZE);
            FLASH_Program((uint8_t *)flashAddr, ImageBuf, IMAGE_BUFFER_SIZE);

            sdAddr += IMAGE_BUFFER_SIZE;
            flashAddr += IMAGE_BUFFER_SIZE;

            if (size < IMAGE_BUFFER_SIZE) {
                size = 0;
            } else {
                size -= IMAGE_BUFFER_SIZE;
            }
        }
    } else {
        uartprintf("Could not find valid image at SD\r\n");
    }
        FLASH_Lock();
    return;
}

static void ImageCopySdToEep()
{
    Imageargs_t iargs;
    uint32_t sdAddr = IMAGE_SDCARD_ADDR;
    uint32_t eepAddr = IMAGE_EEPROM_ADDR;
    uint32_t size;
    
      uartprintf("\r\nCopying Image from SD to EEPROM ...\r\n");
    if (GetImageInfo(&iargs, "SD") == STM32_SUCCESS) {
        EEProm_SectorErrase(IMAGE_EEP_ARGS_ADDR);
        EEPROM_Write(IMAGE_EEP_ARGS_ADDR, (uint8_t *) &iargs, sizeof(Imageargs_t));

        size = iargs.size;

        while (size > 0) {
            if ((eepAddr % EEPROM_PAGE_SIZE) == 0) {
                EEProm_SectorErrase(eepAddr);
            }

            memset(ImageBuf, 0xff, IMAGE_BUFFER_SIZE);
            SD_ReadBlock((uint32_t *)ImageBuf, sdAddr, IMAGE_BUFFER_SIZE);
            EEPROM_Write(eepAddr, (uint8_t *) ImageBuf, IMAGE_BUFFER_SIZE);

            sdAddr += IMAGE_BUFFER_SIZE;
            eepAddr += IMAGE_BUFFER_SIZE;

            if (size < IMAGE_BUFFER_SIZE) {
                size = 0;
            } else {
                size -= IMAGE_BUFFER_SIZE;
            }
        }
    } else {
        uartprintf("Could not find valid image at SD\r\n");
    }
    return;
}

//==================================================================================
// Public functions
//==================================================================================
void BootargsInit()
{
    memset(&Bootargs, 0, sizeof(Bootargs_t));
}

#define autoboot_delay(x) do {for (x=0;x<72000;++x);} while(0)
BootState_t autoboot()
{
    uint8_t buf = 0;
    uint8_t count = 6;
    uint8_t i;
      uint32_t j;

    buf = count + 0x30;
    USART_SendData(&buf, 1);

    while (count > 0) {
        for (i = 0; i < 100; ++i) {
            if((USART1->SR & USART_CR1_RXNEIE) != 0) {
                buf = USART1->DR;
                uartprintf("\r\n");
                return STM32_FALSE;
            }
            autoboot_delay(j);
        }

        count--;
        uartprintf("\b%d", count);
    }
    uartprintf("\r\n");
    return STM32_SUCCESS;
}

void GetBootargFromDefault()
{
    Bootargs.header = BOOTARGS_HEADER;
    Bootargs.tail = BOOTARGS_TAIL;

    Bootargs.version = 0;
    strcpy((char *)Bootargs.confSrc, "NULL");
    strcpy((char *)Bootargs.statSrc, "NULL");
}

BootState_t GetBootargFromEEP()
{
    EEPROM_Read(BOOTARGS_ADDR, (uint8_t *) &Bootargs, sizeof(Bootargs_t));

    if ((BOOTARGS_HEADER == Bootargs.header) &&
        (BOOTARGS_TAIL == Bootargs.tail)) {
        return STM32_SUCCESS;
    } else {
        BootargsInit();
        return STM32_FALSE;
    }
}

void bootm(uint8_t *command)
{
    Imageargs_t iargs;
      uartprintf("\r\nBooting Image from (%s) ...\r\n", (char *)Bootargs.confSrc);
    memset(&iargs, 0, sizeof(Imageargs_t));
    if (strcmp((char *)Bootargs.confSrc, (char *)Bootargs.statSrc) == 0) {
        if ((strcmp((char *)Bootargs.confSrc, "EEPROM") == 0) ||
            (strcmp((char *)Bootargs.confSrc, "SD") == 0)) {
            if (GetImageInfo(&iargs, (uint8_t *)Bootargs.confSrc) == STM32_SUCCESS) {
                if (Bootargs.version == iargs.version) {
                    AppJump();
                } else {
                    if (strcmp((char *)Bootargs.confSrc, "EEPROM") == 0)
                        ImageCopyEepToFlash();
                    else 
                        ImageCopySdToFlash();
                    Bootargs.version = iargs.version;
                    boot_saveenv(NULL);
                    AppJump();
                }
            } else {
                uartprintf("Could not find valid image at (%s)\r\n", Bootargs.confSrc);
            }
        } else {
            uartprintf("Device (%s) is not valid\r\n", Bootargs.confSrc);
        }
    } else {
        if (GetImageInfo(&iargs, (uint8_t *)Bootargs.confSrc) == STM32_SUCCESS) {
            memset((char *)Bootargs.statSrc, 0, MAX_SOURCE_STR_LEN);
            memcpy((char *)Bootargs.statSrc, (char *)Bootargs.confSrc, strlen((char *)Bootargs.confSrc)+1);
            Bootargs.version = iargs.version;

            if (strcmp((char *)Bootargs.confSrc, "EEPROM") == 0)
                ImageCopyEepToFlash();
            else 
                ImageCopySdToFlash();
            boot_saveenv(NULL);
            AppJump();
        } else {
            uartprintf("Could not find valid image at (%s)\r\n", Bootargs.confSrc);
        }
    }
}

void execute_command(uint8_t *command)
{
    int i;
    const cmdType_t *cmdType;
    for (i=0;i<NUM_ROWS(commands);i++) {
        cmdType = &commands[i];
        if (strncmp((char *)cmdType->name, (char *)command, strlen((char *)cmdType->name)) == 0) {
            cmdType->func(command);
            return;
        }
    }
    boot_printenv(command);
    return;
}

void AppJump()
{
      uartprintf("BootAddrData %d\r\n", *(__IO uint32_t *) APP_DEFAULT_ADD);
    if (((*(__IO uint32_t *) APP_DEFAULT_ADD) & 0x2FFE0000) == 0x20000000) {
        /* Jump to user application */
        JumpAddress = *(__IO uint32_t *) (APP_DEFAULT_ADD + 4);
        JumpToApplication = (pFunction) JumpAddress;

        /* Initialize user application's Stack Pointer */
        __set_MSP(*(__IO uint32_t *) APP_DEFAULT_ADD);
        JumpToApplication();
    }
}
