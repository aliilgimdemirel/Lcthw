// Duff's Device 
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dbg.h"

int normal_copy(char *from, char *to, int count)
{
	int i = 0;
	
	for (i = 0; i < count; i++) {
		to[i] = from[i];
	}
	
	return i;
}

int duffs_device(char *from, char *to, int count)
{
	{
		int n = (count + 7) / 8;

		switch (count % 8) {
			case 0:
				do {
					*to++ = *from++;
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

	int i = 0;
	clock_t tic, toc;

	// set up the from to have some stuff
    tic = clock();
	for (i = 0; i < 2000; i ++) {
		memset(from, 'x', 1000);
	}
    toc = clock();
    printf("MEMset; Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	
	// set it to a failure mode
	//memset(to, 'y', 1000);
	//check(valid_copy(to, 1000, 'y'), "Not initialized right.");

	// set it to a failure mode
    tic = clock();
	for (i = 0; i < 2000; i ++) {
		rc = normal_copy(from, to, 1000);
	}
    toc = clock();
    printf("Normal_Copy; Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	//rc = normal_copy(from, to, 1000);
	//check(rc == 1000, "Normal copy failed: %d", rc);
	//check(valid_copy(to, 1000, 'y'), "Not initialized right.");

	// reset
    tic = clock();
	for (i = 0; i < 2000; i ++) {
		memset(to, 'y', 1000);
	}
    toc = clock();
    printf("MEMset; Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	// duffs version
    tic = clock();
	for (i = 0; i < 2000; i ++) {
		rc = duffs_device(from, to, 1000);
	}
    toc = clock();
    printf("duffs; Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	//check(rc == 1000, "Duff's device failed: %d", rc);
	//check(valid_copy(to, 1000, 'x'), "Duff's device failed copy.");
	
	// zeds version
    tic = clock();
	for (i = 0; i < 2000; i ++) {
		rc = zeds_device(from, to, 1000);
	}
    toc = clock();
    printf("zeds; Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	//check(rc == 1000, "zed's device failed: %d", rc);
	//check(valid_copy(to, 1000, 'x'), "zed's device failed copy.");

    tic = clock();
	for (i = 0; i < 2000; i ++) {
		memcpy(from, to, 1000);
	}
    toc = clock();
    printf("MEMcpy; Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);


    tic = clock();
	for (i = 0; i < 2000; i ++) {
		memmove(from, to, 1000);
	}
    toc = clock();
    printf("MEMmove; Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	return 0;
error:
	return 1;
}
