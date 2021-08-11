#include <stdio.h>
#include <ctype.h>

int main (){

	int in;

	printf("Enter an integer: ");
	fflush(stdout); fflush(stdin);

	scanf("%d",&in);

	int fact = 1;

	if(in == 0)
		printf("Factorial = %d", fact);
	else if(in < 0)
		printf("Error!!! Factorial of negative number doesn't exist");

	else{
		int i;
		for(i=2; i <= in; i++)
			fact *= i;
		printf("Factorial = %d", fact);
	}

	return 0;
}
