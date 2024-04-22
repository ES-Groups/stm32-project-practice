#include "stm32f4xx.h"
#include "usart.h"
#include "PWM.h"
#include "control.h"
#include "TIM_EXTI.h"
#include "led.h"
#include "key.h"
#include "lcd.h"

// (37,6) 左上
// (112,4) 右上
// (123,85) 右下
// (29,88 ) 左下

// (79,8)
// (99,42)
// (73,62)

uint8_t mode = mode_three;
uint8_t flag_stop;
uint8_t two_flag;
uint8_t three_flag;
uint8_t four_flag;
uint8_t num_3 = 1;
uint8_t num_2 = 1;
uint8_t num_4 = 1;
float pwm1;
float pwm2;
float k1, k2, k3, k4, b1, b2, b3, b4;

void Servo_PID_cal(int16_t F_X, int16_t F_Y, int16_t Taget_Fx, int16_t Taget_Fy)
{
	if (F_x != FALSE && F_y != FALSE && flag_stop < 5)
	{
		*Servo_pwm_out = Servo_Fx_PID(F_X, Taget_Fx);
		*(Servo_pwm_out + 1) = Servo_Fy_PID(F_Y, Taget_Fy);
		PWM_OUT_LIMIT(Servo_pwm_out, 18000, 900);
		PWM_OUT_LIMIT(Servo_pwm_out + 1, 180000, 900);
		load(Servo_TIM, *Servo_pwm_out, *(Servo_pwm_out + 1), Servo_Mode);
		if (openmv[4] == TRUE)
		{
			flag_stop++;
		}
	}
	if ((F_X == FALSE && F_Y == FALSE) || flag_stop >= 5) // 找不到色块原地停止
	{
		load(Servo_TIM, 0, 0, Servo_Mode);
		reset_flag = FALSE;
	}
}

void chazhi_xunji(int16_t F_X, int16_t F_Y, int16_t Taget_Fx, int16_t Taget_Fy, int16_t NUM)
{
	Servo_PID_cal(F_x, F_y, Taget_Fx, Taget_Fy);
	if (F_x <= Taget_Fx + 1 && F_x >= Taget_Fx - 1 && F_y <= Taget_Fy + 1 && F_y >= Taget_Fy - 1) // 到达目标值
	{
		load(Servo_TIM, 0, 0, Servo_Mode); // 停止
		Stopflag = 5;					   // 停止
		num_3 = NUM;
		num_2 = NUM;
		num_4 = NUM;
		// if (num_2 == 7)
		// 	two_flag = FALSE; // 第二问结束
		// if (num_3 == 7)
		// {
		// 	three_flag = FALSE; // 第三问结束
		// }
	}
}

void TIM4_IRQHandler(void) //  20ms 主控 保证数据的实时获取与计算的实时性
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
	{
		if (reset_flag == TRUE)
		{
			Servo_PID_cal(F_x, F_y, Target_Fx, Target_Fy);
		}
		/************第二问*************/
		if (two_flag == TRUE)
		{
			switch (num_2)
			{
			case 1:
				chazhi_xunji(F_x, F_y, 34, 5, 2);
				break;
			case 2:
				chazhi_xunji(F_x, F_y, 112, 4, 3);
				break;
			case 3:
				chazhi_xunji(F_x, F_y, 120, 50, 4);
				break;
			case 4:
				chazhi_xunji(F_x, F_y, 122, 86, 5);
				break;
			case 5:
				chazhi_xunji(F_x, F_y, 26, 88, 6);
				break;
			case 6:
				chazhi_xunji(F_x, F_y, 34, 6, 7);
				break;
			}
		}
		/************第三问*************/
		if (three_flag == TRUE)
		{
			switch (num_3)
			{
			case 1:
				chazhi_xunji(F_x, F_y, 57, 15, 2);
				break;
			case 2:
				chazhi_xunji(F_x, F_y, 60, 18, 3);
				break;
			case 3:
				chazhi_xunji(F_x, F_y, 65, 20, 4);
				break;
			case 4:
				chazhi_xunji(F_x, F_y, 71, 25, 5);
				break;
			case 5:
				chazhi_xunji(F_x, F_y, 78, 30, 6);
				break;
			case 6:
				chazhi_xunji(F_x, F_y, 83, 34, 7);
				break;
			case 8:
				chazhi_xunji(F_x, F_y, 89, 40, 8);
				break;
			case 9:
				chazhi_xunji(F_x, F_y, 92, 43, 9);
				break;
			default:
				break;
			}
			// switch (num_3)
			// {
			// /************第一条横线************/
			// case 1:
			// 	chazhi_xunji(F_x, F_y, 37, 7, 2);
			// 	break;
			// case 2:
			// 	chazhi_xunji(F_x, F_y, 44, 7, 3);
			// 	break;
			// case 3:
			// 	chazhi_xunji(F_x, F_y, 50, 6, 4);
			// 	break;
			// case 4:
			// 	chazhi_xunji(F_x, F_y, 56, 5, 5);
			// 	break;
			// case 5:
			// 	chazhi_xunji(F_x, F_y, 62, 5, 6);
			// 	break;
			// case 6:
			// 	chazhi_xunji(F_x, F_y, 68, 5, 7);
			// 	break;
			// case 7:
			// 	chazhi_xunji(F_x, F_y, 81, 5, 8);
			// 	break;
			// 	/************第一条竖线*************/
			// case 8:
			// 	chazhi_xunji(F_x, F_y, 83, 33, 9);
			// 	break;
			// 	/************第二条横线*************/
			// case 9:
			// 	chazhi_xunji(F_x, F_y, 70, 34, 10);
			// 	break;
			// case 10:
			// 	chazhi_xunji(F_x, F_y, 60, 34, 11);
			// 	break;
			// case 11:
			// 	chazhi_xunji(F_x, F_y, 50, 34, 12);
			// 	break;
			// case 12:
			// 	chazhi_xunji(F_x, F_y, 40, 34, 13);
			// 	break;
			// case 13:
			// 	chazhi_xunji(F_x, F_y, 35, 35, 14);
			// 	break;
			// /************第二条竖线*************/
			// case 14:
			// 	chazhi_xunji(F_x, F_y, 35, 3, 15);
			// 	break;
			// default:
			// 	break;
			// }
			if (four_flag == TRUE) // 第四小题
			{
				switch (num_4)
				{
				case 1:
					chazhi_xunji(F_x, F_y, 57, 15, 2);
					break;
				case 2:
					chazhi_xunji(F_x, F_y, 60, 18, 3);
					break;
				case 3:
					chazhi_xunji(F_x, F_y, 65, 20, 4);
					break;
				case 4:
					chazhi_xunji(F_x, F_y, 71, 25, 5);
					break;
				case 5:
					chazhi_xunji(F_x, F_y, 78, 30, 6);
					break;
				case 6:
					chazhi_xunji(F_x, F_y, 83, 34, 7);
					break;
				case 8:
					chazhi_xunji(F_x, F_y, 89, 40, 8);
					break;
				case 9:
					chazhi_xunji(F_x, F_y, 92, 43, 9);
					break;
				default:
					break;
				}
			}
			TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
		}
	}
}
void Config_Init(void)
{
	TIM9_PWM_Init(20000, 168);
	delay_init(168);
	TIM_EXTI_Init();
	TIM12_PWM_Init(ARR, PSC);
	Serial1_Init(115200);
	Serial3_Init(115200);
	LED_Init();
	SPI_LCD_Init();
	LCD_SetColor(LCD_BLUE);
	LCD_Backlight_ON;
	LCD_ShowNumMode(Fill_Space);
	Key_Init();
}

int main(void)
{
	Config_Init();
	while (1)
	{
		LCD_DisplayNumber(10, 190, X1 + (X4 - X1) / 10, 3);
		LCD_DisplayNumber(10, 230, Y1 + k1 * (X4 - X1) / 10, 3);
		LCD_DisplayDecimals(10, 100, k1, 3, 2);
		LCD_DisplayDecimals(10, 150, k2, 3, 2);
		LCD_DisplayNumber(50, 10, X1, 3);
		LCD_DisplayNumber(50, 50, Y1, 3);
		LCD_DisplayNumber(90, 10, X2, 3);
		LCD_DisplayNumber(90, 50, Y2, 3);
		LCD_DisplayNumber(130, 10, X3, 3);
		LCD_DisplayNumber(130, 50, Y3, 3);
		LCD_DisplayNumber(160, 10, X4, 3);
		LCD_DisplayNumber(160, 50, Y4, 3);
		LCD_DisplayNumber(10, 10, flag_stop, 1);
	}
}

void EXTI4_IRQHandler(void) // 问题3外部中断函数
{
	if (EXTI_GetITStatus(EXTI_Line4) == SET)
	{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4) == 0)
		{
			three_flag = TRUE;
			flag_stop = 0;
		}
		EXTI_ClearITPendingBit(EXTI_Line15);
	}
}

void EXTI15_10_IRQHandler(void) // 复位按键外部中断函数
{
	if (EXTI_GetITStatus(EXTI_Line15) == SET)
	{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15) == 0)
		{
			reset_flag = TRUE;
		}
		EXTI_ClearITPendingBit(EXTI_Line15);
	}
}

void EXTI2_IRQHandler(void) // 复位按键外部中断函数
{
	if (EXTI_GetITStatus(EXTI_Line2) == SET) // 问题2外部中断函数
	{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 0)
		{
			two_flag = TRUE;
		}
		EXTI_ClearITPendingBit(EXTI_Line2);
	}
}
