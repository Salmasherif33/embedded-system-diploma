/*
 * fifo.c
 *
 *  Created on: Sep 2, 2021
 *      Author: Salma Sherif
 */



#include "fifo.h"


FIFO_status FIFO_init(FIFO_struct* stack, ELEMENT_TYPE* array, unsigned int length){
	if(!stack)
		return fifo_null;

	stack->base = array;
	stack->head = array;
	stack->tail = array;
	stack->length = length;
	stack->count = 0;
	if(stack->base && stack->head)
		return fifo_no_error;

	else
		return fifo_null;
}

FIFO_status FIFO_enqueue(FIFO_struct* stack, ELEMENT_TYPE item){

	if(!stack || !stack->head || !stack->tail || !stack->base)
		return fifo_null;

	if(is_full(stack))
		return fifo_full;

	if(stack->base +(stack->length* sizeof(ELEMENT_TYPE)) == stack->tail){
		*(stack->tail) = item;
		stack->tail = stack->base;
	}
	else{
		*(stack->tail) = item;
		stack->tail++;
	}
	stack->count++;
	return fifo_no_error;

}

FIFO_status FIFO_dequeue(FIFO_struct* stack, ELEMENT_TYPE* item){
	if(!stack || !stack->head || !stack->tail || !stack->base)
		return fifo_null;
	if(is_empty(stack))
		return fifo_empty;

	if(stack->base +(stack->length* sizeof(ELEMENT_TYPE)) == stack->head){
		*item = *(stack->head);
		stack->tail = stack->base;
	}
	else{
		*item = *(stack->head);
		stack->head++;
	}
	stack->count--;


	return fifo_no_error;


}

short is_full(FIFO_struct* stack){
	if(!stack->base || !stack->head || !stack->tail || !stack)
		return 1;

	if(stack->length == stack->count)
		return 1;


	return 0;
}

short is_empty(FIFO_struct* stack){
	if(!stack->base || !stack->head || !stack->tail || !stack)
		return 1;

	if(stack->count == 0 )
		return 1;

	return 0;
}


