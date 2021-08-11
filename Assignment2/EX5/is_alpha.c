#include <stdio.h>
#include <ctype.h>

int main (){

	char in;

	printf("Enter a character: ");
	fflush(stdout); fflush(stdin);

	scanf("%c",&in);

	if(isalpha(in))
		printf("%c is an alphabet", in);
	else
		printf("%c is not an alphabet", in);


	/*
	 * or we could check the range of the char if it is between the
	 * ascii code of a and z ,
	 * or between the ascii code of A and Z, then it is alpha
	 *
	 * */
	return 0;
}
