#include <stdio.h>

int main(void){
	int rad;
	printf("Enter the radius: \n");
	scanf("%d",&rad);
	printf("The area of a circle with radius %d is %f\n",rad,rad * 3.14159 * rad);
	printf("The diameter of a circle with radius %d is %d\n",rad,rad * 2);
	printf("The circumference of a circle with radius %d is %f\n",rad,rad * 2 * 3.14159);
	return 0;
}

