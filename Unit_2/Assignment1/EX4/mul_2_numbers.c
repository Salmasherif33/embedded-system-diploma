#include <stdio.h>

int main (){
	printf("##########Console-output###\n");

	float input1, input2;
	printf("Enter two numbers: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &input1);
	scanf("%f",&input2);

	printf("Product %f\n", input1*input2);

	printf("###########################");

	return 0;
}
