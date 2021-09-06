/*
 * main.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Salma Sherif
 */

#include "AlarmDriver.h"
#include "PressureSensorDriver.h"
#include "MainController.h"
#include "AlarmDriver.h"


void setup(){
	//init STM
	GPIO_INITIALIZATION();

	//init sensor
	PS_init();
	//init alarm
	Alarm_init();
}

int main (){

	setup();

	while (1)
	{

		PS_state();
		C_state();
		Alarm_state();
		Delay(1000);
	}

	return 0;
}
