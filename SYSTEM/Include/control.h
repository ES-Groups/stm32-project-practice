#ifndef __CONTROL_H
#define __CONTROL_H

#include <sys.h>
#include "PWM.h"
#include "PID.h"
#include "Encoder.h"
#include "usart.h"
#include "Common_filter.h"
#include "LCD.h"

extern int16_t Target_V;   // 设置目标速度
extern int16_t Speed;      // 当前速度
extern int16_t Speed_Left; // 左轮速度
extern int16_t Speed_Right; // 右轮速度 
extern uint16_t pathLenth; // 走过的路程
extern int16_t Target_Fx;
extern int16_t Target_Fy;
extern float Servo_pwm_out[2];
extern uint8_t reset_flag; 

extern float motor_left, motor_right;
extern float motor_speed1,motor_speed2;

void Control_Init(void); // 小车引脚初始化
void load(TIM_TypeDef* TIMx,int motor1, int motor2,int mode);
void Stop(void); // 停车
int Distant_Limit(int Now_Disdant, int *pwm, int Taget_Distant);
void Car_turn(int pluse, int mode);
BoolState Get_Crossroads(void);
void Track_Control(void);    //循迹控制
int16_t MyAbs(int16_t p);
int16_t Turn_PID(int16_t rho, int16_t Taget_rho);
void straight(int pluse);
void back(int pluse);
void Go(int pluse);
void Servo_Control(float Angle);
uint8_t Control_Reset(uint32_t Fx, uint32_t Fy);
void Servo_SetAngle(float Angle,uint8_t mode);

#define Motor_TIM TIM12
#define Servo_TIM TIM9
#define Motor_Mode 1
#define Servo_Mode 2
#define Middle_x 155
#define Middle_y 82
#define Stopflag openmv[4]

#define F_x openmv[2]  // 识别到色块的中心点坐标
#define F_y openmv[3]

extern int32_t X1;
extern int32_t Y1;  
extern int32_t X2; 
extern int32_t Y2; 
extern int32_t X3; 
extern int32_t Y3;
extern int32_t X4; 
extern int32_t Y4; 

#define modereset 1
#define mode_two 2
#define mode_three 3
#define mode_four 4
#define mode_five 5
#define mode_six 6

#define AIN1 PGout(0)
#define AIN2 PGout(1)
#define BIN1 PGout(2)
#define BIN2 PGout(3)

#endif
