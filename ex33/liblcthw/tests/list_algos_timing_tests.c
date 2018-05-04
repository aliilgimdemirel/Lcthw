#include "minunit.h"
#include <lcthw/list_algos.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <time.h>


char *unsorted_values[] = { "XXXX", "1234", "abcd", "xjvef", "NDSS" };
char *sorted_values[] = { "1234", "NDSS",  "XXXX", "abcd", "xjvef" };

#define NUM_VALUES 5
#define REPEAT_SORT 1
#define LIST_SIZE 1
#define ORDEROFMAG 4

List *create_unsorted_words()
{
	int i = 0;
	List *words = List_create();

	for (i = 0; i < NUM_VALUES; i++) {
		List_push(words, unsorted_values[i]);
	}

	return words;
}

List *create_sorted_words()
{
	int i = 0;
	List *words = List_create();

	for (i = 0; i < NUM_VALUES; i++) {
		List_push(words, sorted_values[i]);
	}

	return words;
}

List *create_big_unsorted_List(List* list1, int how_big)
{
	List* list3 = List_create();

	for (int i = 0; i < how_big; i++) {
		list3 = Join_two_lists(list3, list1);
	}

	return list3;
}

char* test_bubble_sort_time()
{
	clock_t start_t, end_t;
	int order_of_mag_list_size = ORDEROFMAG; // BAD NAMING
	double total_time[order_of_mag_list_size-1];

	int list_size = LIST_SIZE * 1;

	List *fill_list;
	List *words = create_unsorted_words();
	printf("\nBubble Sort --- \n");
	for (int i = 0; i < order_of_mag_list_size; i++) {

		List *big_unsorted = create_big_unsorted_List(words, list_size);

		total_time[i] = 0.0;
		start_t = clock();
		 
		// BENCHMARK
		for (int j = 0; j < REPEAT_SORT; j++) {
			fill_list = List_bubble_sort(big_unsorted, (List_compare) strcmp);
		}

		end_t = clock();
		total_time[i] = ( (double)end_t - start_t ) / ( CLOCKS_PER_SEC/1000 );

		printf("Loop Count: %d, List Size: %d\n", REPEAT_SORT, list_size);
		printf("Total time taken by CPU in mSeconds: %.8f\n", total_time[i]);

		List_destroy(big_unsorted);
		list_size = list_size * 10;
				
	}

	List_destroy(words);

	return NULL;
}

char* test_merge_sort_time()
{
	clock_t start_t, end_t;
	int order_of_mag_list_size = ORDEROFMAG; // BAD NAMING
	double total_time[order_of_mag_list_size-1];

	int list_size = LIST_SIZE * 1;

	List *words = create_unsorted_words();
	printf("\nMerge Sort --- \n");
	for (int i = 0; i < order_of_mag_list_size; i++) {

		List *fill_list;
		List *big_unsorted = create_big_unsorted_List(words, list_size);

		total_time[i] = 0.0;
		start_t = clock();
		 
		// BENCHMARK
		for (int j = 0; j < REPEAT_SORT; j++) {
			fill_list = List_merge_sort(big_unsorted, (List_compare) strcmp);
		}

		end_t = clock();
		total_time[i] = ( (double)end_t - start_t ) / ( CLOCKS_PER_SEC/1000 );

		printf("Loop Count: %d, List Size: %d\n", REPEAT_SORT, list_size);
		printf("Total time taken by CPU in mSeconds: %.8f\n", total_time[i]);

		List_destroy(fill_list);
		List_destroy(big_unsorted);
		list_size = list_size * 10;
				
	}

	List_destroy(words);

	return NULL;
}

char* all_tests()
{
	mu_suite_start();

	mu_run_test(test_bubble_sort_time);

	mu_run_test(test_merge_sort_time);

	return NULL;
}



RUN_TESTS(all_tests);
