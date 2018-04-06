// LogFind
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "dbg.h"
#include <math.h>

#define MAX_LINE_LEN 1000
#define MAX_STR_LEN 1000

char** split_string(char* str);
char* readline(char *str, FILE *file);
int isStrInLine(char* Line, int len_Line, char* str);
int checkAllStrings(char* Line, int len_Line, char** str, int str_count);


int isStrInLine(char* Line, int len_Line, char* str)
{
	int ret_val = 0;
	// If the string found in the line, the function will return 1 
	if (strstr(Line, str)) {
		ret_val = 1;
	}
	return ret_val;
}

int checkAllStrings(char* Line, int len_Line, char** str, int str_count)
{
	int ret_val = 0;
	// If the string found in the line, the function will return 1 
	for (int i = 0; i < str_count; i++) {
		if ( isStrInLine( Line, len_Line, str[i]) ) {
			ret_val = 1;
			break;
		}
	}
	return ret_val;
}

int main (int argc, char *argv[])
{
	// take inputs 
	// identify the string to be found
	char **srch_str;
	int str_count;
	char opt = argv[1][1]; // bad design should have been argv[1][0]
			char *temp_str = "\0";
			char *temp_blank = " ";
	switch (opt) {
		case 'o':
			str_count = argc-2;
			srch_str = malloc(sizeof(char*) * str_count);
			for (int i = 0; i < str_count; i++) {
				srch_str[i] = argv[i+2];
			}
			break;

		default: // No options provided. DEF MODE; &&
			str_count = argc-1;
			srch_str = malloc(sizeof(char*) * str_count);
			for (int i = 0; i < str_count; i++) {
				srch_str[i] = malloc(sizeof(char) * 40) ;
				memset(srch_str[i], 0, 40);
			}
			printf("srch_str is: \"%s\"\n", srch_str[0]);
			strcat(srch_str[0], argv[1]);
			printf("srch_str is: \"%s\"\n", srch_str[0]);
			for (int i = 1; i < str_count; i++) {
				strcat(srch_str[0], temp_blank);
				printf("srch_str is: \"%s\"\n", srch_str[0]);
				strcat(srch_str[0], argv[i+1]);
				printf("srch_str is: \"%s\"\n", srch_str[0]);
			}
			str_count = 1;
	}


	int fileCount = 2;
	char *dirOfLogfiles = "/home/demirel/.logfind/";
	char *fileList[2] = {"file1.txt", "file2.txt"};

	for (int i = 0; i < fileCount; i++ ) {
		char *pathFile = calloc(sizeof(char), 50);
		strcat( pathFile, dirOfLogfiles );

		FILE *logfile = fopen( strcat(pathFile,fileList[i]), "r" );
//		printf("DEBUG_LOG_FILE\n");

		char *str_readline = malloc(sizeof(char) * MAX_LINE_LEN);
//		printf("DEBUG_MALLOC\n");

		int counter = 0;
		while ( !feof(logfile) && counter < 30 ) {
//		printf("DEBUG\n");
			str_readline = readline(str_readline, logfile);
			if ( checkAllStrings( str_readline, strlen(str_readline), srch_str, str_count ) ) {
				printf("In file %s, @Line:%d, found : %s\n", pathFile, counter, str_readline);
			}
//			printf("%s\n", str_readline);
			memset(str_readline, 0, MAX_LINE_LEN);
//			printf("DEBUG_MEMSET\n");
			counter++; // assumes 2^32 Line count;
		}
	
//		printf("File: %s had %d Lines.\n", pathFile, counter);
		fclose(logfile);
	}
	return 0;	
}


char *readline(char *str, FILE *file)
{
    char buffer[MAX_STR_LEN+2];
    memset(buffer, 0, MAX_STR_LEN+2);
    fgets(buffer, MAX_STR_LEN+2, file);
    buffer[strcspn(buffer,"\n")] = '\0';
    strncpy(str, buffer, MAX_STR_LEN);
    return str;
}

char** split_string(char* str)
{
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }   

    return splits;
}
