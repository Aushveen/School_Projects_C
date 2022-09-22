#include <stdio.h>
#include <math.h>

int findGCD(int p, int q);

int main(){
	int o, s;
	printf("Enter 1st positive integer: \n");
	scanf("%d",&o);
	printf("Enter 2nd positive integer: \n");
	scanf("%d",&s);

	int h = findGCD(o,s);
	printf("The GCF of %d and %d is %d\n", o,s,h);


	return 0;
}


int findGCD(int p, int q){
	if(q == 0)
		return p;
	else
		findGCD(q,p%q);
}
