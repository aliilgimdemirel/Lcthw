// Input, Output, File 
#include <stdio.h>
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

char *replace_scanf(char *str, int size)
{
	int i = 0;
	char *rep_str = "";
	char tmp_str[MAX_DATA] = "";
	tmp_str[MAX_DATA - 1] = '\0';

	for (i = 0; i < size; i++){
		if (str[i] != '\0') {
			rep_str[i] = str[i];
		} else {
			rep_str[i] = '\0';
			break;
		}
	}
	

	return rep_str;
}


int main(int argc, char *argv[])
{
	Person you = {.age = 0};
	int i = 0;
	char *in = NULL;
	int rc = 0;	

	char str[10] = "abcdefghj";
	char *byte = str;

	//printf("What is your first name? ");
	//in = fgets(you.first_name, MAX_DATA - 1, stdin);
	//printf("Hello, %s!\n", you.first_name);
	//check(in != NULL, "Failed to read first name.");
	
	printf("What is your first name? ");
	rc = scanf("%s", str);
	printf("Hello, %s!\n", str);
	check(rc > 0 , "You have to enter a number.");
	//check(in != NULL, "Failed to read first name.");


	for (i = 0; i < MAX_DATA + 5; i++) {
		printf("str at %d: %d\n", i, byte[i]);
	}



	//printf("What is your last name? ");
	//in = fgets(you.last_name, MAX_DATA - 1, stdin);
	//printf("Hello, %s!\n", you.last_name);
	//check(in != NULL, "Failed to read last name.");
	
	
	//printf("How old are you? ");
	//rc = scanf( "%d", &you.age);
	//check(rc > 0 , "You have to enter a number.");
    //
	//printf("What color are your eyes:\n");
	//for (i = 0; i <= OTHER_EYES; i++) {
	//	printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
	//}
	//printf("> ");

	//int eyes = -1;
	//rc = scanf( "%d", &eyes);
	//check(rc > 0, "You have to enter a number");
    //
	//you.eyes = eyes - 1;
	//check(you.eyes <= OTHER_EYES
	//		&& you . eyes >= 0, "Do it right, that's not an option.");
    //
	//printf("How much do you make an hour? ");
	//rc = scanf( "%f", &you.income);
	//check(rc > 0, "Enter a floating point number.");
    //
	printf("----- RESULTS -----\n");

	//printf("First Name: %s\n", you.first_name);
	//printf("Last Name: %s\n", you.last_name);
	//printf("Age: %d\n", you.age);
	//printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
	printf("Income: %f\n", you.income);


	for (i = 0; i < 10; i++) {
		printf("%c", str[i]);
	}

	printf("lets get some characters\n");
	//for (i = 0; i < 10; i++) {
		scanf("%c", &str[0]);
		scanf("%c", &str[3]);
		scanf("%c", &str[6]);
	//}

	printf("\n");


	printf("\n");
	
	for (i = 0; i < MAX_DATA + 5; i++) {
		printf("str at %d: %d\n", i, byte[i]);
	}


	return 0;
error:
	return 1;

}
