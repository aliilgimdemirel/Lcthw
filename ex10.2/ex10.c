//Switch Statements

#include <stdio.h>

int main(int argc, char *argv[])
{
	int j = 1;
	for(j = 1; argv[j]; j++){	
		int i = 0;
		for (i = 0; argv[j][i] != '\0'; i++){
			char letter = argv[j][i];
			printf("%d  ", letter);
			if(letter < 'a'){
				//printf("Hi !");
				letter = letter + ('a'-'A') ;	
			}
		
			//letter = ',';	
			switch (letter){
				case 'a':
					printf("%d: 'a'\n", i);
					break;
				
				case 'e':
					printf("%d: 'e'\n", i);
					break;
	
				case 'i':
					printf("%d: 'i'\n", i);
					break;
	
				case 'o':
					printf("%d: 'o'\n", i);
					break;
	
				case 'u':
					printf("%d: 'u'\n", i);
					break;
					
				case 'y':
					if (i > 2) {
						// it's only sometimes
						printf("%d: 'y'\n", i);
						//break;
					}
					break;
				default:
					printf("%d: %c is not a vowel.\nYou have been to the default case.\n", i, letter);
			}
		}
	}
	return 0;
}
