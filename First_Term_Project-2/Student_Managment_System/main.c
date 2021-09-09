/*
 * main.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Salma Sherif
 */


#include "sms.h"


int main() {

	FIFO_struct studentsDB;
	student array[50];
	student* s;
	if (FIFO_init(&studentsDB, array, 50) == fifo_null) {
		printf("ERROR!!!\n");
		return 0;
	}

	int choice,id;
	DPRINTF("Welcome to the Student Management System\n");
	while (1) {
		DPRINTF("Choose The Task that you want to perform\n");
		DPRINTF("1. Add the student details manually\n");
		DPRINTF("2. Add the student details from text file\n");
		DPRINTF("3. Find the student details by roll number\n");
		DPRINTF("4. Find the student details by first name\n");
		DPRINTF("5. Find the student details by by course id\n");
		DPRINTF("6. Find the total number of students\n");
		DPRINTF("7. Delete the student details by roll number\n");
		DPRINTF("8. Update the student details by roll number\n");
		DPRINTF("9. Show all information\n");
		DPRINTF("10. To exit\n");
		DPRINTF("==================================\n");
		DPRINTF("Enter your choice to perform the task: \n");
		DPRINTF("==================================\n");

		scanf("%d", &choice);
		//choice  = 1;
		if (choice == 10)
			break;
		switch (choice) {

		case 1:
			add_student_manually(&studentsDB);
			//short flag;


			break;

		case 2:
			FILE * file = fopen("C:/Users/lenovo/source/repos/sms/test.txt", "r");
			char line[100];
			char st[50][9];//array of strings
			char* token;
			int i;
			while (!feof(file)) {
				fgets(line, 100, file);
				token = strtok(line, " ");
				i = 0;
				while (token != NULL) {
					strcpy(st[i], token);
					token = strtok(NULL, " ");
					i++;
				}
				Add_from_file(&studentsDB, st);

			}
			fclose(file);
			id = total_number(&studentsDB);
			DPRINTF("\nThe total number of students is : %d \n", id);
			DPRINTF("You can add up to 50 students \n");
			DPRINTF("You can add %d more students\n", 50 - id);
			DPRINTF("\n==================================\n");

			break;

		case 3:

			DPRINTF("Enter the roll number of the student :");
			DPRINTF("\n==================================\n");


			scanf("%d", &id);

			if (find_by_role(id, &studentsDB, &s) == -1) {
				DPRINTF("Roll number %d is not found\n", id);
				DPRINTF("==================================\n");
			}
			else {
				DPRINTF("\n==================================\n");
				DPRINTF("The students details are \n");
				DPRINTF("The first name is %s\n", s->fname);
				DPRINTF("The last name is %s\n", s->lname);
				DPRINTF("The GPA is %0.1f\n", s->GPA);
				for (int i = 0; i < 5; i++) {
					DPRINTF("The course ID is %d\n", s->course_id[i]);
				}
				DPRINTF("\n==================================\n");
			}
			break;

		case 4:
			DPRINTF("Enter the first name of the student : ");
			char name[50];
			scanf("%s", name);
			find_by_fname(name, &studentsDB);
			break;

		case 5:
			DPRINTF("Enter the course id :");
			int cid;
			scanf("%d", &cid);
			find_by_course(&studentsDB, cid);
			break;

		case 6:
			id = total_number(&studentsDB);
			DPRINTF("The total number of students is : %d \n", id);
			DPRINTF("You can add up to 50 students \n");
			DPRINTF("You can add %d more students\n", 50 - id);
			DPRINTF("\n==================================\n");
			break;

		case 7:
			DPRINTF("Enter the roll number which you want to delete");
			int roll;
			scanf("%d", &roll);
			delete_by_roll(&studentsDB, roll, array);
			break;

		case 8:
			DPRINTF("Enter the roll number to update the entry :");
			scanf("%d", &id);
			update(&studentsDB, id);
			break;

		case 9:
			show_all(&studentsDB);
			break;

		default:
			break;
		}
	}
	return 0;

}




