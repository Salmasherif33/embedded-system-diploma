#include <stdio.h>
#include <string.h>

int main (){

	char str[100];
	printf("Enter s string: ");
	fflush(stdout); fflush(stdin);
	gets(str);


	char ser;
	printf("Enter a character to find frequency: ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&ser);

	int i,count =0;
	for(i = 0; i < strlen(str); i++){
		if(str[i] == ser)
			count++;
	}
	printf("Frequency of %c = %d",ser,count);
	return 0;
}
