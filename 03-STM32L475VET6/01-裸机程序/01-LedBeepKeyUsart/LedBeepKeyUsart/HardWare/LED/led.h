#ifndef __LED_H__
#define __LED_H__

#include "stm32l4xx_hal.h"
#include "main.h"

#define LED_R(n) (n?HAL_GPIO_WritePin(LED_R_GPIO_Port,LED_R_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,GPIO_PIN_RESET))
#define LED_G(n) (n?HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin,GPIO_PIN_RESET))
#define LED_B(n) (n?HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin,GPIO_PIN_RESET))

#define LED_R_TOGGLE (HAL_GPIO_TogglePin(LED_R_GPIO_Port,LED_R_Pin))
#define LED_G_TOGGLE (HAL_GPIO_TogglePin(LED_G_GPIO_Port,LED_G_Pin))
#define LED_B_TOGGLE (HAL_GPIO_TogglePin(LED_B_GPIO_Port,LED_B_Pin))

void LedBlink(void);

#endif

