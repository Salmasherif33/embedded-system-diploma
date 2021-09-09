/*
 * sms.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Salma Sherif
 */



#include "sms.h"
FIFO_status FIFO_enqueue(FIFO_struct* queue, ELEMENT_TYPE item);
FIFO_status FIFO_dequeue(FIFO_struct* queue, ELEMENT_TYPE* item);
short is_full(FIFO_struct* queue);
short is_empty(FIFO_struct* queue);
short Course_Exist(int cid, int arr[]);

FIFO_status FIFO_init(FIFO_struct* queue, ELEMENT_TYPE* array, unsigned int length) {
	if (!queue)
		return fifo_null;

	queue->base = array;
	queue->head = array;
	queue->tail = array;
	queue->length = length;
	queue->count = 0;
	if (queue->base && queue->head)
		return fifo_no_error;

	else
		return fifo_null;
}

FIFO_status FIFO_enqueue(FIFO_struct* queue, ELEMENT_TYPE item) {

	if (!queue || !queue->head || !queue->tail || !queue->base)
		return fifo_null;

	if (is_full(queue)) {
		DPRINTF("The array is full\n");
		return fifo_full;
	}

	if (queue->base + (queue->length * sizeof(ELEMENT_TYPE)) == queue->tail) {
		*(queue->tail) = item;
		queue->tail = queue->base;
	}
	else {
		*(queue->tail) = item;
		queue->tail++;
	}
	queue->count++;
	return fifo_no_error;

}

FIFO_status FIFO_dequeue(FIFO_struct* queue, ELEMENT_TYPE* item) {
	if (!queue || !queue->head || !queue->tail || !queue->base)
		return fifo_null;
	if (is_empty(queue))
		return fifo_empty;

	if (queue->base + (queue->length * sizeof(ELEMENT_TYPE)) == queue->head) {
		*item = *(queue->head);
		queue->tail = queue->base;
	}
	else {
		*item = *(queue->head);
		queue->head++;
	}
	queue->count--;


	return fifo_no_error;


}

short is_full(FIFO_struct* queue) {
	if (!queue->base || !queue->head || !queue->tail || !queue)
		return 1;

	if (queue->length == queue->count)
		return 1;


	return 0;
}

short is_empty(FIFO_struct* queue) {
	if (!queue->base || !queue->head || !queue->tail || !queue)
		return 1;

	if (queue->count == 0)
		return 1;

	return 0;
}

void Add_from_file(FIFO_struct* queue, char line[50][9]) {
	
	student s,*s1;

	s.roll = atoi(line[0]);
	strcpy(s.fname, line[1]);
	strcpy(s.lname, line[2]);
	s.GPA = atof(line[3]);
	for (int i = 0; i < 5; i++) {
		s.course_id[i] = atoi(line[i + 4]);
	}

	if (find_by_role(s.roll, queue, &s1) != -1) {
		DPRINTF("\n==================================\n");
		DPRINTF("Roll number %d is already taken\n", s.roll);
		DPRINTF("\n==================================\n");
		return;
	}
	if (FIFO_enqueue(queue, s) != fifo_no_error) {
		DPRINTF("\n==================================\n");
		DPRINTF("SOMeTHING WINT WRONG WHILE ENQueuing\n");
		DPRINTF("\n==================================\n");
		return;
	}
	DPRINTF("\n==================================\n");
	DPRINTF("Roll number %d is inserted successfully", s.roll);
	

	
}


void add_student_manually(FIFO_struct* queue) {
	DPRINTF("\n==================================\n");

	DPRINTF("Add the students details\n");
	student s1;
	DPRINTF("Enter the roll number : ");
	scanf("%d", &s1.roll);
	DPRINTF("\nEnter the first name of student : ");
	scanf("%s", s1.fname);
	DPRINTF("\n Enter the last name: ");
	scanf("%s", s1.lname);
	DPRINTF("\nEnter the GPA you obtained : ");
	scanf("%f", &s1.GPA);
	DPRINTF("\n Enter the course id of each course : ");
	for (int i = 0; i < sizeof(s1.course_id) / sizeof(int); i++) {
		DPRINTF("\n Course %d id : ", i + 1);
		scanf("%d", &s1.course_id[i]);
	}


	student* s;
	if (find_by_role(s1.roll, queue, &s)!= -1) {
		DPRINTF("\n==================================\n");
		DPRINTF("Roll number %d is already taken\n", s1.roll);
		DPRINTF("\n==================================\n");
		return;
	}
	if (FIFO_enqueue(queue, s1) != fifo_no_error) {
		DPRINTF("\n==================================\n");
		DPRINTF("SOMeTHING WINT WRONG WHILE ENQueuing\n");
		DPRINTF("\n==================================\n");
		return;
	}
	DPRINTF("\n==================================\n");
	DPRINTF("The student is inserted successfully");
	DPRINTF("\n==================================\n");

}

void delete_by_roll(FIFO_struct* queue, int roll, ELEMENT_TYPE * array) {
	ELEMENT_TYPE* s;
	int i = find_by_role(roll, queue, &s);
	if ( i== -1) {
		DPRINTF("\n==================================\n");
		DPRINTF("This roll number %d not found", roll);
		DPRINTF("\n==================================\n");
		return;
	}
	ELEMENT_TYPE x1 = array[0];
	ELEMENT_TYPE x2 = array[1];
	ELEMENT_TYPE x3 = array[2];
	
	ELEMENT_TYPE temp = *(queue->head);
	*(queue->head) = *s;
	*s = temp;
	
	x1 = array[0];
	x2 = array[1];
	x3 = array[2];

	FIFO_dequeue(queue, &temp);

	DPRINTF("\n==================================\n");
	DPRINTF("The roll number is removed successfully");
	DPRINTF("\n==================================\n");

}


int find_by_role(int roll, FIFO_struct* queue, ELEMENT_TYPE** s) {
	student* current = queue->head;
	int i = -1;
	while (current != queue->tail) {
		i++;
		if (current->roll == roll) {
			*s = current;
			/*s->GPA = current->GPA;
			s->roll = current->roll;
			for (int i = 0; i < 50; i++) {
				if (i < 5) {
					s->course_id[i] = current->course_id[i];
				}
				s->fname[i] = current->fname[i];
				s->lname[i] = current->lname[i];
			}*/
			return i;

		}
		current++;
	}
	return -1;
}


void find_by_fname(char fname[], FIFO_struct* queue) {
	student* current = queue->head;
	char f = 'f';
	while (current != queue->tail) {
		if (!strcmp(current->fname, fname)) {
			f = 't';
			DPRINTF("\n==================================\n");
			DPRINTF("The student details are \n");
			DPRINTF("The first name is %s\n", current->fname);
			DPRINTF("The last name is %s\n", current->lname);
			DPRINTF("The roll number is %d\n", current->roll);
			DPRINTF("The GPA is %.1f \n", current->GPA);
			for (int i = 0; i < 5; i++) {
				DPRINTF("The course ID is %d\n", current->course_id[i]);
			}
			DPRINTF("\n==================================\n");

		}
		current++;
	}

	if (current == queue->tail && f == 'f') {
		DPRINTF("\n==================================\n");
		DPRINTF("First name %s is not found\n", fname);
		DPRINTF("\n==================================\n");
	}

}



short Course_Exist(int cid, int arr[]) {
	for (int i = 0; i < 5; i++) {
		if (arr[i] == cid)
			return 1;
	}
	return 0;
}



void find_by_course(FIFO_struct* queue, int cid) {
	student* current = queue->head;
	char f = 'f';
	DPRINTF("\n==================================\n");
	while (current != queue->tail) {
		f = 't';
		if (Course_Exist(cid, current->course_id)) {
			DPRINTF("The students details are\n");
			DPRINTF("The first name is %s\n", current->fname);
			DPRINTF("The last name is %s \n", current->lname);
			DPRINTF("The roll number is %d\n", current->roll);
			DPRINTF("The GPA is %.1f\n", current->GPA);
			DPRINTF("\n==================================\n");
		}
		current++;
	}
	if (f == 'f') {
		DPRINTF("Course ID %d not found\n", cid);
		DPRINTF("\n==================================\n");
	}
}

int total_number(FIFO_struct* queue) {
	return queue->count;
}

void update(FIFO_struct* queue, int id) {
	student* s;
	int cid;
	if (find_by_role(id, queue, &s) == -1) {
		DPRINTF("\n==================================\n");
		DPRINTF("This roll number %d is not found", id);
		DPRINTF("\n==================================\n");
		return;
	}

	DPRINTF("\n 1. first name");
	DPRINTF("\n 2. Last name");
	DPRINTF("\n 3. roll no.");
	DPRINTF("\n 4. GPA\n");
	for(int i = 0 ; i < 5; i++)
		DPRINTF(" %d. Course %d\n",i+5 , i+1);
	int choise; 
	scanf("\n%d", &choise);
	switch (choise)
	{
	case 1:
		DPRINTF("\n Enter the new first name: ");
		char fname[50];
		scanf("%s", fname);
		strcpy(s->fname, fname);
		DPRINTF("\n==================================\n");
		DPRINTF("UPDATED SUCCESSFULLY");
		break;

	case 2:
		DPRINTF("\n Enter the new last name: ");
		char lname[50];
		scanf("%s", lname);
		strcpy(s->fname, fname);
		DPRINTF("\n==================================\n");
		DPRINTF("UPDATED SUCCESSFULLY");
		break;

	case 3:
		DPRINTF("\nEnter the new roll number: ");
		int roll;
		scanf("%d", &roll);

		if (find_by_role(roll, queue, &s) != -1) {
			DPRINTF("\n==================================\n");
			DPRINTF("This roll number is assigned for another student");
		}
		else {
			(s->roll) = roll;
			DPRINTF("\n==================================\n");
			DPRINTF("UPDATED SUCCESSFULLY");
		}

		break;

	case 4:
		DPRINTF("Enter the new GPA: ");
		float gpa;
		scanf("%f", &gpa);
		s->GPA = gpa;
		DPRINTF("\n==================================\n");
		DPRINTF("UPDATED SUCCESSFULLY");

		break;

	case 5:
		DPRINTF("Enter the new course ID: ");
		
		scanf("%d", &cid);
		s->course_id[0] = cid;
		DPRINTF("\n==================================\n");
		DPRINTF("UPDATED SUCCESSFULLY");
		break;


	case 6:
		DPRINTF("Enter the new course ID: ");
		
		scanf("%d", &cid);
		s->course_id[1] = cid;
		DPRINTF("\n==================================\n");
		DPRINTF("UPDATED SUCCESSFULLY");
		break;

	case 7:
		DPRINTF("Enter the new course ID: ");
		
		scanf("%d", &cid);
		s->course_id[2] = cid;
		DPRINTF("\n==================================\n");
		DPRINTF("UPDATED SUCCESSFULLY");
		break;

	case 8:
		DPRINTF("Enter the new course ID: ");
	
		scanf("%d", &cid);
		s->course_id[3] = cid;
		DPRINTF("\n==================================\n");
		DPRINTF("UPDATED SUCCESSFULLY");
		break;

	case 9:
		DPRINTF("Enter the new course ID: ");
		
		scanf("%d", &cid);
		s->course_id[4] = cid;
		DPRINTF("\n==================================\n");
		DPRINTF("UPDATED SUCCESSFULLY");
		break;

	default:
		break;
	}
	DPRINTF("\n==================================\n");

}

void show_all(FIFO_struct* queue) {
	if (is_empty(queue)) {
		DPRINTF("The list is Empty\n");
	}
	ELEMENT_TYPE* current = queue->head;
	while (current != queue->tail) {
		DPRINTF("\n==================================\n");
		DPRINTF("\n Student First name: %s", current->fname);
		DPRINTF("\n Student Last name: %s", current->lname);
		DPRINTF("\n Student Roll number: %d", current->roll);
		DPRINTF("\n Student GPA: %f", current->GPA);
		for (int i = 0; i < sizeof(current->course_id) / sizeof(int); i++) {
			DPRINTF("\n The Course ID is %d", current->course_id[i]);
		}
		current++;
	}
	DPRINTF("\n==================================\n");

}



