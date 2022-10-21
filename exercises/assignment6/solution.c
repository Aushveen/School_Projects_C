#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_SIZE 46


double cosineSimilarity(char *instructor_answer, char *student_answer)
char ** getStudentAnswers(const char ** questions, int n, int len);
int ** ans2Vectors(char *instructor_answer, char 
*student_answer);


/* Splits the input string to individual words
   Input: pointer to char array
   Output: array of pointers (to char arrays) */
char** tokenize(char* str) {

    size_t str_len = strlen(str);

    if (str_len == 0)
        return NULL;

    char** tokens = malloc(sizeof(char*) * 2);
    int token_size = 2;

    char word[MAX_WORD_SIZE] = "\0";
    int word_count = 0;
    for (register int i = 0, j = 0; i < str_len + 1; i++) {
        if (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\0' || i == str_len) {
            size_t word_len = strlen(word);

            // Add a null character at the end
            if (word_len >= MAX_WORD_SIZE)
                word[j - 1] = '\0';
            else if (word_len > 0)
                word[j] = '\0';
            else { // Empty word
                j = 0;
                continue;
            }             

            // Grow size
            if (word_count >= token_size - 1) {
                token_size *= 2;
                tokens = realloc(tokens, sizeof(char*) * token_size);
            }

            tokens[word_count] = malloc(sizeof(char) * word_len + 1);
            strcpy(tokens[word_count++], word);

            j = 0;
            word[0] = '\0';
            continue;
        }

        if (j < MAX_WORD_SIZE - 1)
            word[j++] = str[i];
    }

    if (word_count == 0)
        tokens[1] = NULL;

    tokens[word_count] = NULL;

    return tokens;
}


/* Removes duplicates from an array of pointers to char arrays
 * Input: array of pointers to char arrays (containing duplicates)
 * Output: array of pointers to char array (duplicates removed) */
char** getUniqueWords(char** strs) {

    char** uniques = malloc(sizeof(char*) * 2);
    int unique_size = 2;

    int unique_count = 0;

    for (register int i = 0; ; i++) {
        if (strs[i] == NULL)
            break;

        // Detect duplication
        bool is_duplicated = false;
        for (register int j = 0; j < unique_count; j++) {
            if (strcmp(strs[i], uniques[j]) == 0) {
                is_duplicated = true;
                break;
            }
        }

        if (!is_duplicated) {
            
            // Grow size
            if (unique_count >= unique_size - 1) {
                unique_size *= 2;
                uniques = realloc(uniques, sizeof(char*) * unique_size);
            }

            uniques[unique_count] = malloc(sizeof(char) * strlen(strs[i]) + 1);
            strcpy(uniques[unique_count++], strs[i]);
        }
    }

    if (unique_count == 0) {
        free(uniques);
        return NULL;
    }

    uniques[unique_count] = NULL;

    return uniques;
}

/* Free a pointer array of words */
void freeWords(char** ptr) {
    for (register int i = 0; ; i++) {
        if (ptr[i] == NULL)
            break;
        free(ptr[i]);
    }
    free(ptr);
}



char ** getStudentAnswers(const char **questions, int n, int len){
       	char** studentAns = malloc(sizeof(char*) *100200);
	for(int i = 0; i < n; i++){
		char curr[500];
		printf("The %d question is: %s\n",i + 1, questions[i]);
		printf("Please enter your answer student: \n");
		fgets(curr,len,stdin);
		studentAns[i] = malloc(sizeof(char) * strlen(curr) + 1);
		printf("\n"]);

	}
	free(studentAns);
	return studentAns;
}

double cosineSimilarity(char *instructor_answer, char *student_answer){
	int ans** = ans2Vectors(instructor_answer,student_answer);
	double mul = 0.0, d_a = 0.0, d_b = 0.0 ;
    	for(unsigned int i = 0; i < size; ++i)
       	{
        mul += ans[0][i] * ans[1][i] ;
        d_a += ans[0][i]*ans[0][i] ;
        d_b += ans[1][i]*ans[1][i] ;
    }
    return mul / (sqrt(d_a) * sqrt(d_b)) ;
}

int ** ans2Vectors(char *instructor_answer, char *student_answer){

	int ans**;
	while(*instructor_answer){
		*instructor_answer = tolower(*instructor_answer);
		instructor_answer++;
	}
	while(*student_answer){
		*student_answer = tolower(*student_answer);
		student_answer++;
	}

	char **tokenIns = tokenize(instructor_answer);
	char ** tokenStu = tokenize(student_answer);
	char **unqiueIns = getUniqueWords(tokenIns);
	char **uniqueStu = getUniqueWords(tokenStu);
	
}

int main(void) {

	const char *questions[5];
	char a[] = "What are local variables?";
	char b[] = "What is an identifier?";
	char c[] = "What is recursion";
	char d[] = "What is a pointer";
	char e[] = "What is the purpose of applying static to a local array?";
	questions[0] = a;
	questions[1] = b;
	questions[2] = c;
	questions[3] = d;
	questions[4] = e;
	char *instructAns[5];
	char a1[] = "Variables defined in function definition are local variables. They can be accessed only in that function scope";
	char b1[] = "dentifiers are user defined names given to variables, functions and arrays";
	char c1[] = "A function calling itself again and again to compute a value is referred to as recursive function or recursion. Recursion is useful for branching processes and is effective where terms are generated successively to compute a value";
	char d1[] = "A pointer is a variable that stores the memory address of another variable as its value";
	char e1[] = "By making a local array definition static the array is not created and initialized every time the function is called and it is not destroyed every time the function is exited. Also, the execution time is reduced";

	char ** studentAns =  getStudentAnswers(questions, 5, 500);



    /* Example on how to use the helper functions */

    // tokenize function takes a string and can split it into individual words by empty space, comma, period, and null character
    // The function won't return how many words are splitted, but the last pointer is always a null pointer, so you can loop
    // the pointers until you met a null pointer to traverse the words
    // If the string is empty, a null pointer will be returned
    // Note: tokenize function will allocate memory on the heap for each word and the pointers for those words
    /*
    char** tokens = tokenize("a pointer is a variable that stores the memory address of another variable as its value.");

    // getUniqueWords function will traverse through the pointer array created by tokenize function and remove the duplicated words
    // If no word is found, a null pointer will be returned
    // Note: This function will also allocate memory on heap
    char** uniques = getUniqueWords(tokens);

    // Loop through the pointers until met an null pointer
    for (register int i = 0; ; i++) {
        if (uniques[i] == NULL)
            break;
        printf("%s\n", uniques[i]);
    }

    // Since both tokenize and getUniqueWords functions will allocate memory on the heap, we need to free the pointers
    // freeWords function will free the memory for each word and the memory for storing the pointers
    freeWords(tokens);
    freeWords(uniques);



*/

    return 0;
}
