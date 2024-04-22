#ifndef __KEY_H
#define __KEY_H
#include "stm32f4xx.h"
#include "delay.h"

#define Key_Pin GPIO_Pin_15|GPIO_Pin_4|GPIO_Pin_2 
#define Key_Port GPIOA
#define Key_CLK RCC_AHB1Periph_GPIOA
#define Key GPIO_ReadInputDataBit(Key_Port,Key_Pin)

void Key_Init(void);	//LED初始化函数
#endif 
