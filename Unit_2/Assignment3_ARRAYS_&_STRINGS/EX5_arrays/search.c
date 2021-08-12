#include <stdio.h>

int main(){

	int arr[100],n;
	printf("Enter no of elements:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	int i;
	for(i=0; i < n;  i++){
		scanf("%d",&arr[i]);
	}
	int s;
	printf("Enter the element to be searched: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&s);
	char flag = 'f';
	for (i = 0; i < n; i++){
		if(arr[i] == s){
			printf("Number found at location  = %d", i+1);
			flag = 't';
			break;
		}
	}
	if(flag == 'f')
		printf("Not found");


	return 0;
}
