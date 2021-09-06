/*
 * PressureSensorDriver.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Salma Sherif
 */

#include "PressureSensorDriver.h"
int getPressureVal();
//int generate_random(int l, int r, int c);




int pVal = 0;
void (*PS_state)();





void PS_init(){
	PS_state = STATE(PS_reading);
	//printf("INIT PS \n");
}

int getPressureVal(){
	//return generate_random(15,25,1);
	return (GPIOA_IDR & 0xFF);
}

STATE_define(PS_waiting){
	//printf("Sensor state : Waiting......\n");
	Delay(100000);
	PS_state = STATE(PS_reading);
}

STATE_define(PS_reading){
	PS_states_id = PS_reading;
//	printf("Sensor state : reading.....\n");
	pVal = getPressureVal();
	get_pressure_value(pVal);


	PS_state = STATE(PS_waiting);
}


// int generate_random(int l, int r, int c){
// 	int i;
// 	for(i = 0; i < c; i++){
// 		int rand_num = (rand() % (r-l+1)) + l;
// 		return rand_num;
// 	}

// }

