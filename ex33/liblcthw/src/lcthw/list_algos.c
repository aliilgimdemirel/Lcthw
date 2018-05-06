#include "lcthw/list_algos.h"
#include "lcthw/dbg.h"
#include <string.h>

int List_node_cmp(ListNode* node1, ListNode* node2, List_compare cmp)
{
	check(node1 != NULL, "Non existent node");
	check(node2 != NULL, "Non existent node");

	int rc = cmp(node1->value, node2->value);
	
	if ( rc > 0 ) {
		return 1;
	} else if (rc == 0) {
		return 0;
	} else {
		return -1;
	}

error:
	return -1; // this is a bug
}

void List_node_swp(ListNode* node1, ListNode* node2)
{
	check(node1 != NULL, "Non existent node");
	check(node2 != NULL, "Non existent node");

	void* temp;

	temp = node1->value;
	node1->value = node2->value;
	node2->value = temp;

error:
	return;
}

int is_sorted(List* list, List_compare cmp)
{
	check(list != NULL, "Non existent list");

	if (!list->first) { // returns 0 for empty list.
		return 0;
	}

	if (!list->first->next) { // returns 0 for single element list.
		return 0;
	}

	ListNode* cur = list->first;
	ListNode* next = cur->next;
	for (int i = 0; i < ((list->count) - 1); i++) {

		int rc = List_node_cmp(cur, next, (List_compare) cmp);
		if ( rc > 0  ) {
			return 1;
		}
		
		if (next != list->last) {
			next = next->next;
			cur = cur->next;
		}
	}

	return 0;

error:
	return 1;
}

int List_bubble_sort(List* list, List_compare cmp)
{
	check(list != NULL, "Non existent list");
	
	// empty lists are sorted.
	if (list->first == NULL) { return 0; }
	// single element list is sorted.
	if (list->first->next == NULL) { return 0; }

	// early abort for already sorted ret_lists.
	if (!is_sorted(list, (List_compare) cmp)) { return 0;}

	int loopCount = list->count;
	int innerLoopCount = loopCount;
	int sorted = 0;

	//for (int i = 0; i < loopCount; i++) 
	while (sorted == 0) {
		sorted = 1;
		ListNode* cur = list->first;
		ListNode* next = cur->next;
	
		innerLoopCount = innerLoopCount-1;		
		for (int j = 0; j < innerLoopCount; j++) {
			int rc = List_node_cmp(cur, next, (List_compare) cmp);
			if ( rc > 0 ) {
				List_node_swp(cur, next);
				sorted = 0;
			} 

			if (next != list->last) {
				next = next->next;
				cur = cur->next;
			}
		}
	}

	return 0;

error:
	return 1;
}

List* merge_2_sorted_lists(List* list1, List* list2, List_compare cmp)
{
	check(list1 != NULL, "Non existent list");
	check(list2 != NULL, "Non existent list");

	List *ret_list;
	
	ListNode* cur1;
	ListNode* cur2;

	// early termination part.
	if (list1->first) {
		cur1 = list1->first;
	} else {
		if (list2->first) { 
			ret_list = List_copy(list2);
			return ret_list;
		} else { // Both exist but both are empty
			ret_list = List_create();
			return ret_list;
		}
	}
	
	if (list2->first) {
		cur2 = list2->first;
	} else {
		if (list1->first) { // this if block is redundant but left for better understanding 
			ret_list = List_copy(list1);
			return ret_list;
		}
	}

	List* mid_list = List_create();

	while (cur1 != NULL && cur2 != NULL) {
	
		if ( List_node_cmp(cur1, cur2, cmp) > 0 ) {
			List_push(mid_list, List_shift(list2));
			cur2 = list2->first;
		} else {
			List_push(mid_list, List_shift(list1));
			cur1 = list1->first;
		}
	}
	
	if (cur1 == NULL) {
		ret_list = Join_two_lists(mid_list, list2);
	} else {
		ret_list = Join_two_lists(mid_list, list1);
	}

	List_destroy(mid_list);

	return ret_list;

error:
	return NULL;
}

List *List_merge(List *left, List* right, List_compare cmp)
{
	List *result = List_create();
	void * val = NULL;

	while ( List_count(left) > 0  || List_count(right) > 0 ) {
		if ( List_count(left) > 0  && List_count(right) > 0 ) {
			if ( cmp(List_first(left), List_first(right)) <= 0  ) {
				val = List_shift(left);
			} else {
				val = List_shift(right);
			}
				
			List_push(result, val);
		} else if (List_count(left) > 0 ) {
			val = List_shift(left);
			List_push(result, val);
		} else if (List_count(right) > 0 ) {
			val = List_shift(right);
			List_push(result, val);
		}
	}

	return result;
}

List* List_merge_sort_book(List* list, List_compare cmp)
{
	if (List_count(list) <= 1) {
		return list;
	}
	
	List *left = List_create();
	List *right = List_create();
	int middle = List_count(list) / 2;
	
	LIST_FOREACH(list, first, next, cur) {
		if (middle > 0){
			List_push(left, cur->value);
		} else {
			List_push(right, cur->value);
		}

		middle--;
	}

	List *sort_left = List_merge_sort_book(left, cmp);
	List *sort_right = List_merge_sort_book(right, cmp);

	if (sort_left != left) {
		List_destroy(left);
	} 
	if (sort_right != right) {
		List_destroy(right);
	} 

	return List_merge(sort_left, sort_right, cmp);
}

List* List_merge_sort(List* list, List_compare cmp)
{
	check(list != NULL, "Non existent list");
	List* ret_list;
	
	int num_of_elements = list->count;
	List **all_lists = calloc(num_of_elements, sizeof(List*));
	check_mem(all_lists != NULL);

	ListNode* cur = list->first;

	for (int i = 0; i < num_of_elements; i ++) {
		all_lists[i] = List_create();
		List_push(all_lists[i], cur->value);
		cur = cur->next;
	}

	int counterValue = num_of_elements;	
	counterValue = ( (counterValue % 2 == 0) ? counterValue/2: counterValue/2 + 1 ) ;

	List **outputLists = malloc (counterValue *  sizeof(List*));
	check_mem(outputLists);
	
//	for (int i = 0; i < counterValue; i ++) {
//		outputLists[i] = List_create();
//	}

	while (1) {

		for (int i = 0; i < counterValue; i++) {
			// all_lists[i*2+1] does not exist 
			if ( num_of_elements == (i * 2) + 1 ) {
				List * empty_list = List_create(); 
				outputLists[i] = merge_2_sorted_lists(all_lists[i*2], empty_list, cmp);
				List_destroy(empty_list);
			} else {
				outputLists[i] = merge_2_sorted_lists(all_lists[i*2], all_lists[i*2+1], cmp);
			}
		}

		// TRICKY!!!!
		// copy lists then kill old
		for (int i = 0; i < counterValue; i++) {
			List_destroy(all_lists[i]);
			all_lists[i] = List_copy(outputLists[i]);
			List_destroy(outputLists[i]);
		}
		// TRICKY!!!!
		// clean after self
		for (int i = counterValue; i < num_of_elements; i++) {
			List_destroy(all_lists[i]);
		}

		// update counter Value OR exit while loop
		if (counterValue != 1) {
			counterValue = ( (counterValue % 2 == 0) ? \
							counterValue/2 : counterValue/2 + 1 ) ;
			num_of_elements = ( (num_of_elements % 2 == 0) ? \
							num_of_elements/2 : num_of_elements/2 + 1 ) ;
		} else {
			break;
		}
	}

	ret_list = List_copy(all_lists[0]);
	
	List_destroy(all_lists[0]);
	free(all_lists);
	free(outputLists);

	return ret_list; 

error:
	return NULL;
}

List* List_merge_sort_with_swap(List* list, List_compare cmp)
{
	check(list != NULL, "Non existent list");
	List* ret_list;
	
	int num_of_elements = list->count;
	List **all_lists = calloc(num_of_elements, sizeof(List*));
	check_mem(all_lists != NULL);

	ListNode* cur = list->first;

	for (int i = 0; i < num_of_elements; i ++) {
		all_lists[i] = List_create();
		List_push(all_lists[i], cur->value);
		cur = cur->next;
	}

	int counterValue = num_of_elements;	
	counterValue = ( (counterValue % 2 == 0) ? counterValue/2: counterValue/2 + 1 ) ;

	List **outputLists = calloc (counterValue, sizeof(List*));
	check_mem(outputLists);
	
//	for (int i = 0; i < counterValue; i ++) {
//		outputLists[i] = List_create();
//	}
	
	int swap = 0;

	while (1) {

		if (swap == 0) {
			for (int i = 0; i < counterValue; i++) {
				// all_lists[i*2+1] does not exist 
				if ( num_of_elements == (i * 2) + 1 ) {
					List * empty_list = List_create(); 
					outputLists[i] = merge_2_sorted_lists(all_lists[i*2], empty_list, cmp);
					List_destroy(empty_list);
				} else {
					outputLists[i] = merge_2_sorted_lists(all_lists[i*2], all_lists[i*2+1], cmp);
				}
			}
			for (int i = 0; i < num_of_elements; i++) {
				List_destroy(all_lists[i]);
			}
			swap = 1;
		} else {
			for (int i = 0; i < counterValue; i++) {
				if ( num_of_elements == (i * 2) + 1 ) {
					List * empty_list = List_create(); 
					all_lists[i] = merge_2_sorted_lists(outputLists[i*2], empty_list, cmp);
					List_destroy(empty_list);
				} else {
					all_lists[i] = merge_2_sorted_lists(outputLists[i*2], outputLists[i*2+1], cmp);
				}
			}
			for (int i = 0; i < num_of_elements; i++) {
				List_destroy(outputLists[i]);
			}
			swap = 0;
		}
		// END OF MERGE
		// LETS KILL space!
		// SWAP HAS CHANGED!

		// update counter Value OR exit while loop
		if (counterValue != 1) {
			counterValue = ( (counterValue % 2 == 0) ? \
							counterValue/2 : counterValue/2 + 1 ) ;
			num_of_elements = ( (num_of_elements % 2 == 0) ? \
							num_of_elements/2 : num_of_elements/2 + 1 ) ;

		} else {
			break;
		}
	}

	if (swap == 0) {
		//List_destroy(outputLists[0]);
		ret_list = List_copy(all_lists[0]);
		List_destroy(all_lists[0]);
	} else {
		//List_destroy(all_lists[0]);
		ret_list = List_copy(outputLists[0]);
		List_destroy(outputLists[0]);
	}
	
	free(all_lists);
	free(outputLists);

	return ret_list; 

error:
	return NULL;
}

int List_bubble_sort_book(List* list, List_compare cmp)
{
	check(list != NULL, "Non existent list");

	if (List_count(list) <= 1) {
		return 0; // already sorted
	}

	int sorted = 1;

	do {
		sorted = 1;
		LIST_FOREACH(list, first, next, cur) {
			if (cur->next) {
				if ( cmp(cur->value, cur->next->value) > 0 ) {
					List_node_swp(cur, cur->next);
					sorted = 0;
				}
			}
		}
	} while (!sorted);
	
	return 0;

error:
	return 1;
}

int List_insert_sorted(List* list, void* value, List_compare cmp)
{
	check(list != NULL, "Non existent list");

	// check for value in the list, ? cmp(cur->value, value)
	// when the comparison returns equal or bigger

	ListNode *cur;
	if ( list->first ) {
		cur = list->first;
		//printf("DEBUGinside\n");
		int i;
		for ( i = 0; i < list->count; i++) {
			if ( cmp(value, cur->value) > 0  ) {
				cur = cur->next;
			} else {
				break;
			}
		}
		List_insert_at_nth(list, i, value);
	} else { // case for empty list
		List_push(list, value);
	}

	return 0;

error:
	return 1;
}

void dump_list(List* list)
{
	LIST_FOREACH(list, first, next, cur) {
		printf("%s--->", (char*)cur->value);
	}
	printf("\n");
}
