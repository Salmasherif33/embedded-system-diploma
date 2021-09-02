/*
 * fifo.h
 *
 *  Created on: Sep 2, 2021
 *      Author: Salma Sherif
 */

#ifndef FIFO_H_
#define FIFO_H_



#include "stdio.h"
#include "stdint.h"


#define ELEMENT_TYPE	uint32_t		//default

// attributes of the LIFO
typedef struct{
	ELEMENT_TYPE* base;
	ELEMENT_TYPE* head;
	ELEMENT_TYPE* tail;
	unsigned int length;
	unsigned int count;

}FIFO_struct;

//LIFO status
typedef enum{
	fifo_full,
	fifo_empty,
	fifo_null,
	fifo_no_error

}FIFO_status;



//interfaces
FIFO_status FIFO_init(FIFO_struct* stack, ELEMENT_TYPE* array, unsigned int length);
FIFO_status FIFO_enqueue(FIFO_struct* stack, unsigned int item);
FIFO_status FIFO_dequeue(FIFO_struct* stack, ELEMENT_TYPE* item);
short is_full(FIFO_struct* stack);
short is_empty(FIFO_struct* stack);


#endif /* FIFO_H_ */
