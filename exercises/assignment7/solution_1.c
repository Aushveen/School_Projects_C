#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** myTokenizer(char *str, const char *delim);
int main(){
	printf("Input the string: \n");
	char *str =(char*) malloc(sizeof(500));
	fgets(str,500,stdin);
	printf("Input the delimiter: \n");
	char *delim = (char*)malloc(sizeof(500));
	fgets(delim,500,stdin);
	char **tokens = myTokenizer(str,delim);
	while(*tokens){
		printf("%s ", *tokens);
		tokens++;
	}
	return 0;
}


char ** myTokenizer(char *str, const char *delim){
	size_t str_len = strlen(str);
	size_t delim_len = strlen(delim);
	if(str_len == 0)
		return NULL;
	char** tokens = malloc(sizeof(char*) *2);
	int token_size = 2;

	char word[46] = "\0";
	int word_count = 0;
	for(register int i = 0, j = 0, z = 0; i < str_len; i++){
		while(i < str_len && z < delim_len && str[i] == delim[z]){
			z++;
			i++;
		}
		if(z == delim_len){
			i--;
			z = 0;
			continue;
		}else{
			i -= z;
			z = 0;
		}

		if(str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\0' || i == str_len){
			size_t word_len = strlen(word);
			if(word_len >= 46)
				word[j - 1] = '\0';
			else if(word_len > 0)
				word[j] = '\0';
			else{
				j = 0;
				continue;
			}

			if(word_count >= token_size -1){
				token_size *= 2;
				tokens = realloc(tokens, sizeof(char*) * token_size);
			}

			tokens[word_count] = malloc(sizeof(char*) * word_len + 1);
			strcpy(tokens[word_count++],word);

			j = 0;
			word[0] = '\0';
			continue;
		}
		if(j < 46 - 1)
			word[j++] = str[i];
	}
	if(word_count == 0)
		tokens[1] = NULL;
	tokens[word_count] = NULL;
	
	return tokens;
}
