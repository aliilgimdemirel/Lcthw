// Pointers, Dreaded Pointers
#include <stdio.h>

void printPtr(char **names, int *ages, int count) 
{

	printf("====\nWe are inside the Function!\n====\n");
	
	int i = 0;

	for (i = 0; i < count; i++){
		printf("Adress of names:\t%p and it is: %s\nAnd ages:\t\t%p and it is: %d\n",
				 names+i, *(names+i) ,ages+i, ages[i]);
	}
} 

int main(int argc, char *argv[])
{
	// create two arrays we care about
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

//	printf("Sizes of names:%lu, *names:%lu, **names:%lu\n", sizeof(names), sizeof(*names), sizeof(**names));
//	printf("Sizes of ages:%lu, *ages:%lu\n", sizeof(ages), sizeof(*ages));
	
	//safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	//first way using indexing
	for (i=0; i < count; i++) {
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");

	int *ages_ptr = ages;
	char *byte_ptr = ages;
	char **names_ptr = names;

	// Following function call is one with a lot of text.
	printPtr(names_ptr, ages_ptr, count);

	// Comparing memory interpretation differences  
	printf("Size of ages via pointer: %lu\nSize of ages via array: %lu\n", sizeof(*ages_ptr), sizeof(ages));






	/*	
	// This part was used for representing different uses of pointers.
	// 1- How to reach in a integer byte by byte ?

	printf("---\n");
	for (i=0; i < count; i++) {
		printf("%s has %d years alive.\n", *(names_ptr+i), ages_ptr[i]);
		printf("%d %d %d %d\n", *(byte_ptr+i+0), *(byte_ptr+i+1), *(byte_ptr+i+2), *(byte_ptr+i+3) );
		//printf("%c %c %c %c\n", *(byte_ptr+i+0), *(byte_ptr+i+1), *(byte_ptr+i+2), *(byte_ptr+i+3) );
		//printf("%d\n", ages_ptr[i]);
		printf("%d'th pass ended\n\n", i);
	}
	*/

	
	/*
	char *name1[] = {"AHAN"};
	char *name2[5] = {"AHK"};

    printf("clash of name1-name2 W ptr= %li\n", *name1-*name2);
    printf("clash of name1-name2 W/o ptr= %li\n", name1-name2);
	printf("name1:\t%c\nname2:\t%s\n", name1, name2);
    printf("Adress of name1:\t%p with Size:\t %lu\nAdress of name2:\t%p with Size:\t %lu\n",
			 *name1, sizeof(*name1), *name2, sizeof(*name2));
	printf("address of name1 using &: %#x using p: %p, using *: %s\n", &name1, name1, *name1);	
	printf("address of name2 using &: %#x using p: %p, using *: %s\n", &name2, name2, *name2);	


	char *name3[5] = {"BABA"};
	char *name4[5] = {"ANA"};

    printf("clash of name3-name4 W ptr= %li\n", *name3-*name4);
    printf("clash of name3-name4 W/o ptr= %li\n", name3-name4);
    printf("Adress of name3:\t%p with Size:\t %lu\nAdress of name4:\t%p with Size:\t %lu\n",
			 *name3, sizeof(*name3), *name4, sizeof(*name4));
	printf("address of name3 using &: %#x using p: %p, using *: %s\n", &name3, name3, *name3);	
	printf("address of name4 using &: %#x using p: %p, using *: %s\n", &name4, name4, *name4);	

	*/

	// Original ex15.c remainings can be found below.
	/*
	//set up the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	// second way using pointers
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n",
			*(cur_name + i), *(cur_age + i) );
	}
	printf("---\n");

	//third way, pointers are just arrays
	for (i = 0;i < count; i++){
		printf("%s is %d years old.\n",
			cur_name[i], cur_age[i]);
	}

	printf("---\n");
	
	//fourth way with pointers in a stupid complex way
	for (cur_name = names, cur_age = ages;
			(cur_age - ages) < count; cur_name++, cur_age++) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);

	}
	*/

	return 0;
}
