#include <stdio.h>

struct SStudent{

	char name[50];
	int roll;
	float marks;
};

int main(){

	struct SStudent student;
	printf("Enter information of a student:\n");
	printf("Enter name: ");
	fflush(stdout); fflush(stdin);
	scanf("%s", student.name);

	printf("Enter roll number: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &student.roll);

	printf("Enter marks: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &student.marks);

	printf("Displaying information\n");
	printf("name: %s\n",student.name);
	printf("roll: %d\n",student.roll);
	printf("marks: %0.2f\n",student.marks);

	return 0;
}
