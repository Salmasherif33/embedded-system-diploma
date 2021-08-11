#include <stdio.h>
#include <ctype.h>

int main (){

	char op;
	float num1,num2,result = 0.0;
	printf("Enter operator either + or - or * or divide: ");
	fflush(stdout); fflush(stdin);

	scanf("%c",&op);

	printf("Enter two operands: ");
	fflush(stdout); fflush(stdin);

	scanf("%f",&num1);
	scanf("%f",&num2);

	if(op == '/' && num2 == 0.0){
		printf("ERROR!!");
		return 0;
	}

	switch(op){
	case '+':
		result = num1 + num2;
		break;

	case '-':
		result = num1 - num2;
		break;

	case '*':
		result = num1 * num2;
		break;

	case '/':
		result = num1 / num2;
		break;

	default:
		printf("ERROR!");
		return 0;

	}


	printf("%0.2f %c %0.2f = %0.2f",num1,op, num2, result);

	return 0;
}
