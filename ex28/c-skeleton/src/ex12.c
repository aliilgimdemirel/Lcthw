// Sizes and Arrays
#include <stdio.h>


int main(int argc, char* argv[])
{
  int areas[] = {10, 12, 13, 14, 20};
  char name[] = "Zed";
  char full_name[] = {
	  'Z', 'e', 'd',
	  ' ', 'A', '.', ' ',
	  'S', 'h', 'a', 'w', '\0'
	  };
 
  //Warning: On some systems you may have to change the
  //%ld in this code to a %u since it will use unsigned ints
  printf("The size of an int : %ld\n", sizeof(int));
  printf("The size of areas (int[]): %ld\n", sizeof(areas));
  printf("The number of ints in areas: %ld\n",
	  sizeof(areas) / sizeof(int));
  printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1] );

  printf("The size of a char: %ld\n", sizeof(char));
  printf("The size of name (char[]): %ld\n", sizeof(name) );
  printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));
  
  printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
  printf("The number of chars: %ld\n", 
	  sizeof(full_name) / sizeof(char));

  printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

  /*
   * Extra Credit -1- BEGIN
   * Try assigning to elements in the areas array with areas[0] = 100; and similar
   */
  	printf("=Extra Creadit -1-=\n");

	areas[3] = 100;
	areas[6] = 100;

	int i = 0;
	for ( i = 0; i < (sizeof(areas)/sizeof(int)) ; i++) {
		if ( areas[i] == 0) {
		} else {
			printf("Stored value in position %d is %d\n", i, areas[i]);
		}
	}

  /*
   * Extra Credit -1- END 
   */

  /*
   * Extra Credit -2- BEGIN
   * Try assigning to elements of name and full_name
   */
  	printf("==Extra Creadit -2-==\n");

	name[2] = 'G';
	name[6] = 100;

	i = 0;
	for ( i = 0; i < (sizeof(name)/sizeof(char)) ; i++) {
			printf("name contains at position %d is %c\n", i, name[i]);
	}

  /*
   * Extra Credit -2- END 
   */

  /*
   * Extra Credit -3- BEGIN
   * Try setting one element of areas to a character from name.
   */
  	printf("===Extra Creadit -3-===\n");

	areas[2] = name[2] ;
//	name[6] = 100;

	i = 0;
	for ( i = 0; i < (sizeof(areas)/sizeof(int)) ; i++) {
			printf("name contains at position %d is %d\n", i, areas[i]);
	}

  /*
   * Extra Credit -3- END 
   */


	return 0;

}
