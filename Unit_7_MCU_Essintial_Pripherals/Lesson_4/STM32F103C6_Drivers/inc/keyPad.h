/*
 * keyPad.h
 *
 * Created: 9/20/2021 3:48:53 AM
 *  Author: lenovo
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stm32f103c6_gpio_driver.h"
#include "STM32F103C6_Header_Driver.h"


#define KEYPAD_PORT GPIOB

#define R0	GPIO_PIN_0
#define R1	GPIO_PIN_1
#define R2	GPIO_PIN_3
#define R3	GPIO_PIN_4
#define C0	GPIO_PIN_5
#define C1	GPIO_PIN_6
#define C2	GPIO_PIN_7
#define C3	GPIO_PIN_8

void KEYPAD_INIT(void);
char KEYPAD_GET_CHAR(void);

#endif /* KEYPAD_H_ */
