#include <stdio.h>
#include <string.h>

int main (){

	char str [100];
	printf("Enter a string: ");
	fflush(stdout); fflush(stdin);
	gets(str);


	int i;
	printf("Reverse string is: ");
	for(i = strlen(str) - 1; i >=0 ; i--){
		printf("%c",str[i]);
	}
	return 0;

}
