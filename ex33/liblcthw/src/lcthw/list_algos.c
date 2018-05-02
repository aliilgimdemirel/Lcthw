




#include "lcthw/list_algos.h"
#include "lcthw/dbg.h"
#include <string.h>







int List_node_cmp(ListNode* node1, ListNode* node2, List_compare cmp)
{
	int rc = cmp(node1->value, node2->value);
	
	if ( rc > 0 ) {
		return 1;
	} else if (rc == 0) {
		return 0;
	} else {
		return -1;
	}
}



void List_node_swp(ListNode* node1, ListNode* node2)
{
	ListNode* temp;

	temp->value = node1->value;

	node1->value = node2->value;

	node2->value = temp->value;
}

int List_bubble_sort(List* list, List_compare cmp)
{

	//check(list != NULL, "Non existent list");
	
	// empty list will return 0.
	if (list->count == 0) { return 0; }

	// early abort for already sorted lists.
	if (!is_sorted(list, (List_compare) cmp)) { return 0;}

	int loopCount = list->count;
	int innerLoopCount = loopCount;

	for (int i = 0; i < loopCount; i++) {
		ListNode* cur = list->first;
		ListNode* next = cur->next;
	
		innerLoopCount = innerLoopCount-1;		
		for (int j = 0; j < innerLoopCount; j++) {
			int rc = List_node_cmp(cur, next, (List_compare) cmp);
			if ( rc > 0 ) {
				List_node_swp(cur, next);
			} else {
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

int is_sorted(List* list, List_compare cmp)
{
	ListNode* cur = list->first;
	if (cur == NULL) {
		return 0;
	}

	ListNode* next = cur->next;

	for (int i = 0; i < list->count-1; i++) {

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
}

List* merge_2_sorted_lists(List* list1, List* list2)
{
	ListNode* cur1 = list1->first;
	ListNode* cur2 = list2->first;

	List* ret_list;
	List* mid_list = List_create();

	while (cur1 != NULL && cur2 != NULL) {
	
		if ( List_node_cmp(cur1, cur2, (List_compare) strcmp) > 0 ) {
			List_push(mid_list, List_shift(list2));
			cur2 = list2->first;
		} else {
			List_push(mid_list, List_shift(list1));
			cur1 = list1->first;
		}
	}
	
	printf("DEBUG1\n");
	if (cur1 == NULL) {
		ret_list = Join_two_lists(mid_list, list2);
	} else {
		ret_list = Join_two_lists(mid_list, list1);
	}

	return ret_list;

}




List* List_merge_sort(List* list, List_compare cmp)
{
	List* ret_list = List_create();
	
	int num_of_elements = list->count;
	List **all_lists = calloc(num_of_elements, sizeof(List*));
	ListNode* cur = list->first;

	for (int i = 0; i < num_of_elements; i ++) {
		all_lists[i] = List_create();
		List_push(all_lists[i], cur->value);

		cur = cur->next;
	}

	int counterValue = num_of_elements;	

	List **outputLists = calloc (counterValue, sizeof(List*));

// 17e > 9m
// 9e > 5m
// 5e > 3m
// 3e > 2m
// 2e > 1m LAST ONE

	counterValue = ( (counterValue % 2 == 0) ? counterValue/2: counterValue/2 + 1 ) ;

	printf("---\n At the begining \nnumOfElems is: %d\nCounterValue is:%d\n",
					 num_of_elements ,counterValue);

	while (1) {

		for (int i = 0; i < counterValue; i++) {
			if ( num_of_elements == (i * 2) + 1 ) {
				printf("will merge with empty\n") ;
				// all_lists[i*2+1] does not exist 
		//		List * empty_list = List_create(); 
		//		outputLists[i] = merge_2_sorted_lists(all_lists[i*2], empty_list);
		//		List_destroy(empty_list);
			} else {
				printf("will merge proper\n") ;
		//		outputLists[i] = merge_2_sorted_lists(all_lists[i*2], all_lists[i*2+1]);
			}
		
		}

		// copy lists then kill old
		for (int i = 0; i < counterValue; i++) {
			//List_copy(all_lists[i], outputLists[i]);
			//List_destroy(outputLists[i]);
			printf("%d", i);
		}
			printf("\n");

		
		//free(outputLists);

		// update counter Value OR exit while loop
		if (counterValue != 1) {
			counterValue = ( (counterValue % 2 == 0) ? \
							counterValue/2 : counterValue/2 + 1 ) ;
			num_of_elements = ( (num_of_elements % 2 == 0) ? \
							num_of_elements/2 : num_of_elements/2 + 1 ) ;
		} else {
			printf("Gonna break cuz ctrVal is: %d\n",counterValue);
			break;
		}

		//List **outputLists = calloc (counterValue, sizeof(List*));

	}

	// all_lists[0] should have the result.


	return ret_list;
}









void dump_list(List* list)
{
	LIST_FOREACH(list, first, next, cur) {
		printf("%s--->",cur->value);
	}
	printf("\n");
}

static void dump_node(ListNode* node, char* nodeName)
{
	printf("%s's\n val is : %s\n next is:%p\n prev is:%p\n", nodeName,
			node->value, node->next, node->prev);
}
