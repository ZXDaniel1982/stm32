/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DATA_H
#define __DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
  union {
    struct {
      uint64_t lcdDef : 2;
      uint64_t reserve : 62;
    } bits;
    uint64_t SpcMaskRom;
  };
} SpcDataRom_t;

typedef struct {

} SpcDataRam_t;

void SpcDataInit(void);
uint8_t SpcData_GetLcdDef(void);

#ifdef __cplusplus
}
#endif

#endif /* __DATA_H */
