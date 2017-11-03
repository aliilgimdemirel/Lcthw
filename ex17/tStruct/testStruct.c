#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
//#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

int main(int argc, char *argv[])
{
	//int MAX_DATA = 512;

	struct Address addr = {.id = 0, .name = "what?my Name is!" };

	printf("Print myName: %s\n", addr.name);

	return 0;
}
