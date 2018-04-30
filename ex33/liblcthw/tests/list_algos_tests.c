#include "minunit.h"
#include <lcthw/list_algos.h>
#include <assert.h>
#include <string.h>


char *values[] = { "XXXX", "1234", "abcd", "xjvef", "NDSS", };

#define NUM_VALUES 5

List *create_words()
{
	int i = 0;
	List *words = List_create();

	for (i = 0; i < NUM_VALUES; i++) {
		List_push(words, values[i]);
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


char* test_bubble_sort()
{
	List *words = create_words();

	//should work on a list that needs sorting
	int rc = List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort failed.");
	mu_assert(is_sorted(words), 
		"Words are not sorted after buble sort.");

	//should work on an already sorted list
	rc = List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort of alreader sorted failed.");
	mu_assert(is_sorted(words), 
		"Words should be sorted if already bubble sorted.");

	List_destroy(words);
	
	//should work on an empty list
	words = List_create(words);
	rc = List_bubble_sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort failed on empty list.");
	mu_assert(is_sorted(words), 
		"Words should be sorted if empty.");

	List_destroy(words);

}



char* test_merge_sort()
{
	List *words = create_words();

	// should work on a list that needs sorting
	List *res1 = List_merge_sort(words, (List_compare) strcmp);
	mu_assert(is_sorted(res1), "Words are not sorted after merge sort.");

	List *res2 = List_merge_sort (res, (List_compare) strcmp);
	mu_assert(is_sorted(res2), 
		"Should still be sorted after merge sort.");

	List_destroy(res1);
	List_destroy(res2);

	List_destroy(words);

	return NULL;
}

*/

char* test_node_cmp()
{
	ListNode *node1 = calloc(1, sizeof(ListNode));
	ListNode *node2 = calloc(1, sizeof(ListNode));

	node1->value = values[2];
	node2->value = values[2];

	int rc = List_node_cmp(node1, node2, (List_compare) strcmp);

	mu_assert(rc == 0, "Compare failed.");
	
	free(node1);
	free(node2);

	
	return NULL;
}

char* test_node_swp()
{
	printf("DEBUG SWP\n");	

	List *words = create_words();

	printf("list->first is: %s\n", (char*)words->first->value);	
		
	List_node_swp(words->first, words->last);

	printf("list->first is: %s\n", (char*)words->first->value);	

	mu_assert(!strcmp(words->first->value, values[4]), "Node swap failed.")



	return NULL;
}


char* all_tests()
{
	mu_suite_start();

	mu_run_test(test_node_swp);
	mu_run_test(test_node_cmp);

	//mu_run_test(test_bubble_sort);
	//mu_run_test(test_merge_sort);

	return NULL;
}



RUN_TESTS(all_tests);
