#include <stdio.h>

int main(){
	printf("Enter the starting Fizz Buzz number: \n");
	int num;
	scanf("%d", &num);
	if(num <= 0){
		printf("Error: Cannot compute Fizz Buzz of %d\n",num);
	}else{
		for(int i = num; i >= 1; i--){
			for(int j = 0; j < 4 && i >= 1; j++){
				if(i % 5 == 0 && i % 3 == 0)
					printf("Fizz-Buzz ");
				else if(i % 5 == 0)
					printf("Buzz ");
				else if(i % 3 == 0)
					printf("Fizz ");
				else
					printf("%d ", i);
				i--;
			}
			i++;
			printf("\n");
		}
	}
	return 0;
}

