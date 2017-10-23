#include <stdio.h>

int main()
{
	printf("Hello World!");


	int testIf = 5;

	int testSwitch = 5;

	int testWhile = 5;

	int testWhileBreak = 5;

	int testDoWhile = 5;

	int testFor = 5;

	// Lets put in a IF-ELSE Statement
	if(CONDITION) {
		CODE;
	} else if(CONDITION) {
		CODE;
	} else {
		CODE;
	}

	// And now Lets put in a SWITCH Statement
	switch(OPERAND) {
		case CONSTANT:
			CODE;
			break;
		case CONSTANT:
			CODE;
			break;
		default:
			CODE;
	}

	// Now its time for some WHILE LOOP'in
	while(CONDITION) {
		CODE;
	}

	// Double Condition WHILE's can be done through the following way also; while-cont.-loop
	while(1st_CONDITION) {
		CODE; // Maybe
		if(2nd_CONDITION) {
			continue; // important part is here. Jumps back into next WHILE
		}
		CODE;
	}
	
	// Double check WHILE with exit conditions; while-break-loop
	while(1st_CONDITION) {
		CODE; // Bcz why not!
		if(2nd_CONDITION) {
			break; // while 1st happening if 2nd happens IM OUT !
		}
		CODE;
	}

	// The do-while-loop; runs the code then tests to see whether to run it again.
	do {
		CODE;
	} while(TEST);


	// the infamous For loop;
	for (INIT; TEST; POST) {
		CODE;
	}

	// to create a set of integer constants; ENUM

	enum { CONST1, CONST2, CONST3 } hasan;

	if(ERROR_TEST) {
		goto fail; // or any other label instead of fail

	}	
	fail:
		CODE; // printf("I'm sorry that you've failed my young PADAWAN")

	// function definition
	TYPE NAME (ARG1, ARG2, ..) {
		CODE;
		return VALUE;
	}

	// a typedef defines a new type
	typedef DEFINITION IDENTIFIER; // an example; typedef unsigned char byte;

	// A struct is a packaging of many base data types into a single concept, which are used eavily in C:	
	struct NAME {
		ELEMENTS;
	}	[VARIABLE_NAME]; // [VARIABLE_NAME] is OPTIONAL !! 

	typedef struct [struct_NAME] {
		ELEMENTS;
	} IDENTIFIERS;

	union NAME {
		ELEMENTS;
	} [VARIABLE_NAME];

		



	return 0;
}
