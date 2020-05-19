#include "sd.hpp"
#include "sdio.h"
#include "stm32_sdio.h"

STM32F103VET_SD::STM32F103VET_SD()
{
    SDIOEx_Init();
}
