/*
 * DC.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Salma Sherif
 */


#include "DC.h"

unsigned int DC_speed = 0;

void (* DC_state)();	//function to pointer


void DC_init(){
	//init PWM driver
	printf("init DC\n");
}


void DC_set_speed(int s){
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("CA-------speed = %d------>DC\n", DC_speed);

}


STATE_define(DC_busy){

	//state name
	DC_state_id = DC_busy;
	//state action
	//call PWM to make speed = DC_speed  embedded

	printf("DC_busy state: speed = %d\n",DC_speed);

	//auto will be changed to idle
	DC_state = STATE(DC_idle);

}

STATE_define(DC_idle){
	DC_state_id = DC_idle;

	//call PWM to make speed = DC_speed  embedded

	printf("DC_idel state: speed = %d\n",DC_speed);

	//we will not go to busy state except if there is an event will change it, when CA call set_speed
}


