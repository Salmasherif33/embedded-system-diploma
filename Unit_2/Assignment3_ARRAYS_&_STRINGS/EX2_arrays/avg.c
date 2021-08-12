#include <stdio.h>

int main (){

	int n;
	printf("Enter the number  of data: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);
	fflush(stdout); fflush(stdin);

	float arr[100];
	float avg = 0, sum = 0;
	int i;
	for(i = 0; i < n; i++){
		printf("%d. Enter number: ",i+1);
		fflush(stdout); fflush(stdin);

		scanf("%f",&arr[i]);
	}

	for(i = 0; i < n; i++)
		sum += arr[i];

	avg = sum/n;
	printf("Average: %.2f",avg);
	return 0;
}
