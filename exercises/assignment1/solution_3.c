#include <stdio.h>

int main(void){
	int a, b;
	printf("Input a: \n");
	scanf("%d",&a);
	printf("Input b: \n");
	scanf("%d",&b);
	printf("The sume of %d and %d is %d\n",a,b,a+b);
	printf("The differnce of %d and %d is %d\n",a,b,a-b);
	printf("The product of %d and %d is %d\n",a,b,a*b);
	printf("The remainder of %d and %d is %d\n",a,b,a%b);
	return 0;
}
