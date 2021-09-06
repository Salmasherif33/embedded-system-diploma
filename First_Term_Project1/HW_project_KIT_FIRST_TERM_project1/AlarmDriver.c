/*
 * AlarmDriver.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Salma Sherif
 */


#include "AlarmDriver.h"

int duration = 60;

void (*Alarm_state)();


void Alarm_init(){
	Alarm_state = STATE(AlarmOff);
	//printf("init Alarm driver\n");
}

void Set_Alarm_actuator(int i){
	if (i == 1){
		SET_BIT(GPIOA_ODR,13);
		Alarm_state = STATE(AlarmOn);

	}
	else if (i == 0){
		RESET_BIT(GPIOA_ODR,13);
		Alarm_state = STATE(AlarmOff);
	}
}

STATE_define(AlarmOn){
//	printf("Alarm is ONNNNNN!!\n");
	AL_state_id = AlarmOn;
//	printf("Delaaaaay!!!\n");
	Delay(duration*1000); //delay 60 sec
	Alarm_state = STATE(AlarmOff);


}

STATE_define(AlarmOff){
	//printf("Alarm is OFFF!!\n");
	AL_state_id = AlarmOff;
}


