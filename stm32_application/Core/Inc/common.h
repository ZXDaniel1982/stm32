/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __COMMON_H
#define __COMMON_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stdint.h>
#include <stdbool.h>

#include "sdio.h"
#include "stm32f103xe.h"
    
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

#define Delay1s() do { \
  for (uint32_t i=0;i<72000;i++) {} \
} while(0)


#define UNUSED(x) (void)x
#define NUM_ROWS(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))

#define SST_CS_Pin GPIO_BSRR_BS4
#define SST_CS_GPIO_Port GPIOA
#define Key_Pin GPIO_BSRR_BS15
#define Key_GPIO_Port GPIOB
#define Key_EXTI_IRQn EXTI15_10_IRQn
#define LCD_Light_Pin GPIO_BSRR_BS13
#define LCD_Light_GPIO_Port GPIOD
#define Led_Pin GPIO_BSRR_BS5
#define Led_GPIO_Port GPIOB
#define LCD_Rst_Pin GPIO_BSRR_BS1
#define LCD_Rst_GPIO_Port GPIOE
    
#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority,
                                                                 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority,
                                                                 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority,
                                                                 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority,
                                                                 1 bit  for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,
                                                                 0 bit  for subpriority */
    
#define FLASH_PAGE_SIZE          ( 0x800U )   // 2048B
#define EEPROM_PAGE_SIZE         ( 0x1000U )  // 4096B
#define SDCARD_PAGE_SIZE         ( 0x200U )   // 512B
#define DATA_BUF_SIZE            ( SDCARD_PAGE_SIZE )

#define SDCARD_ARGS_ADDR         ( 0 )
#define SDCARD_IMAGE_ADDR        ( SDCARD_PAGE_SIZE )

#define APP_DEFAULT_ADD 0x8005000
typedef  void (*pFunction)(void);
    
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
    GPIO_TypeDef *port;
    uint32_t pin;
    uint32_t clear;
    uint32_t set;
} GPIO_PINS_t;

typedef struct
{
    uint16_t header;
    uint16_t version;
    uint32_t size;
    uint16_t tail; 
} Imageargs_t;

// RCC
void RCC_Init(void);

// GPIO
void GPIO_Init(void);

// TIMER
void TIMER_Init(void);

// USART1
void USART_Init(void);
void USART_SendData(uint8_t *data, uint16_t len);
int uartprintf(const char* fmt, ...);

// FLASH
void FLASH_Lock(void);
void FLASH_Unlock(void);
bool FLASH_WaitForFinish(void);
void FLASH_Erase(uint32_t Add);
bool FLASH_Program(uint8_t *dest, uint8_t *src, uint32_t len);

// SPI
void SPI_Init(void);
uint8_t SPI_Transmit(uint8_t *data, uint16_t size);
uint8_t SPI_TransmitReceive(uint8_t *txData, uint8_t *rxData, uint16_t size);

// EEPROM
void EEPROM_Init(void);
void EEProm_SectorErrase(uint32_t addr);
void EEPROM_Write(uint32_t addr, uint8_t * buf, uint16_t len);
void EEPROM_Read(uint32_t addr, uint8_t *buf, uint16_t len);

// FSMC
void FSMC_Init(void);

// LCD
void LCD_Init(void);
int tftprintf(const char* fmt, ...);

// RTC
// void RTC_Init(void);

// ADC
void ADC_Init(void);

// SDIO
void SDIOEx_Init(void);
SD_Error SD_Erase(uint32_t startaddr, uint32_t endaddr);
SD_Error SD_ReadBlock(uint32_t *readbuff, uint32_t ReadAddr, uint16_t BlockSize);
SD_Error SD_WriteBlock(uint32_t *writebuff, uint32_t WriteAddr, uint16_t BlockSize);

// Interrupt
void TIM1_UP_IRQHandler(void);
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
void TIM5_IRQHandler(void);
void TIM6_IRQHandler(void);
void TIM7_IRQHandler(void);
void TIM8_UP_IRQHandler(void);
void USART1_IRQHandler(void);

// error
void Error_Handle(void);

void LedBlink(void);
// void DMA_Init(void);

// Measurement
void Measure_VoltCurInit(void);

// Page
void Page_Init(void);

// Gui
void Gui_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __COMMON_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
