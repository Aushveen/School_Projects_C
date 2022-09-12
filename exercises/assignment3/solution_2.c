#include <stdio.h>
#include <math.h>

void primeFactors(int num);


int main(){
	int num;
	printf("Enter a positive integer that you wish to find prime factors of: \n");
	scanf("%d",&num);
	
	if(num == 1 || num == 0)
		printf("%d has no prime factorization.\n",num);
	else{
		primeFactors(num);
	}

	return 0;
}


void primeFactors(int num){
	printf("The prime factorization of %d is: ", num);
	while(num % 2 == 0){
		printf("%d ", 2);
		num /= 2;
	}

	for(int i = 3; i <= sqrt(num); i += 2){
		while(num % i == 0){
			printf("%d ",i);
			num /= i;
		}
	}

	if(num > 2)
		printf("%d ", num);
	printf("\n");
}

