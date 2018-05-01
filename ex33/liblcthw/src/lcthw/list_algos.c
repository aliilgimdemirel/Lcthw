




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
		dump_list(list);
		ListNode* cur = list->first;
		ListNode* next = cur->next;
	
		innerLoopCount = innerLoopCount-1;		
		for (int j = 0; j < innerLoopCount; j++) {
			int rc = List_node_cmp(cur, next, (List_compare) cmp);
			if ( rc > 0 ) {
				printf("SWAP\n");
				List_node_swp(cur, next);
			} else {
				printf("NO SWAP\n");
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

static void dump_list(List* list)
{
	LIST_FOREACH(list, first, next, cur) {
		printf("%s--->",cur->value);
	}
	printf("\n");
}

void dump_node(ListNode* node, char* nodeName)
{
	printf("%s's\n val is : %s\n next is:%p\n prev is:%p\n", nodeName,
			node->value, node->next, node->prev);
}
