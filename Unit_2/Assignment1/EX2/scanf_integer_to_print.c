#include <stdio.h>

int main (){
	printf("##########Console-output###\n");

	int input;
	printf("Enter an integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &input);
	printf("You entered %d\n", input);

	printf("###########################");

	return 0;
}
