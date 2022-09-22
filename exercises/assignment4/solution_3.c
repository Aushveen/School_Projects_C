#include <stdio.h>

int isPerfectNumber(int n);
int main(){

	int n;

	printf("Enter a number: \n");
	scanf("%d",&n);

	int valid = isPerfectNumber(n);

	if(valid == 1)
		printf("%d is a perfect number\n",n);
	else
		printf("%d is not a perfect number\n",n);

	return 0;
}

int isPerfectNumber(int n){
	int sum = 0;
	for(int i = 1; i < n; i++)
		if(n % i == 0)
			sum += i;
	if(sum == n)
		return 1;
	return 0;
}


