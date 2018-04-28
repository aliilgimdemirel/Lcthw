#include "lcthw/list.h"
#include "minunit.h"
#include <assert.h>

static List *list = NULL;
static List *list1 = NULL;
static List *list2 = NULL;
static List *list3 = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test_create()
{
	list = List_create();
	mu_assert(list != NULL, "Failed to create list.");

	return NULL;
}

char *test_destroy()
{
	List_clear_destroy(list);
	//mu_assert(List_count(list) == 0, "Wrong count after destroy.");

	return NULL;
}

char *test_get_nth()
{
	List_push(list, test1);
	mu_assert(List_last(list) == test1, "Wrong last value.");
	
	List_push(list, test2);
	mu_assert(List_last(list) == test2, "Wrong last value.");
	
	List_push(list, test3);
	mu_assert(List_last(list) == test3, "Wrong last value.");
	mu_assert(List_count(list) == 3, "Wrong count on push.");

	char *value;
	value = List_get_nth(list, 0);
	mu_assert(value == test1, "Wrong get_nth value.");
	//printf("value returned is: %s\n", value);

	value = List_get_nth(list, 1);
	mu_assert(value == test2, "Wrong get_nth value.");
	//printf("value returned is: %s\n", value);

	value = List_get_nth(list, 2);
	mu_assert(value == test3, "Wrong get_nth value.");
	//printf("value returned is: %s\n", value);

	char *val = List_pop(list);
	mu_assert(val == test3, "Wrong value on pop.");
	
	val = List_pop(list);
	mu_assert(val == test2, "Wrong value on pop.");

	val = List_pop(list);
	mu_assert(val == test1, "Wrong value on pop.");

	mu_assert(List_count(list) == 0, "Wrong count after pop.");
	return NULL;
}

char *test_insert_at_nth()
{
	List_push(list, test1);
	mu_assert(List_last(list) == test1, "Wrong last value.");
	
	List_push(list, test2);
	mu_assert(List_last(list) == test2, "Wrong last value.");
	
	List_push(list, test3);
	mu_assert(List_last(list) == test3, "Wrong last value.");
	mu_assert(List_count(list) == 3, "Wrong count on push.");

	char *value;
	value = List_get_nth(list, 0);
	mu_assert(value == test1, "Wrong get_nth value.");
	//printf("value returned is: %s\n", value);

	List_insert_at_nth(list, 1, value);
	mu_assert(value == test1, "Wrong get_nth value.");

	value = List_get_nth(list, 1);
	mu_assert(value == test1, "Wrong get_nth value.");
	//printf("value returned is: %s\n", value);

	value = List_get_nth(list, 2);
	mu_assert(value == test2, "Wrong get_nth value.");
	//printf("value returned is: %s\n", value);

	value = List_get_nth(list, 3);
	mu_assert(value == test3, "Wrong get_nth value.");
	//printf("value returned is: %s\n", value);

	char *val = List_pop(list);
	mu_assert(val == test3, "Wrong value on pop.");
	
	val = List_pop(list);
	mu_assert(val == test2, "Wrong value on pop.");

	val = List_pop(list);
	mu_assert(val == test1, "Wrong value on pop.");

	val = List_pop(list);
	mu_assert(val == test1, "Wrong value on pop.");

	mu_assert(List_count(list) == 0, "Wrong count after pop.");

	return NULL;
}

// A self standing test where you create 3 lists, and at the end you free them
char *test_join_two_Lists()
{
	// Create 3 Lists, 2 to be joind into the 3rd.	
	list1 = List_create();
	mu_assert(list1 != NULL, "Failed to create list.");
	list2 = List_create();
	mu_assert(list2 != NULL, "Failed to create list.");
	list3 = List_create();
	mu_assert(list3 != NULL, "Failed to create list.");
	
	// Populate 1st List
	List_push(list1, test1);
	mu_assert(List_last(list1) == test1, "Wrong last value.");
	List_push(list1, test1);
	mu_assert(List_last(list1) == test1, "Wrong last value.");

	// Pupulate 2nd List
	List_push(list2, test2);
	mu_assert(List_last(list2) == test2, "Wrong last value.");
	List_push(list2, test2);
	mu_assert(List_last(list2) == test2, "Wrong last value.");

	// Join The Lists.
	list3 =	Join_two_lists(list1, list2);

	// Check entries.
	char *value = List_get_nth(list3, 0);
	mu_assert(value == test1, "Wrong get_nth value.");
	
	value = List_get_nth(list3, 1);
	mu_assert(value == test1, "Wrong get_nth value.");
	
	value = List_get_nth(list3, 2);
	mu_assert(value == test2, "Wrong get_nth value.");
	
	value = List_get_nth(list3, 3);
	mu_assert(value == test2, "Wrong get_nth value.");

	// Check List count
	mu_assert(List_count(list3) == 4, "Wrong count on push.");

	// Check values with popping	
	char *val = List_pop(list3);
	mu_assert(val == test2, "Wrong value on pop.");
	val = List_pop(list3);
	mu_assert(val == test2, "Wrong value on pop.");
	val = List_pop(list3);
	mu_assert(val == test1, "Wrong value on pop.");
	val = List_pop(list3);
	mu_assert(val == test1, "Wrong value on pop.");

	val = List_get_nth(list1,0);	
	mu_assert(val == test1, "Wrong value on pop.");

	mu_assert(List_count(list3) == 0, "Wrong count on pop.");
	
	List_destroy(list1);
	List_destroy(list2);
	List_destroy(list3);

	return NULL;
}

// A self standing test where you create 3 lists, and at the end you free them
char *test_split_into_two_Lists()
{
	// Create 3 Lists, 1 to be split into the 2.	
	list1 = List_create();
	mu_assert(list1 != NULL, "Failed to create list.");
	list2 = List_create();
	mu_assert(list2 != NULL, "Failed to create list.");
	list3 = List_create();
	mu_assert(list3 != NULL, "Failed to create list.");
	
	// Populate 1st List
	List_push(list1, test1);
	mu_assert(List_last(list1) == test1, "Wrong last value.");
	List_push(list1, test1);
	mu_assert(List_last(list1) == test1, "Wrong last value.");
	List_push(list1, test2);
	mu_assert(List_last(list1) == test2, "Wrong last value.");
	List_push(list1, test2);
	mu_assert(List_last(list1) == test2, "Wrong last value.");
	List_push(list1, test3);
	mu_assert(List_last(list1) == test3, "Wrong last value.");
	List_push(list1, test3);
	mu_assert(List_last(list1) == test3, "Wrong last value.");

	// Split The List.
	int split_Pos = 2;
	Split_list_into_2_Lists_At_Position(list1, list2, list3, split_Pos);

	// Check entries.
	char *value = List_get_nth(list1, 2);
	char *value2 = List_get_nth(list3, 0);
	mu_assert(value == value2, "Wrong split_position.");
	
	// Check List count
	mu_assert(List_count(list2) == 2, "Wrong count on push.");

	// Clean after self	
	List_destroy(list1);
	List_destroy(list2);
	List_destroy(list3);

	return NULL;
}



char *test_push_pop()
{
	List_push(list, test1);
	mu_assert(List_last(list) == test1, "Wrong last value.");
	
	List_push(list, test2);
	mu_assert(List_last(list) == test2, "Wrong last value.");
	
	List_push(list, test3);
	mu_assert(List_last(list) == test3, "Wrong last value.");
	mu_assert(List_count(list) == 3, "Wrong count on push.");

	char *val = List_pop(list);
	mu_assert(val == test3, "Wrong value on pop.");
	
	val = List_pop(list);
	mu_assert(val == test2, "Wrong value on pop.");

	val = List_pop(list);
	mu_assert(val == test1, "Wrong value on pop.");

	mu_assert(List_count(list) == 0, "Wrong count after pop.");

	return NULL;
}

char *test_unshift()
{
	List_unshift(list, test1);
	mu_assert(List_first(list) == test1, "Wrong first value.");

	List_unshift(list, test2);
	mu_assert(List_first(list) == test2, "Wrong first value.");
	
	List_unshift(list, test3);
	mu_assert(List_first(list) == test3, "Wrong first value.");

	mu_assert(List_count(list) == 3,"Wrong count on unshift.");

	return NULL;
}

char *test_remove()
{
	char *val = List_remove(list, list->first->next);
	mu_assert(val == test2, "Wrong removed element.");
	mu_assert(List_count(list) == 2, "Wrong count after remove.");
	mu_assert(List_first(list) == test3, "Wrong first after remove.");
	mu_assert(List_last(list) == test1, "Wrong last after remove.");

	return NULL;
}

char *test_shift()
{
	mu_assert(List_count(list) != 0, "Wrong count before shift.");

	char *val = List_shift(list);
	mu_assert(val == test3, "Wrong value on shift");

	val = List_shift(list);
	mu_assert(val == test1, "Wrong value on shift");
	mu_assert(List_count(list) == 0, "Wrong count before shift.");

	return NULL;
}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_push_pop);
	
	mu_run_test(test_unshift);
	mu_run_test(test_remove);
	mu_run_test(test_shift);

	mu_run_test(test_get_nth);
	mu_run_test(test_insert_at_nth);

	mu_run_test(test_join_two_Lists);
	
	mu_run_test(test_split_into_two_Lists);

	mu_run_test(test_destroy);

	return NULL;
}

RUN_TESTS(all_tests);
