#ifndef __COMMON_H__
#define __COMMON_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>
#include <errno.h>
#include <fcntl.h> 
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>

#define IMAGEARGS_HEADER       (0x2233)
#define IMAGEARGS_TAIL         (0x8899)

#define IAP_RETRY_MAX            ( 10 )

#define FLASH_PAGE_SIZE          ( 0x800U )   // 2048B
#define EEPROM_PAGE_SIZE         ( 0x1000U )  // 4096B
#define SDCARD_PAGE_SIZE         ( 0x200U )   // 512B
#define DATA_BUF_SIZE            ( SDCARD_PAGE_SIZE )

#define SDCARD_ARGS_ADDR         ( 0 )
#define SDCARD_IMAGE_ADDR        ( SDCARD_PAGE_SIZE )

typedef enum
{
    IAP_ERROR = 0,
    IAP_SUCCESS,

    IAP_ERROR_HEAD_INVALID,
    IAP_ERROR_FRAME_INVALID,
    IAP_ERROR_CHKSUM_INVALID,
    
    // common
    IAP_CMD_CONNECT,
    IAP_CONNECT_SUCCESS,
    IAP_CONNECT_FAIL,
    
    // SD card programming
    IAP_CMD_SETARGS,
    IAP_SETARGS_SUCCESS,
    IAP_SETARGS_FAIL,

    IAP_CMD_BUFFER,
    IAP_BUFFER_SUCCESS,
    IAP_BUFFER_FAIL,

    IAP_CMD_CLEAR,
    IAP_CLEAR_SUCCESS,
    IAP_CLEAR_FAIL,

    IAP_CMD_SAVE,
    IAP_SAVE_SUCCESS,
    IAP_SAVE_FAIL,

    IAP_CMD_REBOOT,
    IAP_REBOOT_SUCCESS,
    IAP_REBOOT_FAIL,
    
    IAP_MAX_COMMAND = 100,
} IAP_COMMANDS;

typedef struct
{
    uint16_t header;
    uint16_t version;
    uint32_t size;
    uint16_t tail; 
} Imageargs_t;

int set_interface_attribs (int fd, int speed, int parity);
void set_blocking (int fd, int should_block);

void GetImageArgs(Imageargs_t *iargs, char *filename);

#ifdef __cplusplus
}
#endif

#endif /* __COMMON_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
