#include <stdio.h>

void print_prime(int start, int end);

int main(){

	int start,end;
	printf("Enter two numbers(intervals): ");
	fflush(stdout); fflush(stdin);

	scanf("%d %d",&start, &end);

	printf("Prime numbers between %d and %d are: ", start,end);
	print_prime(start, end);
	return 0;
}

void print_prime(int start, int end){
	int i,f;
	start++;
	while(start < end){
		f = 0;
		if( start <= 1)
			continue;
		for(i = 2; i < start/2; i++){
			if(start % i == 0){
				f =1;
				break;
			}

		}if(f==0)
			printf("%d ", start);
		start++;

	}
}
