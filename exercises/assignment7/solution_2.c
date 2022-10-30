#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int indexOf(char * haystack, char * needle, int fromIndex);

int main(){

	char *hay = (char*)malloc(sizeof(500));
	char *needle = (char*)malloc(sizeof(500));

	printf("Haystack: \n");
	fgets(hay,500,stdin);
	printf("Needle: \n");
	fgets(needle,500,stdin);
	printf("From index: \n");
	int n;
	scanf("%d",&n);
	int ans = indexOf(hay, needle, n);
	if(ans != -1)
		printf("The needle is found at index %d.\n",ans);
	else
		printf("The needle cannot be found in the haystack\n");



	return 0;
}


int indexOf(char * haystack, char * needle, int fromIndex){
	size_t haystack_len = strlen(haystack);
	size_t needle_len = strlen(needle);
	int ans = -1;
	for(int i = fromIndex, j = 0; i < haystack_len; i++){
		while(i < haystack_len && j < needle_len && haystack[i] == needle[j]){
			i++;
			j++;
			if(j == needle_len-1)
				ans = i - j;
		}
		if(ans != -1)
			break;
		i -= j;
		j = 0;

	}
	return ans;
}
