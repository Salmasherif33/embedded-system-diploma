#include <stdio.h>

struct SComplex{
	float RPart;
	float IPart;
};

int main (){

	struct SComplex num1, num2 ,sum;
	printf("For 1st complex number\n");
	printf("Enter real and imaginary respectively:");

	fflush(stdout); fflush(stdin);
	scanf("%f %f", &num1.RPart, &num1.IPart);

	printf("For 2nd complex number\n");
	printf("Enter real and imaginary respectively:");

	fflush(stdout); fflush(stdin);
	scanf("%f %f", &num2.RPart, &num2.IPart);

	sum.RPart = num1.RPart + num2.RPart;
	sum.IPart = num2.IPart + num1.IPart;

	printf("Sum = %.1f + %.1fi",sum.RPart, sum.IPart);
	return 0;
}
