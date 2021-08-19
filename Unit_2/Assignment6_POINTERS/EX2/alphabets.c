#include <stdio.h>

int main(){

	char x = 'A';
	char *ptr = &x;
	printf("The Alphabets are:\n");
	int i;
	for(i =0; i < 26; i++){
		printf("%c ",(*ptr)++);
	}
	return 0;
}
