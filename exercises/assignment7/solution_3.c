#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replaceAll(char* s, char* target, char* replacement);

int main(){

	char *str = (char*)malloc(sizeof(500));
	printf("Enter a string: \n");
	fgets(str, 500, stdin);
	char *targ = (char*)malloc(sizeof(500));
	printf("Enter the target: \n");
	fgets(targ, 500, stdin);
	char *repl = (char*)malloc(sizeof(500));
	printf("Enter replacement: \n");
	fgets(repl, 500, stdin);
	char *res = NULL;
	res = replaceAll(str,targ,repl);
	printf("Output: %s\n",res);
	free(res);
	return 0;
}

char* replaceAll(char* s, char* target, char* replacement){
	char* res;
	char* ins;
	char* tmp;
	int len_rep;
	int len_targ;
	int len_front;
	int c;
	if(!s || !target)
		return NULL;
	len_targ = strlen(target);
	if(len_targ == 0)
		return NULL;
	if(!replacement)
		replacement = "";
	len_rep = strlen(replacement);
	ins = s;
	for(c = 0; tmp = strstr(ins, target); c++){
		ins = tmp + len_targ;
	}

	tmp = res = malloc(strlen(s) + (len_rep-len_targ) * c + 1);
	if(!res)
		return NULL;
	while(c--){
		ins = strstr(s,target);
		len_front = ins - s;
		tmp = strncpy(tmp,s,len_front) + len_front;
		tmp = strcpy(tmp,replacement) + len_rep;
		s += len_front + len_targ;
	}
	strcpy(tmp,s);
       return res;       
}
