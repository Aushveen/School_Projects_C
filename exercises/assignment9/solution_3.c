#include <stdio.h>

int main()
{
// variable declation
int n,even=0,odd=0,b=0,count,c=0;
printf("Please Enter The Size Of Array: ");

// read the size of array
scanf("%d",&n);
printf("Please Enter The %d Number For The Array: ",n);
int A[n],i;

// read the n elements for an array
for(i=0;i<n;i++){
	scanf("%d",&A[i]);
	if(A[i]%2==0){
		even++;
	}
	else{
		odd++;
	}
}


int a=(odd*(odd-1))/2;

// count total OR pairs
for(int i=0;i<n;i++){
	if(A[i]%2==1){
		b=b+(n-1-i);
	}
	else{
		count=0;
		for(int j=i+1;j<n;j++){
			if(A[j]%2==1){
				count++;
			}
		}
		b=b+count;
	}
}

// count total XOR pairs
for(int i=0;i<n;i++){
	if(A[i]%2==1){
		count=0;
		for(int j=i+1;j<n;j++){
			if(A[j]%2==0){
				count++;
			}
		}
		c=c+count;
	}else{
		count=0;
		for(int j=i+1;j<n;j++){
			if(A[j]%2==1){
				count++;
			}
		}
		c=c+count;
	}
}

// print total AND pairs with pairs value
printf("Total AND pairs: %d i.e.",a);
int pos=a;
for(int i=0;i<n;i++){
	if(A[i]%2==1){
		for(int j=i+1;j<n;j++){
			if(A[j]%2==1){
				pos--;
				if(pos==0 && a!=1){
					printf(" and (%d, %d)",A[i],A[j]);
				}else{
					printf(", (%d, %d)",A[i],A[j]);
				}
			}
		}
	}
}
printf("\n");

// print total OR pairs with pairs value
printf("Total OR pairs: %d i.e.",b);
pos=b;
for(int i=0;i<n;i++){
	if(A[i]%2==1){
		for(int j=i+1;j<n;j++){
			pos--;
			if(pos==0 && b!=1){
				printf(" and (%d, %d)",A[i],A[j]);
			}else{
				printf(", (%d, %d)",A[i],A[j]);
			}
		}
	}else{
		for(int j=i+1;j<n;j++){
			if(A[j]%2==1){
				pos--;
				if(pos==0 && b!=1){
					printf(" and (%d, %d)",A[i],A[j]);
				}else{
					printf(", (%d, %d)",A[i],A[j]);
				}
			}
		}
	}
}
printf("\n");

// print total XOR pairs with pairs value
printf("Total XOR pairs: %d i.e",c);
pos=c;
for(int i=0;i<n;i++){
	if(A[i]%2==1){
		for(int j=i+1;j<n;j++){
			if(A[j]%2==0){
				pos--;
				if(pos==0 && c!=1){
					printf(" and (%d, %d)",A[i],A[j]);
				}else{
					printf(", (%d, %d)",A[i],A[j]);
				}
			}
		}
	}else{
		for(int j=i+1;j<n;j++){
			if(A[j]%2==1){
				pos--;
				if(pos==0 && b!=1){
					printf(" and (%d, %d)",A[i],A[j]);
				}else{
					printf(", (%d, %d)",A[i],A[j]);
				}
			}
		}
	}
}
printf("\n");

return 0;
}
