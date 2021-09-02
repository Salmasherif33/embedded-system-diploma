/*
 * main.c
 *
 *  Created on: Sep 2, 2021
 *      Author: Salma Sherif
 */


#include "lifo.h"

int main(){

	LIFO_struct numbers;
	ELEMENT_TYPE array[5];

	LIFO_init(&numbers, array, 5);
	unsigned int i;
	for(i = 0; i < 7; i++){
		if(LIFO_push(&numbers,i) == lifo_no_error)
			printf("item : %d is pushed\n", i);

		else
			printf("FAILED to push \n\n");
	}

	unsigned int temp;
	for(i = 0; i < 7; i++){
		if(LIFO_pop(&numbers,&temp) == lifo_no_error)
			printf("Item : %d is popped \n",temp);

		else
			printf("FALIED to pop\n");

	}
	return 0;

}