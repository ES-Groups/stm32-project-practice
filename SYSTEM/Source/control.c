/**
 * 控制小车
 */

#include "control.h"
int32_t X1;
int32_t Y1; 
int32_t X2; 
int32_t Y2; 
int32_t X3; 
int32_t Y3;
int32_t X4; 
int32_t Y4;

float motor_speed1, motor_speed2;

int16_t Target_V = 40;	 // 设置目标速度
int16_t Speed = 0;		 // 当前速度
int16_t Speed_Left = 0;	 // 左轮速度
int16_t Speed_Right = 0; // 右轮速度
uint16_t pathLenth;		 // 走过的路程
int16_t Target_Fx = 76;
int16_t Target_Fy = 41;
float Servo_pwm_out[2];
uint8_t reset_flag = FALSE;
float axis[4][2] = {{53,175},{65,12},{221,12},{255,163}};



float motor_left, motor_right;

void Control_Init(void) // 小车引脚初始化
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}

/**
 * @brief 赋值PWM函数,控制转向
 * @param motor1:左轮PWM -> 经过PID之后
 * @param motor2:右轮PWM -> 经过PID之后
 * @retval 无
 */
void load(TIM_TypeDef *TIMx, int motor1, int motor2, int mode)
{
	// 研究正负号，对应正反转
	switch (mode)
	{
	case Motor_Mode:
		if (motor1 > 0)
		{
			AIN1 = 1;
			AIN2 = 0;
		}
		else
		{
			AIN1 = 0;
			AIN2 = 1;
		}
		// Set_Compare1(MyAbs(motor1));
		TIMx->CCR1 = MyAbs(motor1);

		if (motor2 > 0)
		{
			BIN1 = 1;
			BIN2 = 0;
		}
		else
		{
			BIN1 = 0;
			BIN2 = 1;
		}
		// Set_Compare2(MyAbs(motor2));
		TIMx->CCR2 = MyAbs(motor2);
		break;
	case Servo_Mode: // 舵机驱动
		TIMx->CCR1 = motor1;
		TIMx->CCR2 = motor2;
		break;
	}
}

void Stop(void) // 停车
{
	AIN1 = 1;
	AIN2 = 1;
	BIN1 = 1;
	BIN2 = 1;
}

void Track_Control(void) // 循迹控制
{
	load(Motor_TIM, motor_left, motor_right, Motor_Mode);
}

void straight(int pluse)
{
	pathLenth = 0;
	while (pathLenth < pluse)
	{
		load(Motor_TIM, motor_left, motor_right, Motor_Mode);
	}
	load(Motor_TIM, 0, 0, Motor_Mode); // 立马定住
	Stop();
}

void Go(int pluse)
{
	pathLenth = 0;
	while (pathLenth < pluse)
	{
		load(Motor_TIM, motor_speed1, motor_speed2, Motor_Mode);
	}
	load(Motor_TIM, 0, 0, Motor_Mode); // 立马定住
	Stop();
}
/**
 * @brief 距离限制函数
 * @param Now_Disdant:当前位置
 * @param pwm:当前pwm值
 * @param Taget_Distant:预期距离
 * @retval 1 or 0 (1代表超出距离，0代表未达到距离)
 */
int Distant_Limit(int Now_Disdant, int *pwm, int Taget_Distant)
{
	if (Now_Disdant > Taget_Distant)
	{
		Stop();	  // 马上停车
		*pwm = 0; // 将PWM置零
		return 1;
	}
	return 0;
}

void Servo_Control(float Angle)
{
	load(Servo_TIM, Angle / 360 * 2000 + 500,
				Angle / 360 * 2000 + 500, Servo_Mode);
}

/**
 * @brief 运动目标复位功能
 * @param Fx:
 * @param Fy: 原点位置坐标
 * @retval TURE
 */
uint8_t Control_Reset(uint32_t pluse_x, uint32_t pluse_y)
{
	load(Servo_TIM, pluse_x, pluse_y, Servo_Mode);
	return TRUE;
}


void Servo_SetAngle(float Angle,uint8_t mode)
{
	switch (mode)
	{
	case 1:
		TIM9->CCR1 = (Angle / 180 * 2000 + 500);
		break;
	case 2:
		TIM9 ->CCR2 = (Angle / 180 * 2000 + 500);
	}
	
}

