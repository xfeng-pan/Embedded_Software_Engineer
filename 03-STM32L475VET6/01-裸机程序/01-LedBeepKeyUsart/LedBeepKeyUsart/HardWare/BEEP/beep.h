#ifndef __BEEP_H__
#define __BEEP_H__

#include "stm32l4xx_hal.h"
#include "main.h"

#define BEE_O(n)	(n?HAL_GPIO_WritePin(BEEP_GPIO_Port,BEEP_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(BEEP_GPIO_Port,BEEP_Pin,GPIO_PIN_RESET))


void BeepBlink(void);



#endif
