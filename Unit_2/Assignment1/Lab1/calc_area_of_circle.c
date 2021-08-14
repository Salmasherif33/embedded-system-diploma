#include <stdio.h>
#define PI 3.14

int main(){

	float rad;
	char c;
	printf("Enter circle raduis: ");
	fflush(stdout); fflush(stdin);

	scanf("%f",&rad);

	printf("Enter your choice (a to print the area, c to print the circumference): ");
	fflush(stdout); fflush(stdin);

	scanf("%c",&c);

	if(c =='a')
		printf("area is %f", PI*(rad*rad));
	else if(c == 'c')
		printf("circumference is %f", 2*PI*rad);
	else
		printf("ERROR!");
	return 0;
}
