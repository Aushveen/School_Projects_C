#include <stdio.h>

int main(void){
	printf("Enter two numbers please: \n");
	int f, s;
	scanf("%d%d",&f,&s);
	printf("The sum of %d and %d is %d\n",f,s,f+s);
	printf("The difference of %d and %d is %d\n",f,s,f - s);
	printf("The product of %d and %d is %d\n",f,s,f * s);
	printf("The quotient of %d and %d is %d\n",f,s,f/s);
	return 0;
}
