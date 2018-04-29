




#include "lcthw/list_algos.h"








int List_node_cmp(ListNode* node1, ListNode* node2)
{

	return 0;
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
