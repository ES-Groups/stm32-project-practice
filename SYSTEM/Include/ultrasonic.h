#ifndef __ULTRASONIC_H
#define __ULTRASONIC_H

#include <sys.h>
#include "Common_filter.h"

#define Trig GPIO_Pin_4 
#define Echo GPIO_Pin_5

void Ultrasonic_Init(void);
uint16_t Ultrasonic_Get_Distance(void);

#endif
