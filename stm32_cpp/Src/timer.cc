#include "driver.hpp"
#include "timer.hpp"
#include "stm32f1xx.h"
#include "common.h"

static void TIMERx_Init(TIM_TypeDef *TIMx, uint32_t Periphs, IRQn_Type IRQn)
{
    if ((TIMx == TIM1) || (TIMx == TIM8)) {
        SET_BIT(RCC->APB2ENR, Periphs);
    } else {
        SET_BIT(RCC->APB1ENR, Periphs);
    }

    /*清空计数器的值*/
    WRITE_REG(TIMx->CNT, 0);
    WRITE_REG(TIMx->ARR, 2000-(TIM_CCMR1_IC1F_0 << 16U));
    WRITE_REG(TIMx->PSC, 36000-(TIM_CCMR1_IC1F_0 << 16U));

    WRITE_REG(TIMx->CR1, 0); //将控制寄存器1清空

    SET_BIT(TIMx->CR1, TIM_CR1_URS); //设置事件更新请求源

    /*设置无缓冲功能*/
    CLEAR_BIT(TIMx->CR1, TIM_CR1_ARPE);

    /*设置循环模式*/
    CLEAR_BIT(TIMx->CR1, TIM_CR1_OPM);

    /*允许更新中断使能*/
    SET_BIT(TIMx->DIER, TIM_DIER_UIE);

    /*使能基本定时器中断*/
    NVIC_EnableIRQ(IRQn);

    /*开启计数器使能*/
    SET_BIT(TIMx->CR1, TIM_CR1_CEN);
}

STM32F103VET_TIMER::STM32F103VET_TIMER()
{
	TIMERx_Init(TIM1, RCC_APB2ENR_TIM1EN, TIM1_UP_IRQn);
    TIMERx_Init(TIM2, RCC_APB1ENR_TIM2EN, TIM2_IRQn);
    TIMERx_Init(TIM3, RCC_APB1ENR_TIM3EN, TIM3_IRQn);
    TIMERx_Init(TIM4, RCC_APB1ENR_TIM4EN, TIM4_IRQn);
    TIMERx_Init(TIM5, RCC_APB1ENR_TIM5EN, TIM5_IRQn);
    TIMERx_Init(TIM6, RCC_APB1ENR_TIM6EN, TIM6_IRQn);
    TIMERx_Init(TIM7, RCC_APB1ENR_TIM7EN, TIM7_IRQn);
    TIMERx_Init(TIM8, RCC_APB2ENR_TIM8EN, TIM8_UP_IRQn);
}