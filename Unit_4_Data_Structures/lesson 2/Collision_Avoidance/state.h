/*
 * state.h
 *
 *  Created on: Sep 4, 2021
 *      Author: Salma Sherif
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE_define(_stateFunc_)    void ST_##_stateFunc_()
#define STATE(_stateFunc_)			 ST_##_stateFunc_


//state connection (interfaces between modules)

void US_set_distance(int d); //define in the target
void DC_set_speed(int s);

#endif /* STATE_H_ */
