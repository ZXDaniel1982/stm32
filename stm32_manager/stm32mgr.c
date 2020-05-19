#include "common.h"

const char *portname = "/dev/ttyUSB0";
const char *argsname = "build/ImageArgs";

uint8_t txBuf[20] = {0};
uint8_t rxBuf[20] = {0};
uint8_t rdBuf[8] = {0};
uint16_t chksum = 0;

static FILE *file = NULL;

static void GetHeader(uint8_t *buf, uint8_t cmd);
static void GetChecksum(uint8_t *buf);
static bool GetReply(uint8_t *buf);
static bool SingleComm(uint16_t cmd, int fd);
static void IAP_CONV_FROM_32(uint8_t *buf, uint32_t val);

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage : stm32mgr install <file>\n");
        printf("      : stm32mgr sdimage <file>\n");
        printf("      : stm32mgr connect\n");
        printf("      : stm32mgr reboot\n");
        return -1;
    }

    if (strcmp(argv[1], "sdimage") == 0) {
        if (argv[2] == NULL) {
            printf("Please input valid file name\n");
            return -1;
        }
        uint8_t filename[255];
        memset(filename, 0, 255);
        strcpy(filename, argv[2]);

        Imageargs_t iargs;
        GetImageArgs(&iargs, filename);

        file = fopen(argsname, "w+");
        if (file == NULL) {
            printf("Fail to open file (%s)\n", filename);
            return -1;
        }

        fwrite(&iargs, sizeof(Imageargs_t), 1, file);
        fclose(file);
        return 0;
    }

    int fd = open (portname, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        printf("%s:%d error opening %s %d\n", __func__, __LINE__, portname, fd);
        return -1;
    }

    set_interface_attribs (fd, B115200, 0);  // set speed to 115,200 bps, 8n1 (no parity)
    set_blocking (fd, 1);                // set no blocking

    memset(rxBuf, 0xff, 20);
    memset(txBuf, 0xff, 20);
    memset(rdBuf, 0xff, 8);


    // make connection
    printf("Connect to app\n");
    if (!SingleComm(IAP_CMD_CONNECT, fd)) {
        return -1;
    }
    printf("Connection to app success\n");

    if (strcmp(argv[1], "connect") == 0) {
        return 0;
    } else if (strcmp(argv[1], "reboot") == 0) {
        // reboot device
        printf("Reboot device\n");
        if (!SingleComm(IAP_CMD_REBOOT, fd)) {
            return -1;
        }
        printf("Reboot success\n");
    } else if (strcmp(argv[1], "install") == 0) {
        if (argv[2] == NULL) {
            printf("Please input valid file name\n");
            return -1;
        }

        uint8_t filename[255];
        memset(filename, 0, 255);
        strcpy(filename, argv[2]);

        Imageargs_t iargs;
        GetImageArgs(&iargs, filename);

        uint32_t size = iargs.size;

        file = fopen(argsname, "r");
        if (file == NULL) {
            printf("Fail to open file (%s)\n", argsname);
            return -1;
        }

        // write data
        printf("Write Args to SD card\n");
        memcpy(&txBuf[3], &iargs, sizeof(Imageargs_t));
        if (!SingleComm(IAP_CMD_SETARGS, fd)) {
            fclose(file);
            return -1;
        }
        fclose(file);
        
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Fail to open file (%s)\n", filename);
            return -1;
        }

        uint32_t sdAddr = SDCARD_IMAGE_ADDR;
        while (size > 0) {
            for (int i=0;i<(SDCARD_PAGE_SIZE/8);++i) {
                memset(rdBuf, 0xff, 8);
                memset(txBuf, 0xff, 20);

                txBuf[3] = i;
                fread(rdBuf, sizeof(uint8_t), 8, file);
                memcpy(&txBuf[4], rdBuf, 8);
                if (!SingleComm(IAP_CMD_BUFFER, fd)) {
                    fclose(file);
                    return -1;
                }
            }

            memset(rdBuf, 0xff, 8);
            memset(txBuf, 0xff, 20);
            IAP_CONV_FROM_32(&txBuf[3], sdAddr);
            if (!SingleComm(IAP_CMD_SAVE, fd)) {
                fclose(file);
                return -1;
            }

            sdAddr += SDCARD_PAGE_SIZE;
            if (size < SDCARD_PAGE_SIZE) {
                size = 0;
            } else {
                size -= SDCARD_PAGE_SIZE;
            }
        }
        printf("Programm iap success\n"); 
        // reboot
        printf("Reboot the device\n");
        if (!SingleComm(IAP_CMD_REBOOT, fd)) {
            fclose(file);
            return -1;
        }
        fclose(file);
    }
}

static void GetHeader(uint8_t *buf, uint8_t cmd)
{
    buf[0] = 0x22;
    buf[1] = 0x33;
    buf[2] = cmd;
    buf[18] = 0x44;
    buf[19] = 0x55;
}

static void GetChecksum(uint8_t *buf)
{
    for (int i=0;i<16;i++) {
        chksum += buf[i];
    }

    buf[16] = (uint8_t)((chksum >> 8) & 0x00ff);
    buf[17] = (uint8_t)(chksum & 0x00ff);
    chksum = 0;
}

static bool GetReply(uint8_t *buf)
{
    if ((buf[0] != 0x33) || (buf[1] != 0x44)) return false;

    if (buf[2] == IAP_ERROR) 
        return false;

    return true;
}

static bool SingleComm(uint16_t cmd, int fd)
{
    GetHeader(txBuf, cmd);
    GetChecksum(txBuf);

    for (int i = 0; i < 5; ++i) {
        write (fd, txBuf, 20);
        read (fd, rxBuf, 20);
        if (GetReply(rxBuf)) {
            memset(txBuf, 0xff, 20);
            memset(rxBuf, 0xff, 20);
            return true;
        } else {
            printf("Send fail, try again (%d)\n", i);
        }
    }
    printf("Send fail for command (%d) detail (%d)\n", cmd, rxBuf[3]);
    return false;
}

static void IAP_CONV_FROM_32(uint8_t *buf, uint32_t val)
{
    buf[0] = (uint8_t)((val >> 24) & 0x000000ff);
    buf[1] = (uint8_t)((val >> 16) & 0x000000ff);
    buf[2] = (uint8_t)((val >> 8) & 0x000000ff);
    buf[3] = (uint8_t)(val & 0x000000ff);
}
