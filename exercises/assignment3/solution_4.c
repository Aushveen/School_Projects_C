#include <stdio.h>
#include <string.h>

void revBin(int num);

int main(){
	printf("Enter a number to find the reverse binary representation: \n");
	int num;
	scanf("%d",&num);
	if(num < 0)
		printf("Error: Number must be a positive integer.");
	else
		revBin(num);
	printf("\n");
	return 0;
}

void revBin(int num){
	printf("%d", num % 2);
	if(num > 1)
		revBin(num / 2);
	else
		return;
	
}


