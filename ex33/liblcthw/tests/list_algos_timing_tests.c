#include "minunit.h"
#include <lcthw/list_algos.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <time.h>

char *unsorted_values[] = { "XXXX", "1234", "abcd", "xjvef", "NDSS" };
char *sorted_values[] = { "1234", "NDSS",  "XXXX", "abcd", "xjvef" };

#define NUM_VALUES 5
#define REPEAT_SORT 5

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
	clock_t start_t, end_t, total_t;

	List *words = create_unsorted_words();
	List *big_unsorted = create_big_unsorted_List(words, 50);
	List *fill_list;

	int rc = 0;
	
	start_t = clock();
	for (int i = 0; i < REPEAT_SORT; i++) {
		fill_list = List_bubble_sort(big_unsorted, (List_compare) strcmp);
	}

	end_t = clock();

	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

	List_destroy(words);
	List_destroy(big_unsorted);

	return NULL;
}

char* test_merge_sort_time()
{
	List *words = create_unsorted_words();

	// should work on a list that needs sorting
	List *res1 = List_merge_sort(words, (List_compare) strcmp);
//	mu_assert(is_sorted(res1, (List_compare) strcmp) == 0, "Words are not sorted after merge sort.");

//	List *res2 = List_merge_sort (res1, (List_compare) strcmp);
//	mu_assert(is_sorted(res2, (List_compare) strcmp) == 0, "Should still be sorted after merge sort.");

	List_destroy(res1);
//	List_destroy(res2);

	List_destroy(words);

	return NULL;
}

char* all_tests()
{
	mu_suite_start();

	mu_run_test(test_bubble_sort_time);

	//mu_run_test(test_merge_sort_time);

	return NULL;
}



RUN_TESTS(all_tests);
