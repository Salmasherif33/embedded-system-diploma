/*
 * MainController.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Salma Sherif
 */


#include "MainController.h"


 int threshold = 20;

 void (*C_state)() = STATE(idle);



 void get_pressure_value(int P){
	// printf("Sensor reads :  %d\n", P);

	 if (P > 20){
		 C_state = STATE(HP_detected);

	 }else{
		 C_state = STATE(idle);
	 }
 }

 STATE_define(HP_detected){
	 C_id = HP_detected;
	// printf("Controller in HP detected state .....\n");
	 Set_Alarm_actuator(1);
	 C_state = STATE(idle);

 }

 STATE_define(idle){
	 Set_Alarm_actuator(0);
	 C_id = idle;
	// printf("Controller in idle state .....\n");

 }
