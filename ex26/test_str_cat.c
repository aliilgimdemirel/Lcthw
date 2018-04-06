#include <string.h>
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char* argv[])
{
	char *temp_str = "\0";
	char *temp_str2 = "hasan";
	char *srch_str = malloc(sizeof(char) * 40);
	memset(srch_str, 0, 40);
	
	printf("DEBUG\n");
	strcat(srch_str, temp_str);
	printf("srch_str is: \"%s\"\n",srch_str);

	strcat(srch_str, temp_str2);
	printf("srch_str is: \"%s\"\n",srch_str);

	return 0;
}
