/*
 * main.c
 *
 *  Created on: Sep 2, 2021
 *      Author: Salma Sherif
 */

#include "fifo.h"

int main(){

	FIFO_struct numbers;
	ELEMENT_TYPE array[5];

	FIFO_init(&numbers, array, 5);
	unsigned int i;
	for(i = 0; i < 7; i++){
		if(FIFO_enqueue(&numbers,i) == fifo_no_error)
			printf("item : %d is enqueued\n", i);

		else
			printf("FAILED to enqueued \n\n");
	}

	unsigned int temp;
	for(i = 0; i < 7; i++){
		if(FIFO_dequeue(&numbers,&temp) == fifo_no_error)
			printf("Item : %d is dequeued \n",temp);

		else
			printf("FALIED to dequeued\n");

	}
	return 0;

}


