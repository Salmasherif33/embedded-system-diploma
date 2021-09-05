/*
 * CA.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Salma Sherif
 */


#include "CA.h"

unsigned int distance = 0, speed = 0, threshold = 50;

void (* CA_state)();	//function to pointer


void US_set_distance(int d){
	//check event, this function is event trigger, where it changes the event
	distance = d;
	(distance <=threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("US-------distance = %d------>CA\n", distance);
}


STATE_define(CA_waiting){

	//state name
	CA_state_id = CA_waiting;
	//state action
	speed = 0;
	DC_set_speed(speed);

	printf("Waiting state: distance = %d  speed = %d\n",distance, speed);

}

STATE_define(CA_driving){
	CA_state_id = CA_driving;

	speed = 30;
	DC_set_speed(speed);

	printf("driving state: distance = %d  speed = %d\n",distance, speed);

}

