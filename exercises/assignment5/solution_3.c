#include <stdio.h>
void printUniqueElements(int elements[], int lenArray);

int main(){

	int size;
	printf("What is size of array: \n");
	scanf("%d",&size);


	int elements[size];

	printf("Enter the %d elements of the array: \n",size);

	for(int i = 0; i < size; i++)
		scanf("%d",&elements[i]);

	printUniqueElements(elements, size);


	return 0;
}


void printUniqueElements(int elements[], int lenArray){
	int temp[lenArray];
	int j = 0;
	printf("Input : ");
	for(int i = 0; i < lenArray; i++)
		printf("%d ", elements[i]);
	printf("\n");

	for(int i = 0; i < lenArray-1; i++)
		if(elements[i] != elements[i + 1])
			temp[j++] = elements[i];
	temp[j++] = elements[lenArray - 1];
	for(int i = 0; i < j; i++)
		elements[i] = temp[i];
	printf("Output : ");
	for(int i = 0; i < j; i++)
		printf("%d ", elements[i]);
	printf("\n");
}
