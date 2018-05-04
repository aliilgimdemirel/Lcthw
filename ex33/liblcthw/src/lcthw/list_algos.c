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

	ListNode* temp;

	temp->value = node1->value;
	node1->value = node2->value;
	node2->value = temp->value;

error:
	return;
}

int is_sorted(List* list, List_compare cmp)
{
	check(list != NULL, "Non existent list");

	ListNode* cur = list->first;
	if (cur == NULL) { // returns 0 for empty list.
		return 0;
	}

	ListNode* next = cur->next;
	if (next == NULL) { // returns 0 for single element list.
		return 0;
	}

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

List* List_bubble_sort(List* list, List_compare cmp)
{
	check(list != NULL, "Non existent list");
	
	List* ret_list = List_create();
	List_copy(ret_list, list);
	
	// empty lists are sorted.
	if (list->first == NULL) { return ret_list; }
	// single element list is sorted.
	if (list->first->next == NULL) { return ret_list; }

	// early abort for already sorted ret_lists.
	if (!is_sorted(ret_list, (List_compare) cmp)) { return ret_list;}

	int loopCount = ret_list->count;
	int innerLoopCount = loopCount;
	int sorted = 0;

	//for (int i = 0; i < loopCount; i++) 
	while (sorted == 0) {
		sorted = 1;
		ListNode* cur = ret_list->first;
		ListNode* next = cur->next;
	
		innerLoopCount = innerLoopCount-1;		
		for (int j = 0; j < innerLoopCount; j++) {
			int rc = List_node_cmp(cur, next, (List_compare) cmp);
			if ( rc > 0 ) {
				List_node_swp(cur, next);
				sorted = 0;
			} 

			if (next != ret_list->last) {
				next = next->next;
				cur = cur->next;
			}
		}
	}

	return ret_list;

error:
	return NULL;
}

List* merge_2_sorted_lists(List* list1, List* list2)
{
	check(list1 != NULL, "Non existent list");
	check(list2 != NULL, "Non existent list");

	List* ret_list;
	List* mid_list = List_create();
	
	ListNode* cur1;
	ListNode* cur2;

	// early termination part.
	if (list1->first) {
		cur1 = list1->first;
	} else {
		if (list2->first) { 
			return ret_list = Join_two_lists(mid_list, list2);
		} else { 
			return ret_list = List_create();
		}
	}
	
	if (list2->first) {
		cur2 = list2->first;
	} else {
		if (list1->first) { // this if block is redundant but left for better understanding 
			ret_list = Join_two_lists(mid_list, list1);
		}
	}

	while (cur1 != NULL && cur2 != NULL) {
	
		if ( List_node_cmp(cur1, cur2, (List_compare) strcmp) > 0 ) {
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

List* List_merge_sort(List* list, List_compare cmp)
{
	check(list != NULL, "Non existent list");
	List* ret_list = List_create();
	
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
	
	for (int i = 0; i < counterValue; i ++) {
		outputLists[i] = List_create();
	}

	while (1) {

		for (int i = 0; i < counterValue; i++) {
			// all_lists[i*2+1] does not exist 
			if ( num_of_elements == (i * 2) + 1 ) {
				List * empty_list = List_create(); 
				outputLists[i] = merge_2_sorted_lists(all_lists[i*2], empty_list);
				List_destroy(empty_list);
			} else {
				outputLists[i] = merge_2_sorted_lists(all_lists[i*2], all_lists[i*2+1]);
			}
		}

		// TRICKY!!!!
		// copy lists then kill old
		for (int i = 0; i < counterValue; i++) {
			List_destroy(all_lists[i]);
			all_lists[i] = List_create();
			List_copy(all_lists[i], outputLists[i]);
			List_destroy(outputLists[i]);
		}
		// TRICKY!!!!

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

	return ret_list = all_lists[0];

error:
	return NULL;
}

void dump_list(List* list)
{
	LIST_FOREACH(list, first, next, cur) {
		printf("%s--->",cur->value);
	}
	printf("\n");
}
