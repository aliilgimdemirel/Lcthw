//For-loops and Arrays of Strings
#include <stdio.h>


int main(int argc, char *argv[])
{
	printf("Hello World!\n");

	int i = 0;

	// go through each string in argv
	// why am I skipping argv[0]?
	for (i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}
	
	printf("Value of i, out of Args loop: %d\n", i);

	// let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington" ,"Texas"
	};

	int num_states = 4;
	
	for (i = 0; i < num_states; i++){
		printf("state %d: %s\n", i, states[i]);
	}



	/*
	 * Extra Credit -1- BEGIN
	 * Try assigning to elements of name and full_name
	 */
	  printf("=Extra Creadit -1-=\n");
	
	
	/*
	 * Extra Credit -1- END 
	 */
	
	states[2] = argv[1];	
	
	for (i = 0; i < num_states; i++){
		printf("state %d: %s\n", i, states[i]);
	}

	printf("Value of i, out of States loop: %d\n", i);

	int j,k = 0;
	i = 0;
	for(i=0,j=20,k=100;(i<j) || k > 80 ;i++,j--,k--) {
		printf("Value of i: %d j: %d k: %d\n", i ,j,k);
	}	 
	

	return 0;
}
