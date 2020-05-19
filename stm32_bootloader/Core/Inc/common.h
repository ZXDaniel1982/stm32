/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __COMMON_H
#define __COMMON_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
	
#include "stm32f103xe.h"

#define SST_CS_Pin GPIO_BSRR_BS4
#define SST_CS_GPIO_Port GPIOA
#define Led_Pin GPIO_BSRR_BS5
#define Led_GPIO_Port GPIOB
    
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
    
#define FLASH_PAGE_SIZE          (0x800U)

#define APP_DEFAULT_ADD 0x8005000
typedef  void (*pFunction)(void);

#define MAX_SOURCE_STR_LEN  (10)

#define NUM_ROWS(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))
#define UNUSED(x) (void)x

typedef  void (*commandfunc)(uint8_t *command);

typedef struct
{
    GPIO_TypeDef *port;
    uint32_t pin;
    uint32_t clear;
    uint32_t set;
} GPIO_PINS_t;

typedef enum {
    STM32_FALSE = 0,
    STM32_SUCCESS
} BootState_t;

typedef struct
{
    uint16_t header;
    uint8_t confSrc[MAX_SOURCE_STR_LEN];
    uint8_t statSrc[MAX_SOURCE_STR_LEN];
    uint32_t version;
    uint16_t tail; 
} Bootargs_t;

typedef struct
{
    uint16_t header;
    uint16_t version;
    uint32_t size;
    uint16_t tail; 
} Imageargs_t;

typedef struct 
{
    uint8_t name[10];
    commandfunc func;
} cmdType_t;

void Error_Handle(void);

// Delay
void delay(uint32_t val);
    
// GPIO
void GPIO_Init(void);

// USART1
void USART_Init(void);
void USART_SendData(uint8_t *data, uint16_t len);
void uartprintf(const char* fmt, ...);

// FLASH
void FLASH_Lock(void);
void FLASH_Unlock(void);
void FLASH_Erase(uint32_t Add);
bool FLASH_WaitForFinish(void);
bool FLASH_Program(uint8_t *dest, uint8_t *src, uint32_t len);
void USART_RxProcess(uint8_t val);

// SPI
void SPI_Init(void);
uint8_t SPI_Transmit(uint8_t *data, uint16_t size);
uint8_t SPI_TransmitReceive(uint8_t *txData, uint8_t *rxData, uint16_t size);

// EEPROM
void EEPROM_Init(void);
void EEPROM_Read(uint32_t addr, uint8_t *buf, uint16_t len);
void EEPROM_Write(uint32_t addr, uint8_t * buf, uint16_t len);
void EEProm_SectorErrase(uint32_t addr);

// Boot
void BootargsInit(void);
BootState_t autoboot(void);
void GetBootargFromDefault(void);
BootState_t GetBootargFromEEP(void);
void bootm(uint8_t *command);
void execute_command(uint8_t *command);
void AppJump(void);

// Delay
void delay(uint32_t val);
    
#ifdef __cplusplus
}
#endif

#endif /* __COMMON_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
