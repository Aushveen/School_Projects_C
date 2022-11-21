#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define MAX 100

int main()
{
	//declare two file pointer to read from file 
	FILE* fp1;
	FILE *fp2;
	char file1[20], file2[20];
	//declare a buffer to hold content read from file 
	char text[MAX][1024];
	char buf[200];
	int i, no_lines = 0;
	//ask user input for two input filenames
	printf("Enter name of file1: ");
	scanf("%s", file1);

	printf("Enter name of file2: ");
	scanf("%s", file2);

	//open two files 
	fp1 = fopen(file1, "r");
	fp2 = fopen(file2, "r");
	if (fp1 == NULL || fp2 == NULL)
	{
		printf("Not able to open file1 or file2 or both , check if file exists\n");
		return -1;
	}
	//read file1 and remove empty lines
	while (!feof(fp1))
	{
		fgets(buf, 1024, fp1);
		if(buf[strlen(buf) - 1] =='\n')
			buf[strlen(buf) - 1] = '\0';
		if (strcmp(buf, "") == 0)
			continue;
		strcpy(text[no_lines++], buf);
	}
	//read from file2 in same and remove empty lines 
	while (!feof(fp2))
	{
		
		fgets(buf, 1024, fp2);
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';
		
		if (strcmp(buf, "") == 0)
			continue;

		strcpy(text[no_lines++], buf);
	}
 
	fclose(fp1);
	fclose(fp2);
	//open file2 for writing
	fp2 = fopen(file2, "w"); 
	if (fp2 == NULL)
	{
		printf("file cannot be opened for writing\n");
		return -1;
	}
	//write content for text to file 
	for (i = 0; i < no_lines; i++)
	{
		//use fputs to write a line to file 
		if(i< no_lines-1)
			fprintf(fp2,"%s\n", text[i]);
		else
			fprintf(fp2, "%s", text[i]);
	}

	fclose(fp2);
	return 0;
}
