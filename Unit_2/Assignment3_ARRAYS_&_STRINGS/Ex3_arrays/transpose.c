#include <stdio.h>

int main (){

	float matrix[100][100];
	int r,c;
	printf("Enter rows and columns of matrix: ");
	fflush(stdout); fflush(stdin);

	scanf("%d",&r);
	scanf("%d",&c);

	printf("Enter Elements of matrix: \n");
	int i,j;
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			printf("Enter element a%d%d: ",i+1,j+1);
			fflush(stdout); fflush(stdin);
			scanf("%f",&matrix[i][j]);

		}
	}

	printf("Entered matrix: \n");
	for(i = 0; i < r; i++){
		for(j=0; j < c; j++){
			printf("%.2f\t",matrix[i][j]);
		}
		printf("\n");
	}
	printf("Transpose of matrix: \n");
	for(i = 0; i < c; i++){
		for(j = 0; j < r; j++){
			printf("%.2f\t",matrix[j][i]);
		}
		printf("\n");
	}
	return 0;
}
