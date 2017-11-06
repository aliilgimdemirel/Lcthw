// Arrays and strings
#include <stdio.h>


int main(int argc, char* argv[])
{

  int numbers[4] = { 4 };
  printf("\nLength of numbers 'int numbers[4] = {4}': %lu\n\n", sizeof(numbers)/sizeof(int)      );
  char name[4] = { 'a' };
  printf("\nLength of numbers 'char name[4] = { 'a' };': %lu\n\n", sizeof(name)/sizeof(char)      );
  
  // first, print them out raw
  printf("Content of int array numbers element by element: %d %d %d %d check string\n",
	  numbers[0], numbers[1], numbers[2], numbers[3] );                  

  printf("Content of char array name elem by elem: %c %c %c %c check string\n",
	  name[0], name[1], name[2], name[3]);

  /* We can see now that;
   * 1- The size of arrays is the # inside []'s
   * 2- Declaration of an int array automatically does some magic
   *    it puts the values starting from index 0. 
   * 3- Char arrays put null bytes to its empty indexes.
   *    It is similar to the ineffective element of an operation;
   *    for integers 0, for characters \0.
   */ 
 
  printf("Print name as a whole: %s\n", name);
  //printf("numbers: %d\n", numbers);

  // set up the numbers
  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;
 
  // set up the name
  name[0] = 'Z';
  name[1] = 'e';
  name[2] = 'd';
  name[3] = '\0';

  printf("\nNow we Initialized stuff\n");

  // then print them out initialized
  printf("numbers: %d %d %d %d\n",
	  numbers[0], numbers[1], numbers[2], numbers[3] );

  printf("name each: %c %c %c %c\n",
	  name[0], name[1], name[2], name[3]);

  // print the name like a string
  printf("name: %s\n", name);

  //another way to use name
  char *another = "Zed";

  printf("another: %s\n", another);

  printf("another each: %c %c %c %c %c\n",
 	  another[0], another[1], another[2], another[3], another[0]);



/* 
 * Extra Credit -1- BEGIN;
 * Assign the characters into numbers, and then use printf to
 * print them one character at a time.
 * What kind of compiler warnings do you get ? 
 */
	int i = 0;

	numbers[0] = '4';
	numbers[1] = 'd';
	numbers[2] = 'F';
	numbers[3] = 'P';

    for (i = 0; i < 4; i++) {
        printf("Assign characters into numbers, print as ints!: %d\n", numbers[i]);
    }

// This much we knew.. Characters are ascii codes and can be interpreted as integers.

    for (i = 0; i < 4; i++) {
        printf("Assign characters into numbers, print as chars!: %c\n", numbers[i]);
    }

/* 
 * Extra Credit -1- END;
 */



/*
 * Extra Credit -2- BEGIN
 * Do the invers for name, trying to treat it like an array of int and print it out one int at a time.
 * What does the debugger think of that ?
 */
 
	name[0] = '4';
    name[1] = '0';
    name[2] = '4';
    name[3] = '5';

    for (i = 0; i < 4; i++) {
        printf("Assign integers to characters: %c\n", name[i]);
    }

// So assigning ints to chars result as only the last character ending inside the char space.
// compiler was giving errors anyways.

// warning: overflow in implicit constant conversion [-Woverflow]
// warning: multi-character character constant [-Wmultichar]
//     name[3] = '25';

/*
 * Extra Credit -2- END
 */


/* 
 * Extra Credit -4- BEGIN;
 * If an array of characters is 4 bytes long, and an integer is 4 bytes long, 
 * then can you treat the whole name array like it's just an integer?
 * How might you accomplish this crazy hack ?
 */

	printf("This is name as a string: %s\n", name);
	
	for (i = 0; i < 4; i++)	{
		printf("This is numbers as a string: %c\n", numbers[i]);
	}
	//printf("This is numbers as a string: %s\n", (char *)numbers);

	char name1[4] = {"AA"};
	char name88[16] = {"aa"};
	char name2[4] = {"A"};

	printf("clash of name1-name2 W ptr= %u\n", *name1-*name2);
	printf("clash of name1-name2 W/o ptr= %li\n", name1-name2);
	printf("Lets see the clash of name88-name2= %u\n", *name88-*name2);
	printf("diff btween cases: %d\n", 'A'-'a');

	char name3[5] = {"AhAa"};
	char name4[4] = {"Ah"};

	printf("Lets see the clash of name3-name4= %li\n", name3-name4);

	//char name5[4] = {"873"};

/*
 * Extra Credit -4- END
 */


  return 0;

}
