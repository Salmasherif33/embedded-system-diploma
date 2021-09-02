/*
 * lifo.c
 *
 *  Created on: Sep 2, 2021
 *      Author: Salma Sherif
 */


#include "lifo.h"

LIFO_status LIFO_init(LIFO_struct* stack, ELEMENT_TYPE* array, unsigned int length){
	if(!stack)
		return lifo_null;

	stack->base = array;
	stack->head = array;
	stack->length = length;
	stack->count = 0;

	return lifo_no_error;
}

LIFO_status LIFO_push(LIFO_struct* stack, ELEMENT_TYPE item){
	if(!stack->base || !stack->head || !stack)
		return lifo_null;

	if(is_full(stack))
		return lifo_full;

	*(stack->head) = item;
	stack->head++;
	stack->count++;
	return lifo_no_error;


}

LIFO_status LIFO_pop(LIFO_struct* stack, ELEMENT_TYPE* item){
	if(!stack->base || !stack->head || !stack)
		return lifo_null;

	if(is_empty(stack))
		return lifo_empty;

	stack->head--;
	stack->count--;
	*item = *(stack->head);
	return lifo_no_error;

}

short is_full(LIFO_struct* stack){
	if(!stack->base || !stack->head || !stack)
		return 1;

	if(stack->length == stack->count)
		return 1;

	return 0;
}

short is_empty(LIFO_struct* stack){
	if(!stack->base || !stack->head)
		return 1;

	if(stack->count == 0 )
		return 1;

	return 0;
}