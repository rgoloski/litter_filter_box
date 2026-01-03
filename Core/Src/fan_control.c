/*
 * fan_control.c
 *
 *  Created on: Dec 31, 2025
 *      Author: rgolo
 */

#include "stdbool.h"

#include "fan_control.h"
#include "tim.h"

#include "stm32f4xx_hal_gpio.h"

extern TIM_HandleTypeDef htim1;

static bool initialized = false;

void run_duty_control(void)
{
	if (!initialized)
	{
	    MX_TIM1_SetDuty(25);
	    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
	    initialized = true;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == B1_Pin)
	{
		// Handle button here
	}
}
