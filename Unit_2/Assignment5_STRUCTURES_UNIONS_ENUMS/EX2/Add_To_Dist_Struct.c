#include <stdio.h>

struct SDistance{
	int feet;
	float inch;
};

int main(){

	struct SDistance dist1,dist2,sum;
	printf("Enter information for 1st distance\n");
	printf("Enter feet:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&dist1.feet);

	printf("Enter inch");
	fflush(stdout); fflush(stdin);
	scanf("%f",&dist1.inch);

	printf("Enter information for 2nd distance\n");
	printf("Enter feet:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&dist2.feet);

	printf("Enter inch");
	fflush(stdout); fflush(stdin);
	scanf("%f",&dist2.inch);

	sum.feet = dist1.feet + dist2.feet;
	sum.inch = dist1.inch + dist2.inch;

	if(sum.inch >= 12){
		sum.feet++;
		sum.inch -= 12;
	}

	printf("sum of distances = %d' -%.1f", sum.feet, sum.inch);
	return 0;
}
