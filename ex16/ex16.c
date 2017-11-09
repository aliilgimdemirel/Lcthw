//Structs and Pointers to Them
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height,
	int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	
	printf("Where is %s: %p.\n", name, who);
	
	return who;
};

void Person_destroy(struct Person *who)
{
	assert(who != NULL);
	
	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

// Extra Credit 3, takes in a person as a struct not as a pointer to a struct
// having said that should check what if I send a ptr to a struct 
void getStructAsAWhole(struct Person sahis)
{
	printf("sizeof Person:%s is :%lu\n", sahis.name, sizeof(sahis));

}

int main(int argc, char *argv[])
{
	// make two people structures
	struct Person *joe = Person_create("Joe Alex1234567890123456789012345678901234567890", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	//print them out and where they are in memory
	printf("Where is joe: %p.\n", joe);
	printf("What is the sizeof joe:%lu\n", sizeof(*joe));
	Person_print(joe);

	printf("Where is frank: %p.\n", frank);
	printf("What is the sizeof frank:%lu\n", sizeof(*frank));
	Person_print(frank);

	// make everyone age 20 years and print them again
	joe->age += 20;
	Person_print(joe);

	frank->age += 20;
	Person_print(frank);

	Person_destroy(joe);
	
	// Create a Person struct named hasan.
	struct Person hasan = {.name = "Hasan", .age = 30 };
    printf("Who is hasan ? hasan is %s, and hasan is %d years old.\n", hasan.name, hasan.age);
    printf("Lets crash hasan !!!! hasan weights %d.\n", hasan.weight);
	
	printf("---\n");

	// check if sending a struct directly works or not.
	getStructAsAWhole(hasan);

	/*
	 * // Lets see if we can send a ptr to struct rather than a struct. (Hint; No.)
	 * getStructAsAWhole(joe);
     */

	return 0;
}
