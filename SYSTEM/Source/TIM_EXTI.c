#include "TIM_EXTI.h"

void TIM_EXTI_Init(void)   // 提供20 ms精准延时 -> 主控
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode =TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period =10000-1;
    TIM_TimeBaseInitStructure.TIM_Prescaler =168-1;   // 20ms
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);
    
    TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);    

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel =TIM4_IRQn ;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStructure);

    TIM_Cmd(TIM4,ENABLE);
}

