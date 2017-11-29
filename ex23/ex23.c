// Duff's Device 
#include <stdio.h>
#include <string.h>
#include "dbg.h"


#define LAYDUFF(x, y) \
    case ((0 ## x ## y) + 1) : *to++ = *from++

#define SEVEN_AT_ONCE(x) \
    LAYDUFF(x,6); \
    LAYDUFF(x,5); \
    LAYDUFF(x,4); \
    LAYDUFF(x,3); \
    LAYDUFF(x,2); \
    LAYDUFF(x,1); \
    LAYDUFF(x,0)

#define EIGHT_AT_ONCE(x)    \
    LAYDUFF(x,7);           \
    SEVEN_AT_ONCE(x)


int normal_copy(char *from, char *to, int count)
{
	int i = 0;
	
	for (i = 0; i < count; i++) {
		to[i] = from[i];
	}
	
	return i;
}

int duffs_device(char *from, char *to, int count, int duffs_var)
{
	{
		int n = (count + duffs_var - 1) / duffs_var;

		switch (count % duffs_var) {
			case 0:
				do {
					*to++ = *from++;
					SEVEN_AT_ONCE(3);
					EIGHT_AT_ONCE(2);
					EIGHT_AT_ONCE(1);
					EIGHT_AT_ONCE(0);
					//*to++ = *from++;
					//case 7:
					//	*to++ = *from++;
					//case 6:
					//	*to++ = *from++;
					//case 5:
					//	*to++ = *from++;
					//case 4:
					//	*to++ = *from++;
					//case 3:
					//	*to++ = *from++;
					//case 2:
					//	*to++ = *from++;
					//case 1:
					//	*to++ = *from++;
				} while(--n > 0);
		}
	}
	
	return count;
}

int zeds_device(char *from, char *to, int count)
{
	{
		int n = (count + 7) / 8;

		switch(count % 8) {
			case 0:
again:			*to++ = *from++;
			case 7:
				*to++ = *from++;
			case 6:
				*to++ = *from++;
			case 5:
				*to++ = *from++;
			case 4:
				*to++ = *from++;
			case 3:
				*to++ = *from++;
			case 2:
				*to++ = *from++;
			case 1:
				*to++ = *from++;
			if ( --n > 0) {
				goto again;
			}
		}
	}
	
	return count;
}

int valid_copy(char *data, int count, char expects)
{
	int i = 0;
	
	for (i = 0; i < count; i++) {
		if (data[i] != expects) {
			log_err("[%d] %c != %c", i, data[i], expects);
			return 0;
		}		
	}
	
	return 1;
}

int main(int argc, char *argv[])
{
	char from[1000] = { 'a' };
	char to[1000] = { 'c' };
	int rc = 0;

	// set up the from to have some stuff
	memset(from, 'x', 1000);

	// set it to a failure mode
	//memset(to, 'y', 1000);
	//check(valid_copy(to, 1000, 'y'), "Not initialized right.");

	// set it to a failure mode
	//rc = normal_copy(from, to, 1000);
	//check(rc == 1000, "Normal copy failed: %d", rc);
	//check(valid_copy(to, 1000, 'y'), "Not initialized right.");

	// reset
	memset(to, 'y', 1000);

	// duffs version
	rc = duffs_device(from, to, 1000, 32);
	check(rc == 1000, "Duff's device failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Duff's device failed copy.");
	
	// zeds version
	rc = zeds_device(from, to, 1000);
	check(rc == 1000, "zed's device failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "zed's device failed copy.");

	return 0;
error:
	return 1;
}
