#include <stdio.h>

int main(){
	int a,b,c;
	printf("Input first angle:\n");
	scanf("%d",&a);
       	printf("Input second angle:\n");
        scanf("%d",&b);
	printf("Input third angle:\n");
        scanf("%d",&c);

	int sum = a + b + c;

	if(sum != 180)
		printf("The triangle is invalid\n");
	else{
		printf("The triangle is valid\n");
		if(a < 90 && b < 90 && c < 90)
			printf("It's an acute triangle\n");
		else if(a == 90 || b == 90 || c == 90)
			printf("It's a right triangle\n");
		else if(a > 90 || b > 90 || c > 90)
			printf("It's an obtuse triangle\n");
		if(a == b || a == c || b == c){
			if(a == b && a == c){
				printf("It's an isoceles triangle\n");
				printf("It's an equilateral triangle\n");
			}else
				printf("It's an isoceles triangle\n");
		}else
			printf("It's not an isoceles triangle\n");
	}
	return 0;
}


