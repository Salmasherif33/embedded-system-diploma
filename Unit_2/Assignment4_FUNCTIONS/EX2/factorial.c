#include <stdio.h>

int factorial(int n);

int main(){

	int n;
	printf("Enter a positive integer: ");
	fflush(stdout); fflush(stdin);

	scanf("%d", &n);

	printf("Factorial of %d = %d", n, factorial(n));

	return 0;
}

int factorial (int n){
	int fact = 1, i;
	for(i = 2; i <= n; i++)
		fact *= i;
	return fact;
}
