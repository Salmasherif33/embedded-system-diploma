#include <stdio.h>

int main (){

	float a,b;
	printf("Enter two numbers: ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f", &a, &b);

	if(a < b)
		printf("The minimum is %f", a);
	else if(a > b)
		printf("The minimum is %f ", b);
	else
		printf("Equal");
	return 0;
}
