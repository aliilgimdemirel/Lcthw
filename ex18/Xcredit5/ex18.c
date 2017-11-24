// Pointers To functions

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


/** Our old friend die from ex17 */

void die(const char *message)
{
	if( errno ) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	
	exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);

typedef int *(*sort_array)(int *array, int count);

typedef int (*find_extreme_pos)(int *array, int count);

/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int *target = malloc( count * sizeof(int) );

	if(!target)
		die("Memory error.");

	memcpy( target, numbers, count * sizeof(int) );

	for (i = 0; i < count; i++) {
		for (j = 0; j < count - 1; j++) {
			if( cmp( target[j], target[j + 1] ) > 0) {
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}	
		}
	}
	return target;
}

int find_min_pos(int *array, int count)
{
	int i = 0;
	int minPos = 0;
	int min = array[minPos];

	for (i = 0; i < count - 1; i++) {
		if (min > array[i+1] ) {
			minPos = i+1;
			min = array[i+1];
		}
	}
	return minPos;
}

int find_max_pos(int *array, int count)
{
	int i = 0;
	int maxPos = 0;
	int max = array[maxPos];

	for (i = 0; i < count - 1; i++) {
		if (max < array[i+1] ) {
			maxPos = i+1;
			max = array[i+1];
		}
	}
	return maxPos;
}

// This is selection sort implementation without 
// the linked list data structure. 
// The "removal" from unsorted is imitated via sending
// to end and giving the find_min a decremented count.
int *selection_sort(int *numbers, int count, find_extreme_pos pos)
{
	int size = count * sizeof(int);
	int *unsorted = malloc(size);
	int *sorted = malloc(size);
	int i = 0;
	int minPos = 0;
	int temp = 99999;
	int newCount = count;

	if (!sorted || !unsorted) die("Memory error");

	memcpy(unsorted, numbers, size);

	for (i = 0; i < count; i++) {
		minPos = pos(unsorted, newCount);
		sorted[i] = unsorted[minPos];
		//swap
		temp = unsorted[newCount-1];
		unsorted[newCount-1] = unsorted[minPos];
		unsorted[minPos] = temp;

		newCount = newCount - 1;
	}

	free(unsorted);
	return sorted;
}

int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b) 
{
	return b - a;
}

int strange_order(int a, int b)
{
	if( a == 0 || b == 0 ) {
		return 0;
	} else {
		return a % b;
	}
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp, find_extreme_pos extreme)
{
	int i = 0;
	int *sorted = bubble_sort(numbers, count, cmp);
	
	int *sel_sorted = selection_sort(numbers, count, extreme);


	if(!sorted || !sel_sorted)
		die("Failed to sort as requested\n");

	for(i = 0; i < count; i++) {
		printf("%d", sorted[i]);
	}
	printf("\n");

	for(i = 0; i < count; i++) {
		printf("%d", sel_sorted[i]);
	}
	printf("\n");

	
	free(sorted);
	free(sel_sorted);

//	unsigned char *data = (unsigned char *)cmp;
//	for(i = 0; i < 25; i++) {
//		printf("%02x:", data[i]);
//	}
//	printf("\n");
}

int main(int argc, char *argv[])
{
	if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

	int count = argc - 1;

	int i = 0;
	char **inputs = argv + 1;

	int *numbers = malloc( count * sizeof(int) );
	if(!numbers) die("Memory error.");

	for(i = 0; i < count; i++) {
		numbers[i] = atoi( inputs[i] );
	}

	test_sorting(numbers, count, sorted_order, find_min_pos);
	test_sorting(numbers, count, reverse_order, find_max_pos);
//	test_sorting(numbers, count, reverse_order);
//	test_sorting(numbers, count, strange_order);

	free(numbers);

	return 0;
}
