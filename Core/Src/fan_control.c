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

static const uint32_t duty_sequence[] = {25, 50, 75};
static const size_t duty_sequence_len = sizeof(duty_sequence) / sizeof(duty_sequence[0]);

static bool initialized = false;

//static uint32_t duty = duty_sequence[0];
static size_t duty_index = 0;

void run_duty_control(void)
{
	if (!initialized)
	{
	    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
	    initialized = true;
	}

	MX_TIM1_SetDuty(duty_sequence[duty_index]);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == B1_Pin)
	{
        // Increment by 5 but limit to 50% for now
//		duty += 10;
//		if (duty > 70)
//		{
//			duty = 10;
//		}
		duty_index = (duty_index + 1) % duty_sequence_len;
	}
}
