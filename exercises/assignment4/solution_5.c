#include <stdio.h>
#include <math.h>


float series(int x, int n, int l, int r);
int fact(int n);

int main(){

	int x, n, l, r;

	printf("Enter a value of X: \n");
	scanf("%d", &x);
	printf("Enter a value of n: \n");
	scanf("%d",&n);
	printf("Enter a value of l: \n");
	scanf("%d",&l);
	printf("Enter a value of r: \n");
	scanf("%d",&r);

	float sum = series(x,n,l,r);

	printf("The sum of the series = %f\n",sum);

	return 0;

}

float series(int x, int n, int l, int r){
	int prime[r];

	for(int i = 0; i < r; i++)
		prime[i] = 0;

	for(int i = 2; i <= (int)sqrt(r); i++)
		for(int j = i * i; j < r; j+=i)
			if(prime[j] != 1)
				prime[j] = 1;


	float res;

	for(float i = 1; i <= n; i++){
		float curr = (float)pow((float)x,i)/(float)fact(i);
		
		while(prime[l] == 1 && l < r)
			l++;
		printf("%d\n",l);
		if(l < r)
			curr += l++;

		res += curr;
	}
	return res;
}
			


int fact(int n){
	if(n == 0)
		return 1;
	else
		return (n * fact(n-1));
}






