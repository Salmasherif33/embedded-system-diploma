/*
 * CA.h
 *
 *  Created on: Sep 4, 2021
 *      Author: Salma Sherif
 */

#ifndef CA_H_
#define CA_H_

#include "stdio.h"
#include "stdlib.h"
#include "state.h"

enum{

	CA_waiting,
	CA_driving

}CA_state_id;


//prototypes
STATE_define(CA_waiting);
STATE_define(CA_driving);


extern void (*CA_state)();

#endif /* CA_H_ */
