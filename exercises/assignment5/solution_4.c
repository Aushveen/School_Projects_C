#include <stdio.h>

void checkSet(int arr[], int len);
int findIntersection(int arr1[], int input1_len, int arr2[], int input2_len);
int findUnion(int arr1[], int input1_len, int arr2[], int input2_len);
void calculateJaccard(int arr1[], int input1_len, int arr2[], int input2_len);

int main(){


	printf("Input first set length: \n");
	int s;
	scanf("%d",&s);
	int arr1[s];
	printf("Input numbers : \n");

	for(int i = 0; i < s;i++)
		scanf("%d",&arr1[i]);
	int n;
	printf("Input second set length: \n");
	scanf("%d",&n);
	int arr2[n];
	printf("Input numbers: \n");
	for(int i = 0; i < n; i++)
		scanf("%d",&arr2[i]);
	checkSet(arr1,s);
	checkSet(arr2,n);
	if(s == 0 || n == 0)
		return 0;
	calculateJaccard(arr1,s,arr2,n);
	printf("\n");

	return 0;
}

void checkSet(int arr[], int len){
	if(len == 0)
		printf("Please enter values in the set \n");
}


int findIntersection(int arr1[], int input1_len, int arr2[], int input2_len){
	int ans = 0;
	int max;
	if(input1_len <= input2_len){
		for(int i = 0; i < input1_len; i++)
			for(int j = 0; j < input2_len; j++)
				if(arr1[i] == arr2[j])
					ans++;
	}else
		for(int i = 0; i < input2_len; i++)
			for(int j = 0; j < input1_len; j++)
				if(arr2[i] == arr1[i])
					ans++;
	return ans;
}

int findUnion(int arr1[], int input1_len, int arr2[], int input2_len){
	return (input1_len + input2_len) - findIntersection(arr1,input1_len,arr2,input2_len);
}

void calculateJaccard(int arr1[], int input1_len, int arr2[], int input2_len){
	int u = findUnion(arr1,input1_len,arr2,input2_len);
	
	
	int inter = findIntersection(arr1, input1_len, arr2, input2_len);
	printf("The Jaccard similarity is %lf\n", (double)((double)inter / (double)u));
}

