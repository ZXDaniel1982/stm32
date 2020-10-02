#include "stm32f1xx.h"

volatile uint32_t ulHighFrequencyTimerTicks = 0;

void TIM1_UP_IRQHandler(void)
{
    CLEAR_BIT(TIM1->SR, TIM_SR_UIF);
}

void TIM2_IRQHandler(void)
{
    CLEAR_BIT(TIM2->SR, TIM_SR_UIF);
    ulHighFrequencyTimerTicks++;
}

void TIM3_IRQHandler(void)
{
    CLEAR_BIT(TIM3->SR, TIM_SR_UIF);
}

void TIM4_IRQHandler(void)
{
    CLEAR_BIT(TIM4->SR, TIM_SR_UIF);
}

void TIM5_IRQHandler(void)
{
    CLEAR_BIT(TIM5->SR, TIM_SR_UIF);
}

void TIM6_IRQHandler(void)
{
    CLEAR_BIT(TIM6->SR, TIM_SR_UIF);
}

void TIM7_IRQHandler(void)
{
    CLEAR_BIT(TIM7->SR, TIM_SR_UIF);
}

void TIM8_UP_IRQHandler(void)
{
    CLEAR_BIT(TIM8->SR, TIM_SR_UIF);
}

void USART1_IRQHandler(void)
{
    uint8_t buf;
    if((USART1->SR & USART_CR1_RXNEIE) != 0) {
        buf = USART1->DR;
        //USART_RxProcess(buf);
    }
}
