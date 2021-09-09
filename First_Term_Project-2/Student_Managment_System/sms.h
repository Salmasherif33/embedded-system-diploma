
/*
 * sms.h
 *
 *  Created on: Sep 8, 2021
 *      Author: Salma Sherif
 */

#ifndef SMS_H_
#define SMS_H_



#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"

#define ELEMENT_TYPE	student		//default
#define DPRINTF(...)	{fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}


typedef struct {
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int course_id[5];
}student;



// attributes of the FIFO
typedef struct {
	ELEMENT_TYPE* base;
	ELEMENT_TYPE* head;
	ELEMENT_TYPE* tail;
	unsigned int length;
	unsigned int count;

}FIFO_struct;

//FIFO status
typedef enum {
	fifo_full,
	fifo_empty,
	fifo_null,
	fifo_no_error

}FIFO_status;



//interfaces
FIFO_status FIFO_init(FIFO_struct* queue, ELEMENT_TYPE* array, unsigned int length);

void add_student_file();
void add_student_manually(FIFO_struct* queue);
void Add_from_file(FIFO_struct* queue, char line[50][9]);
int find_by_role(int roll, FIFO_struct* queue, ELEMENT_TYPE** s);
void find_by_fname(char fname[], FIFO_struct* queue);
void find_by_course(FIFO_struct* queue, int cid);
int total_number(FIFO_struct* queue);
void delete_by_roll(FIFO_struct* queue, int roll, ELEMENT_TYPE* array);
void update(FIFO_struct* queue, int id);
void show_all(FIFO_struct* queue);
#endif /* SMS_H_ */
