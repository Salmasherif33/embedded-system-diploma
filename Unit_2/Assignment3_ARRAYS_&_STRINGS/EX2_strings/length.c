#include <stdio.h>

int main (){

	char str [100];
	printf("Enter a string: ");
	fflush(stdout); fflush(stdin);
	gets(str);

	int c = 0, i;
	for(i = 0; str[i] != 0; i++){
		c++;
	}
	printf("Length of string: %d",c);
	return 0;
}
