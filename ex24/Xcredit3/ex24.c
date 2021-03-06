// Input, Output, File 
#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_DATA 10

typedef enum EyeColor {
	BLUE_EYES, GREEN_EYES, BROWN_EYES,
	BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
	"Blue", "Green", "Brown", "Black", "Other",
};

typedef struct Person {
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	EyeColor eyes;
	float income;
} Person;

char *trimmer(char *str, int size)
{
	char *trimmed = str;
	int i = 0;

	printf("Length of str b4 trim: %lu\n", strlen(str));
	
	for (i = 0; i < size; i++) {
		if (trimmed[i] == '\n' || trimmed[i] == ' ') {
			trimmed[i] = '\0';
		}
	}

	printf("Length of str b4 trim: %lu\n", strlen(trimmed));
	return trimmed;
}



int main(int argc, char *argv[])
{
	Person you = {.age = 0};
	int i = 0;
	char *in = NULL;
	//int rc = 0;	

	char *bayt = NULL;
	char str[MAX_DATA] = "abcdefghj";

	// first name
	//printf("What is your first name? ");
	//in = fgets(you.first_name, MAX_DATA - 1, stdin);
	//check(in != NULL, "Failed to read first name.");
	
	// last name
	//printf("What is your last name? ");
	//in = fgets(you.last_name, MAX_DATA - 1, stdin);
	//check(in != NULL, "Failed to read last name.");
	
	// age
	//printf("How old are you? ");
	//in = fgets(str, MAX_DATA -1, stdin);
	//check(in != NULL, "Failed to read age name.");
	you.age = atoi(str);

	// eyes
	//printf("What color are your eyes:\n");
	//for (i = 0; i <= OTHER_EYES; i++) {
	//	printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
	//}
	//printf("> ");
    //
	//int eyes = -1;
	//in = fgets(str, MAX_DATA -1, stdin);
	//check(in != NULL, "Failed to read eyes name.");
	//eyes = atoi(str);
    //
	//you.eyes = eyes - 1;
	//check(you.eyes <= OTHER_EYES
	//		&& you . eyes >= 0, "Do it right, that's not an option.");
    //
	printf("How much do you make an hour? ");
	in = fgets(str, MAX_DATA , stdin);
	check(in != NULL, "Failed to read income name.");
	you.income = atof(trimmer(str, MAX_DATA));
	

	
	// --- Some debugging had happened. ---
	bayt = str;

	for (i = 0; i < MAX_DATA ; i++) {
		printf("%d'th byte of our input: %d\n", i, *bayt++);
	}
	
	printf("----- RESULTS -----\n");

	printf("First Name: %s\n", you.first_name);
	printf("Last Name: %s\n", you.last_name);
	printf("Age: %d\n", you.age);
	printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
	printf("Income: %f\n", you.income);

	return 0;
error:
	return 1;

}
