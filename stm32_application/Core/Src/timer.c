#include "stm32f1xx.h"
#include "stm32f103xe.h"
#include "common.h"

volatile uint32_t ulHighFrequencyTimerTicks = 0;
static SemaphoreHandle_t TimerMutex;
extern TaskHandle_t TaskMeasure;

static void TIMERx_Init(TIM_TypeDef * TIMx, uint32_t Periphs, IRQn_Type IRQn)
{
	if ((TIMx == TIM1) || (TIMx == TIM8)) {
		SET_BIT(RCC->APB2ENR, Periphs);
	} else {
		SET_BIT(RCC->APB1ENR, Periphs);
	}

	/*清空计数器的值 */
	WRITE_REG(TIMx->CNT, 0);
	WRITE_REG(TIMx->ARR, 200 - (TIM_CCMR1_IC1F_0 << 16U));
	WRITE_REG(TIMx->PSC, 360 - (TIM_CCMR1_IC1F_0 << 16U));

	WRITE_REG(TIMx->CR1, 0);	//将控制寄存器1清空

	SET_BIT(TIMx->CR1, TIM_CR1_URS);	//设置事件更新请求源

	/*设置无缓冲功能 */
	CLEAR_BIT(TIMx->CR1, TIM_CR1_ARPE);

	/*设置循环模式 */
	CLEAR_BIT(TIMx->CR1, TIM_CR1_OPM);

	/*允许更新中断使能 */
	SET_BIT(TIMx->DIER, TIM_DIER_UIE);

	/*使能基本定时器中断 */
	NVIC_EnableIRQ(IRQn);
  NVIC_SetPriority(IRQn, 5);

	/*开启计数器使能 */
	SET_BIT(TIMx->CR1, TIM_CR1_CEN);
}

void Timer_TickInc()
{
	xSemaphoreTake(TimerMutex, portMAX_DELAY);
  ulHighFrequencyTimerTicks++;
	xSemaphoreGive(TimerMutex);
}

uint32_t Timer_GetTick()
{
  uint32_t value;

	xSemaphoreTake(TimerMutex, portMAX_DELAY);
  value = ulHighFrequencyTimerTicks;
	xSemaphoreGive(TimerMutex);

  return value;
}

void TIMER_Init()
{
	TimerMutex = xSemaphoreCreateMutex();

  TIMERx_Init(TIM1, RCC_APB2ENR_TIM1EN, TIM1_UP_IRQn);
	TIMERx_Init(TIM2, RCC_APB1ENR_TIM2EN, TIM2_IRQn);
#if 0
  TIMERx_Init(TIM3, RCC_APB1ENR_TIM3EN, TIM3_IRQn);
	TIMERx_Init(TIM4, RCC_APB1ENR_TIM4EN, TIM4_IRQn);
	TIMERx_Init(TIM5, RCC_APB1ENR_TIM5EN, TIM5_IRQn);
	TIMERx_Init(TIM6, RCC_APB1ENR_TIM6EN, TIM6_IRQn);
	TIMERx_Init(TIM7, RCC_APB1ENR_TIM7EN, TIM7_IRQn);
	TIMERx_Init(TIM8, RCC_APB2ENR_TIM8EN, TIM8_UP_IRQn);
#endif
}

void TIM1_UP_IRQHandler(void)
{
	CLEAR_BIT(TIM1->SR, TIM_SR_UIF);
}

void TIM2_IRQHandler(void)
{
	CLEAR_BIT(TIM2->SR, TIM_SR_UIF);
	Timer_TickInc();
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
