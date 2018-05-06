#include "minunit.h"
#include <lcthw/list_algos.h>
#include <assert.h>
#include <string.h>
#include <math.h>

char *unsorted_values[] = { "XXXX", "1234", "abcd", "xjvef", "NDSS"};
char *sorted_values[] = { "1234", "NDSS",  "XXXX", "abcd", "xjvef" };

#define NUM_VALUES 5

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

/*
int is_sorted(List * words)
{
	LIST_FOREACH(words, first, next, cur) {
		if (cur->next && strcmp(cur->value, cur->next->value) > 0 ) {
			debug("%s %s", (char *)cur->value, (char *)cur->next->value);
			return 0;
		}
	}
	
	return 1;
}
*/

char* test_node_cmp()
{
	ListNode *node1 = calloc(1, sizeof(ListNode));
	ListNode *node2 = calloc(1, sizeof(ListNode));

	node1->value = unsorted_values[1];
	node2->value = unsorted_values[1];

	int rc = List_node_cmp(node1, node2, (List_compare) strcmp);

	mu_assert(rc == 0, "Compare failed for equal.");

	node1->value = "b";
	node2->value = "a";

	rc = List_node_cmp(node1, node2, (List_compare) strcmp);

	mu_assert(rc > 0, "Compare failed for bigger.");
	
	free(node1);
	free(node2);

	
	return NULL;
}

char* test_node_swp()
{
	List *words = create_unsorted_words();
	//printf("DEBUG1\n")	;
	List_node_swp(words->first, words->last);
	
	dump_list(words);
	
	mu_assert(!strcmp(words->first->value, unsorted_values[4]), "Node swap failed.")

	dump_list(words);
	List_clear_destroy(words);

	return NULL;
}

char *test_is_sorted()
{
	List *words = create_unsorted_words();
	mu_assert( is_sorted(words, (List_compare) strcmp) == 1, 
				"is_sorted failed for unsorted." );	
	
	List *sorted_words = create_sorted_words();
	mu_assert( is_sorted(sorted_words, (List_compare) strcmp) == 0, 
				"is_sorted failed for sorted." );	

	List_destroy(words);
	List_destroy(sorted_words);

	return NULL;
}

char* test_bubble_sort()
{
	List *words = create_unsorted_words();

	int rc;
	//should work on a list that needs sorting
	rc = List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort failed.");
	mu_assert(is_sorted(words, (List_compare) strcmp) == 0, 
		"Words are not sorted after bubble sort.");
	//should work on an already sorted list
	rc = List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort of already sorted failed.");
	mu_assert(is_sorted(words, (List_compare) strcmp) == 0, 
		"Words should be sorted if already bubble sorted.");

/*
	List_destroy(sorted_list);
	List_destroy(words);
	
	//should work on an empty list
	
	words = List_create();
	sorted_list = List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(sorted_list != NULL, "Bubble sort failed on empty list.");
	mu_assert(is_sorted(sorted_list, (List_compare) strcmp) == 0, 
		"Words should be sorted if empty.");
*/	

	List_destroy(words);

	return NULL;
}

char* test_merge_2_sorted_lists()
{
	List *words1 = create_sorted_words();
	List *words2 = create_sorted_words();
	List *words_merged = merge_2_sorted_lists(words1, words2,  (List_compare) strcmp);
	mu_assert(is_sorted(words_merged, (List_compare) strcmp) == 0,
			"merge_2_sorted_lists failed.")
	
	List *words3 = create_sorted_words();

	List* empty = List_create(); // WORKS
	List *words_merged2 = merge_2_sorted_lists(empty, words3, (List_compare) strcmp);
	mu_assert(is_sorted(words_merged2, (List_compare) strcmp) == 0,
			"merge_2_sorted_lists failed.")
	

	List_destroy(empty);
	List_destroy(words1);
	List_destroy(words2);
	List_destroy(words3);
	List_destroy(words_merged);
	List_destroy(words_merged2);

	return NULL;
}

char* test_merge_sort()
{
	List *words = create_unsorted_words();

	// should work on a list that needs sorting
	List *res1 = List_merge_sort(words, (List_compare) strcmp);
	mu_assert(is_sorted(res1, (List_compare) strcmp) == 0, "Words are not sorted after merge sort.");

//	List *res2 = List_merge_sort (res1, (List_compare) strcmp);
//	mu_assert(is_sorted(res2, (List_compare) strcmp) == 0, "Should still be sorted after merge sort.");

	List_destroy(res1);
//	List_destroy(res2);

	List_destroy(words);

	return NULL;
}

char* test_merge_sort_with_swap()
{
	List *words = create_unsorted_words();

	// should work on a list that needs sorting
	List *res1 = List_merge_sort_with_swap(words, (List_compare) strcmp);
	mu_assert(is_sorted(res1, (List_compare) strcmp) == 0, "Words are not sorted after merge sort.");

	mu_assert( strcmp( List_get_nth(res1, NUM_VALUES-1), "xjvef") == 0, "swapping merge sort failed!" )
	printf( "last value of sorted list is; %s\n", List_get_nth(res1, NUM_VALUES-1) );

//	List *res2 = List_merge_sort (res1, (List_compare) strcmp);
//	mu_assert(is_sorted(res2, (List_compare) strcmp) == 0, "Should still be sorted after merge sort.");

	List_destroy(words);
	List_destroy(res1);
//	List_destroy(res2);

	return NULL;
}

char* test_insert_sorted()
{
	List *words = create_sorted_words();

	int rc;
	rc = List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort failed.");
	mu_assert(is_sorted(words, (List_compare) strcmp) == 0, 
		"Words are not sorted after bubble sort.");

	// insert the last value
	rc = List_insert_sorted(words, List_get_nth(words, 4), (List_compare) strcmp );
	mu_assert(is_sorted(words, (List_compare) strcmp) == 0, 
		"Words should be sorted if already bubble sorted.");
	mu_assert(words->count == 6, "List count is incorrect after insert sort.");

	// insert the initial value
	rc = List_insert_sorted(words, List_get_nth(words, 0), (List_compare) strcmp );
	mu_assert(is_sorted(words, (List_compare) strcmp) == 0, 
		"Words should be sorted if already bubble sorted.");
	mu_assert(words->count == 7, "List count is incorrect after insert sort.");

	// insert an existing value with sorted insert
	rc = List_insert_sorted(words, List_get_nth(words, 3), (List_compare) strcmp );
	mu_assert(is_sorted(words, (List_compare) strcmp) == 0, 
		"Words should be sorted if already bubble sorted.");
	mu_assert(words->count == 8, "List count is incorrect after insert sort.");

	char *val = "1111";
	// insert a value that is smaller than any value in the list
	rc = List_insert_sorted(words, val, (List_compare) strcmp );
	mu_assert(is_sorted(words, (List_compare) strcmp) == 0, 
		"Words should be sorted if already bubble sorted.");
	mu_assert(words->count == 9, "List count is incorrect after insert sort.");

	val = "zzzz";
	// insert a value that is bigger than any value in the list
	rc = List_insert_sorted(words, val, (List_compare) strcmp );
	mu_assert(is_sorted(words, (List_compare) strcmp) == 0, 
		"Words should be sorted if already bubble sorted.");
	mu_assert(words->count == 10, "List count is incorrect after insert sort.");

	List_destroy(words);

	return NULL;
}

char* all_tests()
{
	mu_suite_start();

	mu_run_test(test_node_swp);
	mu_run_test(test_node_cmp);

	mu_run_test(test_is_sorted);

	mu_run_test(test_bubble_sort);
	mu_run_test(test_merge_2_sorted_lists);

	mu_run_test(test_merge_sort);

	mu_run_test(test_merge_sort_with_swap);

	mu_run_test(test_insert_sorted);

	return NULL;
}



RUN_TESTS(all_tests);
