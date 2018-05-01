




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
	ListNode temp;

	temp.value = node1->value;
	temp.next = node1->next;
	temp.prev = node1->prev;

	node1->value = node2->value;
	node1->next = node2->next;	
	node1->prev = node2->prev;	

	node2->value = temp.value;
	node2->next = temp.next;
	node2->prev = temp.prev;

}

// TODO loop correction for last element
int List_bubble_sort(List* list, List_compare cmp)
{

	check(list != NULL, "Non existent list");
	
	// empty list will return 0.
	if (list->count == 0) { return 0; }

	// early abort for already sorted lists.
	if (!is_sorted(list, cmp)) { return 0;}

	int loopCount = list->count;

	for (int i = 0; i < loopCount; i++) {

	ListNode* cur = list->first;
	ListNode* next = cur->next;

		for (int i = 0; i < loopCount; i++) {
			
			int rc = List_node_cmp(cur, next, (List_compare) cmp);
			if ( rc > 0 ) {
				List_node_swp(cur, next);
				// as node_swp changes cur's pos, we do not need to handle its next pos.
				next = cur->next;
			} else { 
				cur = cur->next;
				next = next->next;
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
	ListNode* next = cur->next;

	for (int i = 0; i < list->count; i++) {

		int rc = List_node_cmp(cur, next, (List_compare) cmp);
		if ( rc <= 0  ) {
			;
		} else {
			return 1;
		}	
		
		if (next != list->last) {
			next = next->next;
			cur = cur->next;
		}
	}

	return 0;
}


