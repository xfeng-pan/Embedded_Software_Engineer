#include "key.h"

//mode: 0/1
//0:不支持连按
//1:支持连按

int16_t Key_Scan(int16_t mode)
{	
	static int16_t keystatus=1;
	if(mode==1) keystatus=1;
	
	if(keystatus&&(KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
	{
		HAL_Delay(10);
		keystatus=0;	
		if(0==KEY0) return K0Press;
		else if(0==KEY1) return K1Press;
		else if(0==KEY2) return K2Press;
		else if(1==WK_UP) return WK_UP_Presss;
	}
	else if(KEY0==1&&1==KEY1&&1==KEY2&&WK_UP==0) keystatus=1;
	
	return 0;
	
}


void Key_Led(int16_t num)
{
	switch(num)
	{
		case 1:
			HAL_GPIO_TogglePin(LED_R_GPIO_Port,LED_R_Pin);
		break;
		
		case 2:
			HAL_GPIO_TogglePin(LED_G_GPIO_Port,LED_G_Pin);
		break;
		
		case 3:	
			HAL_GPIO_TogglePin(LED_B_GPIO_Port,LED_B_Pin);
		break;
		
		case 4:
			HAL_GPIO_TogglePin(BEEP_GPIO_Port,BEEP_Pin);
		break;
		
		default:
			;
		
	}
}






