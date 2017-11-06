#include <stdio.h>

/*
if(TEST){
#	CODE;
#} else if(TEST){
	CODE;
} else{
	CODE;
}
*/

// ARGument Count ARGvector. Program Name is the FIRST (argv[0] ) argument to the program itself.
int main(int argc, char *argv[]) // main also works ? works with WARNING
{

	//int i = 0;
	
	if(argc == 0){
		printf("You do NOT have any arguments.\n");
	} else if(argc == 1 ){
		printf("You only have one argument. You suck.\n");		
	} else if(argc > 1 && argc < 4){
		printf("Here are your arguments:\n");
		for(int i = 0; i < argc; i++){
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments. You suck.\n");
	}


	return 0;
}
