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
	int insert;
	printf("Enter the element to be inserted: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&insert);
	n++;
	int loc;
	printf("Enter the location: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&loc);
	int temp [100];

	for(i = 0; i < n; i++)
		temp[i] = arr[i];
	for(i = n-1; i >=0  && n != 100; i--){
		if(i > loc-1){
			arr[i] = temp[i-1];
		}
		else if(i == loc -1){
			arr[i] = insert;
		}
		else{
			arr[i] = temp[i];
		}
	}
	for(i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
