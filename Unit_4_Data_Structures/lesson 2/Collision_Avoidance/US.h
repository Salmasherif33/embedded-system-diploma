/*
 * US.h
 *
 *  Created on: Sep 4, 2021
 *      Author: Salma Sherif
 */

#ifndef US_H_
#define US_H_

#include "stdio.h"
#include "stdlib.h"
#include "state.h"

enum{

	US_busy,


}US_state_id;


//prototypes
void US_init();
STATE_define(US_busy);

extern void (*US_state)();

#endif /* US_H_ */
