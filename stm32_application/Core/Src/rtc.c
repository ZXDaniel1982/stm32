#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

void RTC_Init()
{
    SET_BIT(PWR->CR, PWR_CR_DBP);
    SET_BIT(RCC->BDCR, RCC_BDCR_RTCEN);

    CLEAR_BIT(RTC->CRL, RTC_CRL_RSF);
    while (READ_BIT(RTC->CRL, RTC_CRL_RSF)) {}

    while (!READ_BIT(RTC->CRL, RTC_CRL_RTOFF)) {}
    SET_BIT(RTC->CRL, RTC_CRL_CNF);
    
    MODIFY_REG(RTC->PRLH, RTC_PRLH_PRL, (0xFFFFFFFFU >> 16));
    MODIFY_REG(RTC->PRLL, RTC_PRLL_PRL, (0xFFFFFFFFU & RTC_PRLL_PRL));
    
    while (!READ_BIT(RTC->CRL, RTC_CRL_RTOFF)) {}
    SET_BIT(RTC->CRL, RTC_CRL_CNF);

    uint32_t time = ((uint32_t)16 * 3600U) + ((uint32_t)50 * 60U);
    /* Set RTC COUNTER MSB word */
    WRITE_REG(RTC->CNTH, (time >> 16U));
    /* Set RTC COUNTER LSB word */
    WRITE_REG(RTC->CNTL, (time & RTC_CNTL_RTC_CNT));

    CLEAR_BIT(RTC->CRL, RTC_CRL_CNF);
    while (!READ_BIT(RTC->CRL, RTC_CRL_RTOFF)) {}
}
