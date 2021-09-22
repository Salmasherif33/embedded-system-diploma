/*
 * 7segment.c
 *
 *  Created on: Sep 22, 2021
 *      Author: lenovo
 */

#include "7_segment.h"

GPIO_PinConfig_t pinConfig;

void SEG_INIT(void){
	pinConfig.GPIO_PinNumber = GPIO_PIN_9;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

	pinConfig.GPIO_PinNumber = GPIO_PIN_10;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

	pinConfig.GPIO_PinNumber = GPIO_PIN_11;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

	pinConfig.GPIO_PinNumber = GPIO_PIN_12;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

	pinConfig.GPIO_PinNumber = GPIO_PIN_13;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

	pinConfig.GPIO_PinNumber = GPIO_PIN_14;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

	pinConfig.GPIO_PinNumber = GPIO_PIN_15;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(GPIOB, &pinConfig);
}

