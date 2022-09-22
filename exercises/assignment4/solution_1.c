#include <stdio.h>
#include <math.h>

double fact(int n);

int main(){
	int k, n;
	double p;

	printf("Enter a k value: \n");
	scanf("%d",&k);
	printf("Enter a n value: \n");
	scanf("%d",&n);
	printf("Enter a p value: \n");
	scanf("%lf",&p);


	double ans =  fact(n)/((fact(k)*(fact(n - k)))) * pow(p,k) * pow(1-p,n-k);

	printf("The answer is %lf \n",ans);

	return 0;
}


double fact(int n){
	double i;
	double f = 1.0;
	for(i = 1; i <= n; i++)
		f = f * i;
	return f;
}

