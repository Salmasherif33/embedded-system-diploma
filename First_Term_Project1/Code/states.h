/*
 * states.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Salma Sherif
 */


#ifndef STATES_H_
#define STATES_H_

#define STATE_define(_stateFunc_)    void ST_##_stateFunc_()
#define STATE(_stateFunc_)			 ST_##_stateFunc_

void get_pressure_value(int P);
void Set_Alarm_actuator(int i);

#endif /* STATES_H_ */
