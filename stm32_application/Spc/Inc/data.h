/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DATA_H
#define __DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define NUM_ROWS(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))

typedef struct {
    uint8_t hasValue;
    int16_t temperature[2];
} SpcTemp_t;

typedef struct {
    union {
        struct {
            uint64_t lcdDef : 2;
            uint64_t tempUint : 1;
            uint64_t reserve : 61;
        } bits;
        uint64_t SpcMaskRom;
    };
} SpcDataRom_t;

typedef struct {
    union {
        struct {
            uint64_t heatStatus : 2;
            uint64_t hasHeatStatus : 1;
            uint64_t reserve : 61;
        } bits;
        uint64_t SpcMaskRam;
    };
    SpcTemp_t SpcTemp;
    SpcTemp_t SpcTempChan1;
    SpcTemp_t SpcTempChan2;
} SpcDataRam_t;

void SpcDataInit(void);
uint8_t SpcData_GetLcdDef(void);
uint8_t SpcData_GetTempUint(void);
uint64_t SpcData_GetMaskRam(void);
bool SpcData_GetTemperature(SpcTemp_t *temp);

#ifdef __cplusplus
}
#endif

#endif /* __DATA_H */
