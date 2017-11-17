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

  printf("another each: %c %c %c %c \n",
 	  another[0], another[1], another[2], another[3]);

  // set up the name
  name[0] = 'Z';
  name[1] = 'e';
  name[2] = 'd';
  name[3] = 'J';
  name[4] = 'J';
  name[5] = 'd';
  name[6] = 'J';
  name[7] = 'J';
  name[8] = 'M';

  // print the name like a string
  printf("name: %s\n", name);

  printf("name+3: %c\t %0#x\n" , *(name+3) , *(name+3) );
  printf("name+4: %c\t %0#x\n" , *(name+4) , *(name+4) );
  printf("name+5: %c\t %0#x\n" , *(name+5) , *(name+5) );
  printf("name+6: %c\t %0#x\n" , *(name+6) , *(name+6) );
  printf("name+7: %c\t %0#x\n" , *(name+7) , *(name+7) );
  printf("name+8: %c\t %0#x\n" , *(name+8) , *(name+8) );
  printf("name+9: %c\t %0#x\n" , *(name+9) , *(name+9) );
  printf("name+10:%c\t %0#x\n", *(name+10), *(name+10) );
  printf("name+11:%c\t %0#x\n", *(name+11), *(name+11) );
  printf("name+12:%c\t %0#x\n", *(name+12), *(name+12) );
  printf("name+13:%c\t %0#x\n", *(name+13), *(name+13) );
  printf("name+14:%c\t %0#x\n", *(name+14), *(name+14) );
  printf("name+15:%c\t %0#x\n", *(name+15), *(name+15) );
  printf("name+16:%c\t %0#x\n", *(name+16), *(name+16) );
  printf("name+17:%c\t %0#x\n", *(name+17), *(name+17) );
  printf("name+18:%c\t %0#x\n", *(name+18), *(name+18) );
  printf("name+19:%c\t %0#x\n", *(name+19), *(name+19) );
// The purpose of the above code was to find where the next 
// jibberish byte 'jyte' and fill the bytes towards that memory so that the 
// effect of the absence of '\0' terminator byte is visible.


// following 2 lines are sort of crucial.
// If they are not here, the stack ends and the program is stopped abruptly.
  char kanka[300] = {"OLEEEY"};
  printf("kanka is: %s\n",kanka);

  return 0;

}

///* 
// * Extra Credit -1- BEGIN;
// * Assign the characters into numbers, and then use printf to
// * print them one character at a time.
// * What kind of compiler warnings do you get ? 
// */
//	int i = 0;
//
//	numbers[0] = '4';
//	numbers[1] = 'd';
//	numbers[2] = 'F';
//	numbers[3] = 'P';
//
//    for (i = 0; i < 4; i++) {
//        printf("Assign characters into numbers, print as ints!: %d\n", numbers[i]);
//    }
//
//// This much we knew.. Characters are ascii codes and can be interpreted as integers.
//
//    for (i = 0; i < 4; i++) {
//        printf("Assign characters into numbers, print as chars!: %c\n", numbers[i]);
//    }
//
///* 
// * Extra Credit -1- END;
// */
//
//
//
///*
// * Extra Credit -2- BEGIN
// * Do the invers for name, trying to treat it like an array of int and print it out one int at a time.
// * What does the debugger think of that ?
// */
// 
//	name[0] = '4';
//    name[1] = '0';
//    name[2] = '4';
//    name[3] = '5';
//
//    for (i = 0; i < 4; i++) {
//        printf("Assign integers to characters: %c\n", name[i]);
//    }
//
//// So assigning ints to chars result as only the last character ending inside the char space.
//// compiler was giving errors anyways.
//
//// warning: overflow in implicit constant conversion [-Woverflow]
//// warning: multi-character character constant [-Wmultichar]
////     name[3] = '25';
//
///*
// * Extra Credit -2- END
// */
//
//
///* 
// * Extra Credit -4- BEGIN;
// * If an array of characters is 4 bytes long, and an integer is 4 bytes long, 
// * then can you treat the whole name array like it's just an integer?
// * How might you accomplish this crazy hack ?
// */
//
//	printf("This is name as a string: %s\n", name);
//	
//	for (i = 0; i < 4; i++)	{
//		printf("This is numbers as a string: %c\n", numbers[i]);
//	}
//	//printf("This is numbers as a string: %s\n", (char *)numbers);
//
//	char name1[4] = {"AA"};
//	char name88[16] = {"aa"};
//	char name2[4] = {"A"};
//
//	printf("clash of name1-name2 W ptr= %u\n", *name1-*name2);
//	printf("clash of name1-name2 W/o ptr= %li\n", name1-name2);
//	printf("Lets see the clash of name88-name2= %u\n", *name88-*name2);
//	printf("diff btween cases: %d\n", 'A'-'a');
//
//	char name3[5] = {"AhAa"};
//	char name4[4] = {"Ah"};
//
//	printf("Lets see the clash of name3-name4= %li\n", name3-name4);
//
//	//char name5[4] = {"873"};
//
//	int hasan = ((2^24) * 12) +( (2^16) * 0) +( (2^8) *0) +( (2^0) * 0);
//	printf("The value of hasan is: %#x\n" , hasan);
//	printf("The adres of hasan is: %#x\n" , &hasan);
//	int *mahmut = &hasan;
//	char *byte = &hasan;
//
//	printf("Where are we pointing at?\nmahmut:\t%p\nbyte:\t%p\n", mahmut, byte);
//	printf("What is the value where they point at?\nmahmut:\t%#x\nbyte:\t%#x\n", *mahmut, *byte);
//
//
///*
// * Extra Credit -4- END
// */

