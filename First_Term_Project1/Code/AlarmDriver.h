/*
 * AlarmDriver.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Salma Sherif
 */

#ifndef ALARMDRIVER_H_
#define ALARMDRIVER_H_

#include "driver.h"
#include "states.h"



enum{
	AlarmOn,
	AlarmOff

}AL_state_id;

void Alarm_init();
STATE_define(AlarmOn);
STATE_define(AlarmOff);


extern void (*Alarm_state)();

#endif /* ALARMDRIVER_H_ */
