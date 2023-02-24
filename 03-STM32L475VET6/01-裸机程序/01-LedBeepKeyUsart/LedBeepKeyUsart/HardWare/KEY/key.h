#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"




#define KEY0 HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin)
#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)
#define KEY2 HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)
#define WK_UP HAL_GPIO_ReadPin(WK_UP_GPIO_Port,WK_UP_Pin)

#define KEY0_PRES 		1
#define KEY1_PRES		2
#define KEY2_PRES		3
#define WKUP_PRES   	4

enum
{
	NoPress,
	K0Press,
	K1Press,
	K2Press,
	WK_UP_Presss
};

int16_t Key_Scan(int16_t mode);

void Key_Led(int16_t num);



#endif
