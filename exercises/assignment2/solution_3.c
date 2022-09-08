#include <stdio.h>
#include <math.h>

int main(){
	double a,b;
	char op;
	printf("Enter two numbers: \n");
	scanf("%lf%lf",&a,&b);
	printf("Enter an operator:\n");
	scanf(" %c",&op);


	switch(op){
		case '+':
			printf("%.2lf",a + b);
			break;
		case '-':
			printf("%.2lf",a - b);
			break;
		case '*':
			printf("%.2lf",a * b);
			break;
		case '/':
			if(b == 0)
				printf("Error: dividing by zero");
			else
				printf("%.2lf",a / b);
			break;
		case '^':
			printf("%.2lf",pow(a,b));
			break;
		case 'r':
			printf("%.2lf",pow(b, 1.0/a));
			break;
		case '%':
			printf("%d",(int)(a) % (int)(b));
			break;

		}
	printf("\n");
	return 0;
}

