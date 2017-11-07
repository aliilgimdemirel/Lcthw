// Pointers, Dreaded Pointers
#include <stdio.h>

// important thing about this is that when using a pointer the pointed object's are not also passed. 
// This is though only the side effect of its usage logic;
// Practical Pointer Usage
// |__Pass large Blocks of memory to functions with a pointer, so you don't have to pass the whole thing to them.
// CREDIT PART BEGINS
void print1(char **names, int *ages, int count) 
{

	printf("====\nWe are inside the Function!\n====\n");
	
	int i = 0;

//	printf("Sizes of names:%lu, *names:%lu, **names:%lu\n", sizeof(names), sizeof(*names), sizeof(**names));
//	printf("Sizes of ages:%lu, *ages:%lu\n", sizeof(ages), sizeof(*ages));

	for (i = 0; i < count; i ++){
		printf("%s has %d years alive.\n", *(names+i), ages[i]);
	}
} // CREDIT PART ENDS

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
	char **names_ptr = names;

	print1(names_ptr, ages_ptr, count);

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
