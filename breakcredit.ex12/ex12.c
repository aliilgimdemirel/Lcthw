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
 
  //Warning: On some systems you may habe to change the
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

  //Begining of Extra Stuff 

  float hasan[] = {1.2, 3.4, 8.43};
  
  printf("The size of an float : %ld\n", sizeof(float));
  printf("The size of areas (float[]): %ld\n", sizeof(hasan));
  printf("The number of float in hasan: %ld\n",
	  sizeof(hasan) / sizeof(float));

  double mahmut[] = {0.004, 0.213234};
  
  printf("The size of an double : %ld\n", sizeof(double));
  printf("The size of areas (double[]): %ld\n", sizeof(mahmut));
  printf("The number of doubles in mahmut: %ld\n",
	  sizeof(mahmut) / sizeof(double));

  unsigned int mahmu[] = {4, 234};
  
  printf("The size of an unsigned int : %ld\n", sizeof(unsigned int));
  printf("The size of areas (unsigned int[]): %ld\n", sizeof(mahmu));
  printf("The number of unsigned ints in mahmu: %ld\n",
	  sizeof(mahmu) / sizeof(unsigned int));

  long int mah[] = {4, 234};
  
  printf("The size of an long int : %ld\n", sizeof(long int));
  printf("The size of areas (long int[]): %ld\n", sizeof(mah));
  printf("The number of long ints in mah: %ld\n",
	  sizeof(mah) / sizeof(long int));

  long long ma[] = {4, 234, 239847, 45675467897653};
  
  printf("The size of an long long int : %ld\n", sizeof(long long));
  printf("The size of areas (long long int[]): %ld\n", sizeof(ma));
  printf("The number of long long ints in ma: %ld\n",
	  sizeof(ma) / sizeof(long long));

  printf("The size of an short int : %ld\n", sizeof(short int));
  printf("The size of an int : %ld\n", sizeof(int));
  printf("The size of an unsigned : %ld\n", sizeof(unsigned ));
  printf("The size of an unsigned int : %ld\n", sizeof(unsigned int));
  printf("The size of an signed int : %ld\n", sizeof(signed int));

  printf("The size of an long : %ld\n", sizeof(long));
  printf("The size of an long int : %ld\n", sizeof(long int));
  printf("The size of an unsigned long: %ld\n", sizeof(unsigned long));
  printf("The size of an unsigned long int : %ld\n", sizeof(unsigned long int));

  printf("The size of an long long : %ld\n", sizeof(long long));
  printf("The size of an long long int : %ld\n", sizeof(long long int));
  printf("The size of an unsigned long long: %ld\n", sizeof(unsigned long long));
  printf("The size of an unsigned long long int : %ld\n", sizeof(unsigned long long int));

  printf("The size of an float : %ld\n", sizeof(float));
  printf("The size of an double : %ld\n", sizeof(double));
  printf("The size of an long double : %ld\n", sizeof(long double));

  return 0;

}
