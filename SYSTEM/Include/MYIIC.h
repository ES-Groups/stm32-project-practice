#ifndef __MYIIC_H
#define __MYIIC_H
#include "stm32f4xx.h"
#include "sys.h"
#include "delay.h"


//IO方向设置
#define SDA_IN()  {GPIOB->MODER &=~(3<<(9*2)); GPIOB->MODER |=0<<9*2;}
#define SDA_OUT() {GPIOB->MODER &=~(3<<(9*2)); GPIOB->MODER |=1<<9*2;}

//IO操作函数	 
#define IIC_SCL    PBout(8) //SCL
#define IIC_SDA    PBout(9) //SDA	 
#define READ_SDA   PBin(9)  //输入SDA 

//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(u8 txd);			//IIC发送一个字节
u8 IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 IIC_Wait_Ack(void); 				//IIC等待ACK信号

#endif




