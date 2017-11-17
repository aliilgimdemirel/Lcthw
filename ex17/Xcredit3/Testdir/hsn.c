#include <stdio.h>


int main()
{
	int numbers[6] = {5};
	char t1[10] = {'P', 'K', 'e', '9', '\0'};
	char t3[5] ;
	char t2[5] = {'P', 'K', 'e', '9', 'K' };
	
	t3[0] = 'k' ;
	t3[1] = 'l' ;
	t3[2] = 'j' ;
	t3[3] = 'h' ;
	t3[4] = 'd' ;

	printf("numbers are: %d %d %d %d %d %d\n",
			numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],numbers[5]);



	printf("t1 :%s,\t size of t1: %lu\n", t1, sizeof(t1));
	printf("here is t3:%s.\n", t3);
	printf("t2 :%s,\t size of t2: %lu\n", t2, sizeof(t2));
	printf("t3 :%s,\t size of t3: %lu\n", t3, sizeof(t3));

	char kck[] = "joe";
	char byk[] = "joeblack";

	printf("kck :%s,\t size of kck: %lu\n", kck, sizeof(kck));
	printf("byk :%s,\t size of byk: %lu\n", byk, sizeof(byk));

	char *pkck = "Joe";
	char *pbyk = "JoeBlack";

	printf("pkck :%s,\t size of pkck: %lu\n", pkck, sizeof(pkck));
	printf("pbyk :%s,\t size of pbyk: %lu\n", pbyk, sizeof(pbyk));

	printf("pkck :%c\t, size of pkck: %lu\n", *pkck, sizeof(*pkck));
	printf("pbyk :%c\t, size of pbyk: %lu\n", *pbyk, sizeof(*pbyk));

	printf("t3+4:%c\n", *(t3+4) );
	printf("t3+5:%c\n", *(t3+5) );


	return 0;
}
