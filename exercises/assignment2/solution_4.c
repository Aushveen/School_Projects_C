#include <stdio.h>

int main(){
	int a,b,c,d;
	printf("Enter a year:\n");
	scanf("%d",&a);
	printf("Enter a month:\n");
	scanf("%d",&b);
	printf("Enter a day:\n");
	scanf("%d",&c);
	if(b >= 1 && b <= 12){
		if(b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12){
			if(c >= 1 && c <= 31){
				printf("The date is valid\n");
				d = 1;
			}
		}else if(b == 2){
			if(a % 100 == 0 && a % 4 == 0){
				if(c >= 1 && c <= 29){
					d = 1;
					printf("The date is valid\n");
				}
			}else if(c >= 1 && c <= 28){
				d = 1;
				printf("The date is valid\n");
			}
		}else{
			if(c >= 1 && c <= 30){
				printf("The date is valid\n");
				d = 1;
			}
		}
	}
	if(d != 1)
		printf("The date is invalid\n");
	return 0;
}


		

