#include <stdio.h>
#include <ctype.h>

int main (){

	char in;
	printf("Enter an alphabet: ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&in);

	switch(tolower(in)){
	case 'i':
		printf("%c is a vowel.",in);
		break;

	case 'a':
		printf("%c is a vowel.",in);
		break;
	case 'e':
		printf("%c is a vowel.",in);
		break;
	case 'o':
		printf("%c is a vowel.",in);
		break;

	case 'u':
		printf("%c is a vowel.",in);
		break;

	default:
		printf("%c is a consonant.",in);
		break;
	}


	return 0;
}
