#include "led.h"


void LedBlink(void)
{
	LED_R(0);
	HAL_Delay(200);
	LED_G(0);
	HAL_Delay(300);
	LED_B(0);
	HAL_Delay(400);
	LED_R(1);
	HAL_Delay(200);
	LED_G(1);
	HAL_Delay(200);
	LED_B(1);
	
}



