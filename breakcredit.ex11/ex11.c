// Arrays and strings
#include <stdio.h>
#include <string.h>

/*
void char2int(int *dest, char *src)
{

  printf("input int for    : %d, control", dest);
  printf("input string for : %s, control", src);
  

  return ;
}
*/

/*
void extraCredit2()
{
  char someChars[4] = { 1, 2, 4, '\0' };

  printf("someChars as decimal  : %d\n", someChars); //
  printf("someChars as string   : %s\n", someChars); //  
  printf("someChars char by char: %c %c %c %c\n",
	  someChars[0], 
	  someChars[1],
	  someChars[2],
	  someChars[3]);



  return ;
}
*/

void extraCreditIntArrayCharInit()
{
  //excess elements in array initializer
  //int someNumbers[4] = {'a', 'A', 'Z', 'P'};
  
  //no warnings whatsoever, 
  int someNumbers[4] = {'a', 'A', 'Z', '\0' };
  
  //long int someLongNumbers[4] = {'a', 'A', 'Z', 'P'};
  
  //printf("someNumbers as decimal  : %d\n", someNumbers); //garbage
  //printf("someNumbers as string   : %s\n", someNumbers); //does not work like chars & strings
  printf("someNumbers char by char: %c %c %c %c\n",
	  someNumbers[0], 
	  someNumbers[1],
	  someNumbers[2],
	  someNumbers[3]);
  
  //printf("someLongNumbers as decimal  : %d\n", someLongNumbers);
  //printf("someLongNumbers as string   : %s\n", someLongNumbers);
  /*printf("someLongNumbers char by char: %c %c %c %c\n",
	  someLongNumbers[0], 
	  someLongNumbers[1],
	  someLongNumbers[2],
	  someLongNumbers[3]);
  */
  return ;
}

int main(int argc, char* argv[])
{
  //char *extraCreditSrc[4];
  //int *extraCreditDest[4];

  //extraCredit char2int
  //char2int(int* extraCreditDest, char *extraCreditSrc);

  //extraCreditIntArrayCharInit();
  //extraCredit2();

  int numbers[4] = { 4 };
  char name[4] = { 'a' };
  char name2[4] = { 'b' };
  name2[2] = 'F'; 

  char name3[4] = { 'b' };
  name3[1] = 'F'; 
 
  // C treats an array of Char's as a String. !!!
  printf("name1 each: %c %c %c %c\n",
	  name[0], name[1], name[2], name[3]);

  printf("name2 each: %c %c %c %c\n",
	  name2[0], name2[1], name2[2], name2[3]);
  
  printf("name3 each: %c %c %c %c\n",
	  name3[0], name3[1], name3[2], name3[3]);
  
  printf("name: %s\n", name);
  printf("name2: %s\n", name2);
  printf("name3: %s\n", name3); 
  // From the Book: "...the C language doesn't differentiate between 
  // a string and an arrac of characters."
  // C treats an array of Char's as a String. !!!
  

  // first, print them out raw
  printf("numbers: %d %d %d %d\n",
	  numbers[0], numbers[1], numbers[2], numbers[3] );

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

  printf("\nNow that we have Initialized stuff\n");

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



  //char *charPtr = 's';
  //char *charPtr ; //output>"charPtr : (null)" // W>"‘charPtr’ is used uninitialized in this function"
  //char *charPtr[10] = "Hasan"; //output>"error: invalid initializer"
  //char *charPtr[10] = "HasanHasan"; //output>"error: invalid initializer"
  //char *charPtr[10] = "HasanHasa"; //output>"error: invalid initializer"
  //char *charPtr = "HasanHasa"; //output>"HasanHasa"

  //char *charPtr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  /*
  warning: initialization makes pointer from integer without a cast [-Wint-conversion]
     char *charPtr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
                        ^
  ex11.c:147:24: note: (near initialization for ‘charPtr[0]’)
  */
  
  int intPtr[5] = {1}; 
  char charPtr[6] = "Hasan";

  intPtr[1] = 2;
  intPtr[2] = 3;
  intPtr[3] = 4;
  intPtr[4] = 5;

  printf("size of intPtr: %d.\nsize of charPtr: %d.\n", sizeof(intPtr), sizeof(charPtr) );
  printf("size of intPtr element: %d.\nsize of charPtr element: %d.\n", sizeof(intPtr[0]), sizeof(charPtr[0]) );


  printf("charPtr : %s\n", charPtr);
  
  printf("intPtr  : %d\n", intPtr);

  printf("another each: %c %c %c %c %c\n",
          charPtr[0], charPtr[1], charPtr[2], charPtr[3], charPtr[4]);


  printf("another each: %d %d %d %d %d\n",
          intPtr[0], intPtr[1], intPtr[2], intPtr[3], intPtr[4]);


  memcpy( intPtr, charPtr, 5);

  printf("charPtr : %s\n", charPtr);
  
  printf("intPtr  : %d\n", intPtr);

  printf("another each: %d %d %d %d %d\n",
          intPtr[0], intPtr[1], intPtr[2], intPtr[3], intPtr[4]);

  printf("another each: %d %d %d %d %d\n",
          charPtr[0], charPtr[1], charPtr[2], charPtr[3], charPtr[4]);

  printf("another each: %c %c %c %c %c\n",
          charPtr[0], charPtr[1], charPtr[2], charPtr[3], charPtr[4]);

  return 0;

}
