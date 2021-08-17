#include <stdio.h>

struct SStudent{

	char name[50];
	int roll;
	float marks;
};

int main(){

	struct SStudent students [10];
	printf("Enter information of students: \n");
	int i;
	for(i = 0; i < 10; i++){
		printf("For roll number %d\n",i+1);
		students[i].roll = i+1;
		printf("Enter name:");
		fflush(stdout); fflush(stdin);
		scanf("%s",students[i].name);

		printf("Enter marks:");
		fflush(stdout); fflush(stdin);
		scanf("%f",&students[i].marks);

	}

	printf("Displaying information of students:\n");
	for(i = 0; i < 10; i++){
		printf("Information for roll number %d",students[i].roll);
		printf("Name:%s \n",students[i].name);
		printf("Marks: %.1f\n",students[i].marks);


	}
	return 0;
}
