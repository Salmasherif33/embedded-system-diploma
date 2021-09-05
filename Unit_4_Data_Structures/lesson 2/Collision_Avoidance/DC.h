/*
 * DC.h
 *
 *  Created on: Sep 4, 2021
 *      Author: Salma Sherif
 */

#ifndef DC_H_
#define DC_H_

#include "stdio.h"
#include "stdlib.h"
#include "state.h"

enum{

	DC_idle,
	DC_busy

}DC_state_id;



//prototypes
void DC_init();
STATE_define(DC_idle);
STATE_define(DC_busy);


extern void (*DC_state)();

#endif /* DC_H_ */
