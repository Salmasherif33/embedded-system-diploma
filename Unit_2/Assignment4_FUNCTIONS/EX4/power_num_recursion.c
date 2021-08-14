#include <stdio.h>

int power (int base, int pow);


int main (){

	int base,pow;
	printf("Enter base number: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&base);

	printf("Enter power number (positive integer): ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&pow);

	printf("%d^%d = %d", base, pow, power(base, pow));

	return 0;


}

int power(int base, int pow){



	if(pow == 0)
		return 1;

	if(pow == 1)
		return base;

	return base * power(base, --pow);

}
