/*
 * US.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Salma Sherif
 */


#include "US.h"

unsigned int US_distance = 0;

void (* US_state)();	//function to pointer
int generate_random(int l, int r, int c);

void US_init(){
	//init US driver
	printf("init US\n");
}

STATE_define(US_busy){	//reading...

	//state name
	US_state_id = US_busy;
	//state action
	US_distance = generate_random(45,55, 1);

	US_set_distance(US_distance);
	printf("US_busy state: distance = %d  \n",US_distance);
	US_state = STATE(US_busy); //loop

}

int generate_random(int l, int r, int c){
	int i;
	for(i = 0; i < c; i++){
		int rand_num = (rand() % (r-l+1)) + l;
		return rand_num;
	}

}


