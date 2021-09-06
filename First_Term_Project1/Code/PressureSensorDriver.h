/*
 * PressureSensor.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Salma Sherif
 */

#ifndef PRESSURESENSORDRIVER_H_
#define PRESSURESENSORDRIVER_H_

#include "states.h"
#include "driver.h"
//#include "stdlib.h"

enum{
	PS_reading,
	PS_waiting
}PS_states_id;


void PS_init();
STATE_define(PS_reading);

extern void (*PS_state)();
#endif /* PRESSURESENSORDRIVER_H_ */
