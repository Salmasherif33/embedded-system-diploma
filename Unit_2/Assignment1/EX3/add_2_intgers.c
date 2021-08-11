#include <stdio.h>

int main (){
	printf("##########Console-output###\n");

	int input1, input2;
	printf("Enter two integers: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &input1);
	scanf("%d",&input2);

	printf("Sum %d\n", input1+input2);

	printf("###########################");

	return 0;
}
