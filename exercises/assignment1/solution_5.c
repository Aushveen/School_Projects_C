#include <stdio.h>

int main(void){
	int start, diff, n;
	printf("Enter the starting number of the AP series: \n");
	scanf("%d",&start);
	printf("Enter the common difference: \n");
	scanf("%d",&diff);
	printf("Enter the nth term to be found: \n");
	scanf("%d",&n);
	printf("The %dnth term of the series is: %d\n",n,start + (n - 1) * diff);
	return 0;
}
