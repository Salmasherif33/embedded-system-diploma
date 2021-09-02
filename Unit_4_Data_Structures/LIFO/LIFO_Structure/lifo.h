/*
 * lifo.h
 *
 *  Created on: Sep 2, 2021
 *      Author: Salma Sherif
 */

#ifndef LIFO_H_
#define LIFO_H_


#include "stdio.h"
#include "stdint.h"


#define ELEMENT_TYPE	uint32_t		//default

// attributes of the LIFO
typedef struct{
	ELEMENT_TYPE* base;
	ELEMENT_TYPE* head;
	unsigned int length;
	unsigned int count;

}LIFO_struct;

//LIFO status
typedef enum{
	lifo_full,
	lifo_empty,
	lifo_null,
	lifo_no_error

}LIFO_status;



//interfaces
LIFO_status LIFO_init(LIFO_struct* stack, ELEMENT_TYPE* array, unsigned int length);
LIFO_status LIFO_push(LIFO_struct* stack, unsigned int item);
LIFO_status LIFO_pop(LIFO_struct* stack, ELEMENT_TYPE* item);
short is_full(LIFO_struct* stack);
short is_empty(LIFO_struct* stack);






#endif /* LIFO_H_ */
