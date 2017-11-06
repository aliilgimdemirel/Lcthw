#include <stdio.h>

int main(int argc, char *argv[])
{
    char name[4] = {'A'};

    int *name_int;
    name_int = &name;
    printf("%d\n", *name_int);

	int i;
	char nameString[4] = {'A'};
	int namer= 0;
	
	for ( i = 0; i < 4; ++i )
	{
	   namer = (namer << 8) + nameString[i];
	}

	printf("%c %c %c %c\n", nameString[0], nameString[1], nameString[2], nameString[3]);
	printf("%#x %#x %#x %#x\n", nameString[0], nameString[1], nameString[2], nameString[3]);
	
	printf("%c %c %c %c\n", (char *)&namer, &namer+1, &namer+2, &namer+3);
	printf("%#x %#x %#x %#x\n", &namer, &namer+1, &namer+2, &namer+3);
	
	printf("nameString\n %d\n", *nameString);
	printf("%#x\n", *nameString);
	printf("name \n%#x\n", namer);
	printf("%d\n", namer);

	int hexu = 7;
	printf("%#x\n", hexu);


    return 0;
}
