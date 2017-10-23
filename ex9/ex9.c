#include <stdio.h>
	
//while (TEST){
//	CODE;	
//}

int main(int argc, char *argv[])
{
	/*int i = 0;
	while (i<25) {
		printf("%d ", i);
		i++;
	}*/
	
	/*int i = 25;
	while (i>=0) {
		printf("%d ", i);
		i--;
	}*/
	
	int i = 0;
	do {
		printf("%d ", i);
		i++;
	} while (i<25);

	return 0;
}
