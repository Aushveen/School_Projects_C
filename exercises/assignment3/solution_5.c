#include <stdio.h>

int main(){
	printf("Enter the number of rows: ");
	int n, c;
	scanf("%d",&n);
	if(n < 0 || n % 2 == 0){
		printf("n has to be a postive odd number\n");
		return 0;
	}
	n /= 2;
	n++;
	for(int i = 1; i <= n; i++){
		for(c = 1; c <= n - i; c++)
		       printf(" ");
		for(c = 1; c <= i * 2 - 1; c++)
			printf("*");
		printf("\n");
	}
	for(int i = 1; i <= n - 1; i++){
		for(c = 1; c<= i; c++)
			printf(" ");
		for(c = 1; c <= 2 * (n - i)-1; c++)
			printf("*");
		printf("\n");
	}
	return 0;
}
	
		


