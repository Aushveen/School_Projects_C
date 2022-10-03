#include <stdio.h>

void printSortedMergedArray(int arr1[], int len1, int arr2[], int len2, int arr3[]);

int main(){
	printf("Input size of array 1: \n");
	int one;
	scanf("%d",&one);
	printf("Input array 1: \n");
	int arr1[one];
	for(int i = 0; i < one; i++)
		scanf("%d",&arr1[i]);  
       
	printf("Input size of array 2: \n");
        int two;
	scanf("%d",&two);
        printf("Input array 2: \n");
        int arr2[two];
        for(int i = 0; i < two; i++)
                scanf("%d",&arr2[i]);
	int arr3[two + one];
	printSortedMergedArray(arr1,one,arr2,two,arr3);
	return 0;
}


void printSortedMergedArray(int arr1[], int len1, int arr2[], int len2, int arr3[]){
	int i = 0, j = 0;
	int k = 0;
	while(i < len1 && j < len2){
		if(arr1[i] <= arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}
	while(i < len1)
		arr3[k++] = arr1[i++];
	while(j < len2)
		arr3[k++] = arr2[j++];
	for(int l = 0; l < k; l++)
		printf("%d ", arr3[l]);
	printf("\n");
	
}
