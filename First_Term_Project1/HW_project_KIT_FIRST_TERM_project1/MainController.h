/*
 * MainController.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Salma Sherif
 */

#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_

#include "driver.h"
#include "states.h"
#include "PressureSensorDriver.h"


enum{
	idle,
	HP_detected

}C_id;

STATE_define(HP_detected);
STATE_define(idle);


extern void (*C_state)();

#endif /* MAINCONTROLLER_H_ */
