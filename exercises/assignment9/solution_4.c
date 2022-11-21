#include <stdio.h>


int main()
{
// variable declation
int n,sum=0;
printf("Enter The Size Of Array: ");

// read the size of array
scanf("%d",&n);
printf("Enter The %d Elements Of The Array: ",n);
int A[n],i;

// read the n elements for an array
for(i=0;i<n;i++)
{
scanf("%d",&A[i]);
sum=sum+A[i];
}
printf("Duplicate No. is: %d.\n",sum-((n*(n-1))/2));
return 0;
}
