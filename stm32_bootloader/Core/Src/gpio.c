#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

static const GPIO_PINS_t GPIO_PINS_L[] = {
    {Led_GPIO_Port, Led_Pin, (GPIO_CRL_CNF5 | GPIO_CRL_MODE5), GPIO_CRL_MODE5_1},      // B5
    {SST_CS_GPIO_Port, SST_CS_Pin, (GPIO_CRL_CNF4 | GPIO_CRL_MODE4), GPIO_CRL_MODE4},  // B4

    // spi1
    {GPIOA, GPIO_BSRR_BS5,  (GPIO_CRL_CNF5  | GPIO_CRL_MODE5),  (GPIO_CRL_CNF5_1  | GPIO_CRL_MODE5)},
    {GPIOA, GPIO_BSRR_BS6,  (GPIO_CRL_CNF6  | GPIO_CRL_MODE6),  GPIO_CRL_CNF6_0},
    {GPIOA, GPIO_BSRR_BS7,  (GPIO_CRL_CNF7  | GPIO_CRL_MODE7),  (GPIO_CRL_CNF7_1  | GPIO_CRL_MODE7)},
    
    // sdio
    {GPIOD, GPIO_BSRR_BS2,  (GPIO_CRL_CNF2  | GPIO_CRL_MODE2),  (GPIO_CRL_CNF2_1  | GPIO_CRL_MODE2)},
};
static const GPIO_PINS_t GPIO_PINS_H[] = {
    // usart1
    {GPIOA, GPIO_BSRR_BS9,  (GPIO_CRH_CNF9  | GPIO_CRH_MODE9),  (GPIO_CRH_CNF9_1  | GPIO_CRH_MODE9)},
    {GPIOA, GPIO_BSRR_BS10, (GPIO_CRH_CNF10 | GPIO_CRH_MODE10), GPIO_CRH_CNF10_0},
    
    // sdio
    {GPIOC, GPIO_BSRR_BS8,  (GPIO_CRH_CNF8  | GPIO_CRH_MODE8),  (GPIO_CRH_CNF8_1  | GPIO_CRH_MODE8)},
    {GPIOC, GPIO_BSRR_BS9,  (GPIO_CRH_CNF9  | GPIO_CRH_MODE9),  (GPIO_CRH_CNF9_1  | GPIO_CRH_MODE9)},
    {GPIOC, GPIO_BSRR_BS10, (GPIO_CRH_CNF10 | GPIO_CRH_MODE10), (GPIO_CRH_CNF10_1 | GPIO_CRH_MODE10)},
    {GPIOC, GPIO_BSRR_BS11, (GPIO_CRH_CNF11 | GPIO_CRH_MODE11), (GPIO_CRH_CNF11_1 | GPIO_CRH_MODE11)},
    {GPIOC, GPIO_BSRR_BS12, (GPIO_CRH_CNF12 | GPIO_CRH_MODE12), (GPIO_CRH_CNF12_1 | GPIO_CRH_MODE12)},
};

static void GPIOxL_Init(GPIO_TypeDef *GPIOx, uint32_t pin, uint32_t clear, uint32_t set)
{
    // �0�9�0�9�0�7�0�3�0�2�0�3�0�5�0�2�0�6�0�5�0�4�0�2�0�7�0�3�0�4��  �0�5�0�2�0�6�0�5�0�9�0�9�0�7�0�3x�0�8�0�2�0�2�0�3y  1�0�5�0�2�0�5�0�2�0�6�0�5�0�9�0�8�0�7�0�7�0�8�0�2ODRy�0�2�0�3�0�2�0�90
    WRITE_REG(GPIOx->BRR, pin);

      // �0�9�0�9�0�7�0�3�0�3�0�1�0�0�0�1�0�8�0�1�0�4�0�2�0�7�0�3�0�4��  CNF 00�0�5�0�2�0�1���0�7�0�1�0�1�0�4�0�1���0�8�0�1�0�6�0�2�0�2�0�5�0�8�0�5  MODE  10 : �0�8�0�1�0�6�0�2�0�2�0�5�0�8�0�5�0�5�0�1���0�6�0�7���0�9�0�2�0�9�0�62MHz
    MODIFY_REG(GPIOx->CRL, clear, set);

    // �0�9�0�9�0�7�0�3�0�8�0�1�0�6�0�2�0�8�0�5�0�6�0�6�0�4�0�2�0�7�0�3�0�4��  
    MODIFY_REG(GPIOx->ODR, pin, 0);
}

static void GPIOxH_Init(GPIO_TypeDef *GPIOx, uint32_t pin, uint32_t clear, uint32_t set)
{
    // �0�9�0�9�0�7�0�3�0�2�0�3�0�5�0�2�0�6�0�5�0�4�0�2�0�7�0�3�0�4��  �0�5�0�2�0�6�0�5�0�9�0�9�0�7�0�3x�0�8�0�2�0�2�0�3y  1�0�5�0�2�0�5�0�2�0�6�0�5�0�9�0�8�0�7�0�7�0�8�0�2ODRy�0�2�0�3�0�2�0�90
    WRITE_REG(GPIOx->BRR, pin);

      // �0�9�0�9�0�7�0�3�0�3�0�1�0�0�0�1�0�8�0�1�0�4�0�2�0�7�0�3�0�4��  CNF 00�0�5�0�2�0�1���0�7�0�1�0�1�0�4�0�1���0�8�0�1�0�6�0�2�0�2�0�5�0�8�0�5  MODE  10 : �0�8�0�1�0�6�0�2�0�2�0�5�0�8�0�5�0�5�0�1���0�6�0�7���0�9�0�2�0�9�0�62MHz
    MODIFY_REG(GPIOx->CRH, clear, set);

    // �0�9�0�9�0�7�0�3�0�8�0�1�0�6�0�2�0�8�0�5�0�6�0�6�0�4�0�2�0�7�0�3�0�4��  
    MODIFY_REG(GPIOx->ODR, pin, 0);
}

void GPIO_Init()
{
    uint8_t i;

    for (i=0;i<NUM_ROWS(GPIO_PINS_L);++i) {
        GPIOxL_Init(GPIO_PINS_L[i].port, GPIO_PINS_L[i].pin, GPIO_PINS_L[i].clear, GPIO_PINS_L[i].set);
    }
    for (i=0;i<NUM_ROWS(GPIO_PINS_H);++i) {
        GPIOxH_Init(GPIO_PINS_H[i].port, GPIO_PINS_H[i].pin, GPIO_PINS_H[i].clear, GPIO_PINS_H[i].set);
    }
}
