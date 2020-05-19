#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

#define USART_MAX_LEN 255
#define USART_PROTOCOL_LEN 20

static void IAP_SetArgs(uint8_t* Buf);
static void IAP_Buffer(uint8_t* Buf);
static void IAP_Clear(uint8_t* Buf);
static void IAP_Save(uint8_t* Buf);
static void IAP_Reboot(uint8_t* Buf);

typedef void (*IAP_Func)(uint8_t *Buf);
typedef struct
{
    uint16_t cmd;
    uint16_t suc;
    uint16_t err;
    IAP_Func func;
} IAP_Command_t;
static const IAP_Command_t IAP_Command[] = {
    {IAP_CMD_CONNECT, IAP_CONNECT_SUCCESS, IAP_CONNECT_FAIL, NULL},
    {IAP_CMD_SETARGS, IAP_SETARGS_SUCCESS, IAP_SETARGS_FAIL, IAP_SetArgs},
    {IAP_CMD_BUFFER,  IAP_BUFFER_SUCCESS,  IAP_BUFFER_FAIL,  IAP_Buffer},
    {IAP_CMD_CLEAR,   IAP_CLEAR_SUCCESS,   IAP_CLEAR_FAIL,   IAP_Clear},
    {IAP_CMD_SAVE,    IAP_SAVE_SUCCESS,    IAP_SAVE_FAIL,    IAP_Save},
    {IAP_CMD_REBOOT,  IAP_REBOOT_SUCCESS,  IAP_REBOOT_FAIL,  IAP_Reboot},
};

uint8_t data[DATA_BUF_SIZE] = {0};
uint8_t txBuf[USART_PROTOCOL_LEN] = {0};
uint8_t rxBuf[USART_MAX_LEN] = {0};
uint8_t rxCnt = 0;


//======================================================================//
// Private functions
//======================================================================//
static uint32_t IAP_CONV_TO_32(uint8_t *buf)
{
    uint32_t ret = 0;
    ret = (*buf) << 24;
    ret += *(buf+1) << 16;
    ret += *(buf+2) << 8;
    ret += *(buf+3);
    return ret;
}

static void IAP_SendReply(uint8_t replyType, uint8_t replyDetail)
{
    txBuf[0] = 0x33;
    txBuf[1] = 0x44;
    txBuf[2] = replyType;
    txBuf[3] = replyDetail;

    USART_SendData(txBuf,USART_PROTOCOL_LEN);
}

static uint8_t IAP_HeaderIsValid(uint8_t* Buf)
{
    if (Buf == NULL) return 0;

    if ((Buf[0] != 0x22) || (Buf[1] != 0x33)) {
        return 0;
    }

    return 1;
}

static uint8_t IAP_ChecksumIsValid(uint8_t* Buf)
{
    uint8_t i;
    uint16_t RxChksum = 0;
    uint16_t Checksum = 0;
    
    if (Buf == NULL) return 0;
    
    Checksum = Buf[16] * 256 + Buf[17];
    for (i=0;i<(USART_PROTOCOL_LEN-4);i++) {
        RxChksum += Buf[i];
    }
        
    if (Checksum == RxChksum) return 1;
    else return 0;
}

static void IAP_NorCommand(uint8_t *Buf, const IAP_Command_t *IapCmd)
{
    if (Buf == NULL) {
        IAP_SendReply(IAP_ERROR, IapCmd->err);
        return;
    }
    
    if (Buf[0] != IapCmd->cmd) {
        return;
    }

    if (IapCmd->func != NULL) {
        IapCmd->func(&Buf[1]);
    } else {
        IAP_SendReply(IAP_SUCCESS, IapCmd->suc);
    }
}

static void IAP_SetArgs(uint8_t* Buf)
{
    memset(data, 0xff, DATA_BUF_SIZE);
    memcpy(data, Buf, sizeof(Imageargs_t));

    SD_WriteBlock((uint32_t *)data, SDCARD_ARGS_ADDR, SDCARD_PAGE_SIZE);
    IAP_SendReply(IAP_SUCCESS, IAP_SETARGS_SUCCESS);
}

static void IAP_Buffer(uint8_t* Buf)
{
    uint16_t index = Buf[0];

    if (index == 0) {
        memset(data, 0xff, DATA_BUF_SIZE);
    }

    memcpy(&data[index*8], &Buf[1], 8);
    IAP_SendReply(IAP_SUCCESS, IAP_BUFFER_SUCCESS);
}

static void IAP_Clear(uint8_t* Buf)
{
    uint32_t addr = IAP_CONV_TO_32(Buf);

    SD_Erase(addr, (addr + SDCARD_PAGE_SIZE));
    IAP_SendReply(IAP_SUCCESS, IAP_CLEAR_SUCCESS);
}

static void IAP_Save(uint8_t* Buf)
{
    uint32_t addr = IAP_CONV_TO_32(Buf);

    SD_WriteBlock((uint32_t *)data, addr, SDCARD_PAGE_SIZE);
    IAP_SendReply(IAP_SUCCESS, IAP_SAVE_SUCCESS);
}

static void IAP_Reboot(uint8_t* Buf)
{
    IAP_SendReply(IAP_SUCCESS, IAP_REBOOT_SUCCESS);
    NVIC_SystemReset();
}

static void USART_DataProcess(uint8_t *Buf)
{
    uint16_t i;

    memset(txBuf, 0, USART_PROTOCOL_LEN);

    if (IAP_HeaderIsValid(Buf) == 0) {
        IAP_SendReply(IAP_ERROR, IAP_ERROR_HEAD_INVALID);
        return;
    }
        
    if (IAP_ChecksumIsValid(Buf) == 0) {
        IAP_SendReply(IAP_ERROR, IAP_ERROR_CHKSUM_INVALID);
        return;
    }

    for (i=0;i<NUM_ROWS(IAP_Command);++i) {
        IAP_NorCommand(&Buf[2], &IAP_Command[i]);
    }
}

static void USART_RxProcess(uint8_t val)
{
    if (rxCnt >= USART_MAX_LEN) {
        memset(rxBuf, 0, USART_MAX_LEN);
        rxCnt = 0;
    }
    
    rxBuf[rxCnt] = val;
    rxCnt++;
        
    if (rxCnt >= 2) {
        if ((rxBuf[rxCnt-2] == 0x44) && (rxBuf[rxCnt-1] == 0x55)) {
            if (rxCnt >= USART_PROTOCOL_LEN) {
                USART_DataProcess(&rxBuf[rxCnt-USART_PROTOCOL_LEN]);
            } else {
                IAP_SendReply(IAP_ERROR, IAP_ERROR_FRAME_INVALID);
            }
            memset(rxBuf, 0, USART_MAX_LEN);
            rxCnt = 0;
        }
    }
        
    if (rxCnt >= USART_MAX_LEN) {
        memset(rxBuf, 0, USART_MAX_LEN);
        rxCnt = 0;
    }
}

void USART_Init()
{
    if (READ_BIT(USART1->CR1, USART_CR1_UE) != (USART_CR1_UE)) {
        MODIFY_REG(USART1->CR1,
               (USART_CR1_M | USART_CR1_PCE | USART_CR1_PS | USART_CR1_TE | USART_CR1_RE),
               (USART_CR1_TE |USART_CR1_RE));

        MODIFY_REG(USART1->CR2, USART_CR2_STOP, 0);

        MODIFY_REG(USART1->CR3, USART_CR3_RTSE | USART_CR3_CTSE, 0);

        USART1->BRR = 0x271;
    }
        
    CLEAR_BIT(USART1->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
    CLEAR_BIT(USART1->CR3, (USART_CR3_SCEN | USART_CR3_IREN | USART_CR3_HDSEL));
        
    SET_BIT(USART1->CR1, USART_CR1_UE);
    SET_BIT(USART1->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));

    NVIC_EnableIRQ(USART1_IRQn);
}

void USART_SendData(uint8_t *data, uint16_t len)
{
    uint16_t i;
    
    for (i=0;i<len;i++) {
        while ((USART1->SR &USART_SR_TXE) == 0) {}
        USART1->DR= data[i];
    }
}

void USART1_IRQHandler(void)
{
    uint8_t buf;
    if((USART1->SR & USART_CR1_RXNEIE) != 0) {
        buf = USART1->DR;
        USART_RxProcess(buf);
    }
}
