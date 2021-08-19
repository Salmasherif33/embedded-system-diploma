#include <stdio.h>

struct SEmployee{
	char name[50];
	int id;
};
int main(){

	struct SEmployee *arr[1];
	struct SEmployee emp1 = {"Alex", 1002};

	arr[0] = &emp1;
	struct SEmployee **ptr = arr;
	printf("Employee name : %s\n",(*(*ptr)).name );
	printf("Employee ID : %d\n", (*(*ptr)).id);


//	printf("Employee name: %s\n",ptr->name);
	//printf("Employee ID : %d\n",ptr->id);
	//ptr++;

	return 0;
}
