#include <stdio.h>

int main(void){
	int month, year, age;
	printf("Enter current month: \n");
	scanf("%d",&month);
	printf("Enter current year: \n");
	scanf("%d",&year);
	printf("Enter your age: \n");
	scanf("%d",&age);
	printf("It is month %d of the year %d and you are %d years old!\n",month,year,age);
	return 0;
}
