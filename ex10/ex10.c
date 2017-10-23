#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	for (i = 0; argv[1][i] != '\0'; i++){
		char letter = argv[1][i];
		//int ahmet = 89;
		int mehmet ;
		switch (mehmet){
			case 'a':
			case 'A':
				printf("%d: 'A'\n", i);
				break;
			
			case 'e':
			case 'E':
				printf("%d: 'E'\n", i);
				break;

			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
				break;

			case 'o':
			case 'O':
				printf("%d: 'O'\n", i);
				break;

			case 'u':
			case 'U':
				printf("%d: 'U'\n", i);
				break;
				
			case 'y':
			case 'Y':
				if (i > 2) {
					// it's only sometimes
					printf("%d: 'Y'\n", i);
					break;
				}
			default:
				printf("%d: %c is not a vowel.\nYou have been to the default case.\n", i, letter);
		}
	}
	return 0;
}
