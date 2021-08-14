#include <stdio.h>
#include <string.h>

void reverse_string (char str[]);

int main (){
	char s [100];
	printf("Enter a sentence: ");
	fflush(stdout); fflush(stdin);
	gets(s);

	reverse_string(s);
	return 0;
}


void reverse_string (char str[]){

	int i;
	for(i = strlen(str) -1 ; i >= 0; i--){
		printf("%c", str[i]);
	}

}
