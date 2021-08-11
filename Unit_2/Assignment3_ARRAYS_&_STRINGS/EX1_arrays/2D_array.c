#include <stdio.h>

int main (){

	printf("Enter the elements of 1st matrix: \n");
	fflush(stdout); fflush(stdin);

	float arr1[2][2],arr2[2][2];

	int i,j;
	for(i=0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf("Enter a%d%d: \n",i+1,j+1);
			fflush(stdout); fflush(stdin);

			scanf("%f",&arr1[i][j]);
		}
	}

	printf("Enter the elements of 2nd matrix: \n");
	for(i=0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf("Enter b%d%d: \n",i+1,j+1);
			fflush(stdout); fflush(stdin);

			scanf("%f",&arr2[i][j]);
		}
	}

	printf("Sum Of Matrix: \n");
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf("%0.2f\t\t",arr1[i][j] + arr2[i][j]);
		}
		printf("\n");
	}


	return 0;

}
