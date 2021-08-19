#include <stdio.h>

int main(){

	int n;
	int arr[15];
	int reverse_Arr[15];
	printf("Input the number of elements to stre in the array(max15) : ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);
	printf("Input %d number of elements in the array:\n",n);
	int i;
	int *ptr = arr;
	for(i=0; i< n; i++){
		printf("element- %d :",i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d", ptr++);
	}
	ptr = arr;
	printf("The elements of array in reverse order are : \n");
	int *rev_ptr = reverse_Arr;
	for(i=n-1; i>= 0; i--){
		*(rev_ptr+i) = *ptr;
		ptr++;
	}

	for(i = 0; i < n; i++)
		printf("element - %d : %d\n",i+1,*(rev_ptr+i));
	return 0;
}
