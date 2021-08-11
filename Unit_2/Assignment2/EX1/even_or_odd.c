#include <stdio.h>

int main (){

	int in;
	printf("Enter an integer you want to check: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&in);

	if(in %2 == 0)
		printf("%d is even", in);
	else
		printf("%d is odd", in);


	return 0;
}
