#include <stdio.h>
//#include <string.h>


int main()
{
	char kck[] = "joe";
	char byk[] = "joeblack";

	printf("kck :%s,\t size of kck: %lu,\t strlen of kck: %lu\n", kck, sizeof(kck), strlen(kck));
	printf("byk :%s,\t size of byk: %lu,\t strlen of byk: %lu\n", byk, sizeof(byk), strlen(byk));

	char *pkck = "Joe";
	char *pbyk = "JoeBlack";

	printf("pkck :%s,\t size of pkck: %lu,\tstrlen of pkck: %lu\n", pkck, sizeof(pkck), strlen(pkck));
	printf("pbyk :%s,\t size of pbyk: %lu,\tstrlen of pbyk: %lu\n", pbyk, sizeof(pbyk), strlen(pbyk));

	printf("pkck :%c\t, size of pkck: %lu\n", *pkck, sizeof(*pkck));
	printf("pbyk :%c\t, size of pbyk: %lu\n", *pbyk, sizeof(*pbyk));


	char t1[10] = {'P', 'K', 'e', '9', '\0'};
	char t3[5] ;
	char t2[5] = {'P', 'K', 'e', '9', 'K' };
	
	t3[0] = 'k' ;
	t3[1] = 'l' ;
	t3[2] = 'j' ;
	t3[3] = 'h' ;
	t3[4] = 'd' ;





	printf("t1 :%s,\t size of t1: %lu,\t strlen of t1: %lu\n", t1, sizeof(t1), strlen(t1));
	printf("t2 :%s,\t size of t2: %lu,\t strlen of t2: %lu\n", t2, sizeof(t2), strlen(t2));
	printf("t3 :%s,\t size of t3: %lu,\t strlen of t3: %lu\n", t3, sizeof(t3), strlen(t3));
	printf("here is t3:%s\n", t3);

	return 0;
}
