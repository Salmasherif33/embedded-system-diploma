#include <stdio.h>
#include <string.h>

int main (){

	char arr[100];
	char*ptr = arr;
	printf("Input a string : ");
	fflush(stdout); fflush(stdin);
	scanf("%s",ptr);

	int i;
	for(i=strlen(ptr)-1; i >=0 ; i--){
		printf("%c", *(ptr+i));

	}
	return 0;
}
