#include <stdio.h>

void generateKGrams(int n, int k, char kGrams[][k + 1], char input[], int l);
void printKGrams(int l, int k, char kGrams[][k+1]);
int length(char str[]);

int main(){

	int k;
	char str[] = {"because  the  arrays  starting  address  is  passed,  the  called  function  knows precisely where the array is stored"};
	printf("Input value of k: \n");
	scanf("%d",&k);
	int l = length(str);
	int n = l - k + 1;
	char kGrams[][k + 1];
	generateKGrams(n, k, kGrams, str, l);
	printKGrams(l,k,kGrams);

	return 0;
}

void generateKGrams(int n, int k, char kGrams[][k + 1],char input[], int l){
	int curr = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < k + 1; j++)
			while(curr < l)
				kGrams[i][j] = input[curr++];
}

void printKGrams(int l, int k, char kGrams[][k + 1]){
	for(int i = 0; i < (l - k + 1); i++)
		printf("%s\n",kGrams[i]);

}

int length(char str[]){
	int i = 0;
	while(str[i] != '\0')
		i++;
	return i;
}
