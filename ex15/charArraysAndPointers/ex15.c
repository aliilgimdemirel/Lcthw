// Pointers, Dreaded Pointers
#include <stdio.h>

void printAllChars(char *chrPtrArray[])
{
    printf("chrPtrArray: \t%p \tsizeof(chrPtrArray):\t\t%lu\n", chrPtrArray, sizeof(*chrPtrArray));
	int i = 0;
	char *byte_ptr = *chrPtrArray;
    printf("byte_ptr: \t%p \tsizeof(byte_ptr):\t\t%lu\n", byte_ptr, sizeof(byte_ptr));
    printf("byte_ptr: \t%p \tsizeof(byte_ptr):\t\t%lu\n", &byte_ptr, sizeof(&byte_ptr));
	int j = 0;	
	while(j <3)
	{
		printf("%c", *(byte_ptr+i));
		
		if(*(byte_ptr+i) == '\0' )
		{
			printf("\n");
			j++;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	/*Outputs; */
	int i = 0;

	//char name0[] = {"AHA"};
	//char name1[5] = {"BHA"};
	//char *name2[4] = {"CHA"};
	//char *name3[] = {"DHA"};

	//printf("---\n");
	//printf("name0 was defined as:\tchar name0[] = {\"AHA\"}\n");
    //printf("name0: \t\t%p \tsizeof(name0):\t\t%lu\n", name0, sizeof(name0));
    //printf("name0: \t\t%s \t\tsizeof(name0):\t\t%lu\n", name0, sizeof(name0));
    //printf("&name0: \t%#lx \tsizeof(&name0):\t\t%lu\n", &name0, sizeof(&name0));
    //printf("name0[0]: \t%c \t\tsizeof(name0[0]):\t%lu\n", name0[0], sizeof(name0[0]));
	///*Outputs;
	//	name0: 		0x7ffceefda680 	sizeof(name0):		4
	//	name0: 		AHA 			sizeof(name0):		4
	//	&name0: 	0x7ffceefda680 	sizeof(&name0):		8
	//	name0[0]: 	A 				sizeof(name0[0]):	1
	// */

	//printf("---\n");
	//printf("name1 was defined as:\tchar name1[5] = {\"BHA\"}\n");
    //printf("name1: \t\t%p \tsizeof(name1):\t\t%lu\n", name1, sizeof(name1));
    //printf("name1: \t\t%s \t\tsizeof(name1):\t\t%lu\n", name1, sizeof(name1));
    //printf("&name1: \t%#lx \tsizeof(&name1):\t\t%lu\n", &name1, sizeof(&name1));
    //printf("name1[0]: \t%c \t\tsizeof(name1[0]):\t%lu\n", name1[0], sizeof(name1[0]));
	///*Outputs;
	//	name1: 		0x7ffd17395cb0 	sizeof(name1):		5
	//	name1: 		BHA 			sizeof(name1):		5
	//	&name1: 	0x7ffd17395cb0 	sizeof(&name1):		8
	//	name1[0]: 	B 				sizeof(name1[0]):	1
	//*/

	//printf("---\n");
	//printf("name2 was defined as:\tchar *name2[4] = {\"CHA\"}\n");
	//printf("name2: \t\t%p \tsizeof(name2):\t\t%lu\n", name2, sizeof(name2));	
	//printf("&name2: \t%#lx \tsizeof(&name2):\t\t%lu\n", &name2, sizeof(&name2));	
	//printf("*name2: \t%s \t\tsizeof(*name2):\t\t%lu\n", *name2, sizeof(*name2));	
	//printf("**name2: \t%c \t\tsizeof(**name2):\t%lu\n", **name2, sizeof(**name2));	
	//printf("name2[0]: \t%c \t\tsizeof(name2[0]):\t%lu\n", name2[0], sizeof(name2[0]));	
	//printf("*name2[0]: \t%c \t\tsizeof(*name2[0]):\t%lu\n", *name2[0], sizeof(*name2[0]));	
	///* Outputs;
	//	name2: 		0x7ffccbe62d40 	sizeof(name2): 		32
	//	&name2: 	0x7ffccbe62d40 	sizeof(&name2): 	8
	//	*name2: 	CHA 			sizeof(*name2): 	8
	//	**name2: 	C 				sizeof(**name2): 	1
	//	name2[0]: 	 				sizeof(name2[0]): 	8
	//	*name2[0]: 	C 				sizeof(*name2[0]): 	1
	//*/

	//printf("---\n");
	//printf("name3 was defined as:\tchar *name3[] = {\"DHA\"}\n");
	//printf("name3: \t\t%p \tsizeof(name3):\t\t%lu\n", name3, sizeof(name3));	
	//printf("&name3: \t%#lx \tsizeof(&name3):\t\t%lu\n", &name3, sizeof(&name3));	
	//printf("*name3: \t%s \t\tsizeof(*name3):\t\t%lu\n", *name3, sizeof(*name3));	
	//printf("**name3: \t%c \t\tsizeof(**name3):\t%lu\n", **name3, sizeof(**name3));	
	//printf("name3[0]: \t%c \t\tsizeof(name3[0]):\t%lu\n", name3[0], sizeof(name3[0]));	
	//printf("*name3[0]: \t%c \t\tsizeof(*name3[0]):\t%lu\n", *name3[0], sizeof(*name3[0]));	
	///* Outputs;
	//	name3: 		0x7ffdfa0059f0 	sizeof(name3):		8
	//	&name3: 	0x7ffdfa0059f0 	sizeof(&name3):		8
	//	*name3: 	DHA 			sizeof(*name3):		8
	//	**name3: 	D 				sizeof(**name3):	1
	//	name3[0]: 	� 				sizeof(name3[0]):	8
	//	*name3[0]: 	D 				sizeof(*name3[0]):	1
	//*/
	//
	//char **pnames = name3;

	//printf("---\n");
	//printf("pnames was defined as:\tchar **pnames = name3\n");
	//printf("pnames: \t%p \tsizeof(pnames):\t\t%lu\n", pnames, sizeof(pnames));	
	//printf("&pnames: \t%#lx \tsizeof(&pnames):\t%lu\n", &pnames, sizeof(&pnames));	
	//printf("*pnames: \t%s \t\tsizeof(*pnames):\t%lu\n", *pnames, sizeof(*pnames));	
	//printf("**pnames: \t%c \t\tsizeof(**pnames):\t%lu\n", **pnames, sizeof(**pnames));	
	//printf("pnames[0]: \t%c \t\tsizeof(pnames[0]):\t%lu\n", pnames[0], sizeof(pnames[0]));	
	//printf("*pnames[0]: \t%c \t\tsizeof(*pnames[0]):\t%lu\n", *pnames[0], sizeof(*pnames[0]));	
	///* Outputs;
	//	pnames was defined as:		char **pnames = name3
	//	pnames: 	0x7ffc50f037b0 	sizeof(pnames):		8
	//	&pnames: 	0x7ffc50f037a8 	sizeof(&pnames):	8
	//	*pnames: 	DHA 			sizeof(*pnames):	8
	//	**pnames: 	D 				sizeof(**pnames):	1
	//	pnames[0]: 	� 				sizeof(pnames[0]):	8
	//	*pnames[0]: D 				sizeof(*pnames[0]):	1
	//*/

	char *names4[] = {"Hasan", "sdkfnsdfnsjnfAhmet", "Cano"};

    //printf("---\n");
    //printf("names4 was defined as:\tchar *names4[] = {...}\n");
    printf("names4: \t%p \tsizeof(names4):\t\t%lu\n", names4, sizeof(names4));
    //printf("&names4: \t%#lx \tsizeof(&names4):\t%lu\n", &names4, sizeof(&names4));
    //printf("*names4:s \t%s \t\tsizeof(*names4):\t%lu\n", *names4, sizeof(*names4));
    //printf("*names4:p \t%p \t\tsizeof(*names4):\t%lu\n", *names4, sizeof(*names4));
    //printf("**names4: \t%c \t\tsizeof(**names4):\t%lu\n", **names4, sizeof(**names4));
    //printf("**names4: \t%c \t\tsizeof(**names4):\t%lu\n", &**names4, sizeof(&**names4));
    //printf("names4[0]: \t%c \t\tsizeof(names4[0]):\t%lu\n", names4[0], sizeof(names4[0]));
    //printf("*names4[0]: \t%c \t\tsizeof(*names4[0]):\t%lu\n", *names4[0], sizeof(*names4[0]));
    //printf("*names4[1]: \t%c \t\tsizeof(*names4[1]):\t%lu\n", *names4[1], sizeof(*names4[1]));

	
	printf("---\n");
	printf("---\n");

	printAllChars(names4);

	char *byte_ptr = *names4;
    printf("byte_ptr: \t%p \tsizeof(byte_ptr):\t\t%lu\n", byte_ptr, sizeof(byte_ptr));
	//int j = 0;	
	//while(j <3)
	//{
	//	printf("%c", *(byte_ptr+i));
	//	
	//	if(*(byte_ptr+i) == '\0' )
	//	{
	//		printf("\n");
	//		j++;
	//	}
	//	i++;
	//}

	printf("---\n");
	printf("---\n");


	//int ages[] = { 23, 43, 12, 89, 2 };

	//printf("---\n");
	//printf("ages: \t\t%p \tsizeof(ages):\t\t%lu\n", ages, sizeof(ages));	
	//printf("&ages: \t\t%#lx \tsizeof(&ages):\t\t%lu\n", &ages, sizeof(&ages));	
	//printf("*ages: \t\t%d \t\tsizeof(*ages):\t\t%lu\n", *ages, sizeof(*ages));	
	////printf("**ages: \t%c \t\tsizeof(**ages):\t%lu\n", **ages, sizeof(**ages));	
	//printf("ages[0]: \t%d \t\tsizeof(ages[0]):\t%lu\n", ages[0], sizeof(ages[0]));	
	////printf("*ages[0]: \t%d \t\tsizeof(*ages[0]):\t%lu\n", *ages[0], sizeof(*ages[0]));	




	/*

    // create two arrays we care about
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	//safely get the size of ages
	int count = sizeof(ages) / sizeof(int);

	//first way using indexing
	for (i=0; i < count; i++) {
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");

	//set up the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	// second way using pointers
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n",
			*(cur_name + i), *(cur_age + i) );
	}
	printf("---\n");

	//third way, pointers are just arrays
	for (i = 0;i < count; i++){
		printf("%s is %d years old.\n",
			cur_name[i], cur_age[i]);
	}

	printf("---\n");
	
	//fourth way with pointers in a stupid complex way
	for (cur_name = names, cur_age = ages;
			(cur_age - ages) < count; cur_name++, cur_age++) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);

	}
	*/
	return 0;
}

	//printf("name0 => address: %p\t value: %s\t first char: %c\n",
	//		&name0, name0, &name0);
	//Outputs; name0 => address: 0x7fff6529dd10	 value: AHA	 first char: (square with 0010) 

	//printf("name0 => address: %p\t value: %s\t first char: %c\n",
	//		&name0, name0, name0[0]);
	//Outputs; name0 => address: 0x7ffc7ac562a0	 value: AHA	 first char: A 

	//printf("Sizeofs: name0:%lu\t &name0:%lu\t *name0:%lu\t *name0[0]:%lu\t\n",
	//		sizeof(name0), sizeof(&name0), sizeof(*name0), sizeof(name0[0]));

	//Outputs; Sizeofs: name0:4	 &name0:8	 *name0:1	 *name0[0]:1 

	//printf("---\n");
	//printf("name1 => address: %p\t value: %s\t first char: %c\n",
	//		&name1, name1, &name1);
	//Outputs; name1 => address: 0x7ffc5d40d940	 value: BHA	 first char: @ 

	//printf("name1 => address: %p\t value: %s\t first char: %c\n",
	//		&name1, name1, name1[0]);
	//Outputs; name1 => address: 0x7ffc5d40d940	 value: BHA	 first char: B

	//printf("Sizeofs: name1:%lu\t &name1:%lu\t *name1:%lu\t *name1[0]:%lu\t\n",
	//		sizeof(name1), sizeof(&name1), sizeof(*name1), sizeof(name1[0]));
	//Outputs; Sizeofs: name1:4	 &name1:8	 *name1:1	 *name1[0]:1

	//printf("---\n");
	//printf("name2 => address: %p\t value: %s\t dereferencing it: %s\t first char: %c\n",
	//		&name2, name2, *name2, **name2);
	//Outputs;

	//printf("name2 => address: %p\t value: %d\t dereferencing it: %s\t first char: %c\n",
	//		&name2, name2, *name2, **name2);
	//Outputs;

	//printf("Sizeofs: name2:%lu\t &name2:%lu\t *name2:%lu\t **name2:%lu\t *name2[0]:%lu\t\n",
	//		sizeof(name2), sizeof(&name2), sizeof(*name2), sizeof(**name2), sizeof(name2[0]));


//void printEveryChar(char *chrPtrArray[])
//{
//	int i= 0;	
//	int count = sizeof(*chrPtrArray) / sizeof(char *);
//	printf("count is:%d\n", count);
///*
//    printf("chrPtrArray: \t%p \tsizeof(chrPtrArray):\t\t%lu\n", chrPtrArray, sizeof(chrPtrArray));
//    printf("&chrPtrArray: \t%#lx \tsizeof(&chrPtrArray):\t%lu\n", &chrPtrArray, sizeof(&chrPtrArray));
//    printf("*chrPtrArray:s \t%s \t\tsizeof(*chrPtrArray):\t%lu\n", *chrPtrArray, sizeof(*chrPtrArray));
//    printf("*chrPtrArray:p \t%p \t\tsizeof(*chrPtrArray):\t%lu\n", *chrPtrArray, sizeof(*chrPtrArray));
//    printf("**chrPtrArray: \t%c \t\tsizeof(**chrPtrArray):\t%lu\n", **chrPtrArray, sizeof(**chrPtrArray));
//    printf("**chrPtrArray: \t%c \t\tsizeof(**chrPtrArray):\t%lu\n", &**chrPtrArray, sizeof(&**chrPtrArray));
//    printf("chrPtrArray[0]: \t%c \t\tsizeof(chrPtrArray[0]):\t%lu\n", chrPtrArray[0], sizeof(chrPtrArray[0]));
//    printf("*chrPtrArray[0]: \t%c \t\tsizeof(*chrPtrArray[0]):\t%lu\n", *chrPtrArray[0], sizeof(*chrPtrArray[0]));
//    printf("*chrPtrArray[1]: \t%c \t\tsizeof(*chrPtrArray[1]):\t%lu\n", *chrPtrArray[1], sizeof(*chrPtrArray[1]));
//*/
//
//
////	for(i = 0; i < count; i++){
////		printf("%d'th string is: %s\n", i, *chrPtrArray[i]);
////	}
//
//	i = 0;
//	int j = 0;
//	while(j < 15){
//	
//		char *cur_char = &chrPtrArray[j];
//		printf("sizeof cur_char: %lu\n", sizeof(*cur_char));
//		printf("%d'th char is: %c\n", i, *(cur_char+j));
//	
////		printf("%p %p\n", *(cur_char), *(cur_char+j));
//
//		if(*(cur_char+j) == '\0')
//		{
//			i++;
//			
//			printf("\n");
//		}
//	
//		j++;
//	}
//
//	printf("Count:%d VS i:%d", count, i);
//}
