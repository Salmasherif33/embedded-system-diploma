/*
 * main.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Salma Sherif
 */

#include "CA.h"
#include "DC.h"
#include "US.h"

void setup(){

	//init.
	US_init();
	DC_init();

	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

int main(){

	volatile int d;
	setup();
	while(1){
		US_state();
		CA_state(); //call the function;
		DC_state();
		//delay
		for(d = 0; d <= 1000;d++);
	}
	return 0;
}


