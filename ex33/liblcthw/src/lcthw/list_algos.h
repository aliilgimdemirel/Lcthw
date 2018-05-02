#ifndef lcthw_List_algos_h
#define lcthw_List_algos_h

#include "lcthw/list.h"

typedef int (*List_compare)(char* a, char* b);

/*
 * A method for comparing the node values. 
 * Returns;
 * 1 if the first one is bigger,
 * 0 if they are equal,
 * -1 if the latter one is bigger.
 */
int List_node_cmp(ListNode* node1, ListNode* node2, List_compare cmp);

/*
 * A method that swps 2 nodes.
 */
void List_node_swp(ListNode* node1, ListNode* node2);

/*
 * Takes in a list, and a comparison function pointer and checks if 
 * the list is sorted or not. Returns 0 if sorted, else it returns 1.
 */
int is_sorted(List* list, List_compare cmp);


int List_bubble_sort(List* list, List_compare cmp);


/*
 * merges sorted lists 1 and 2 and returns a new list.
 */
List* merge_2_sorted_lists(List* list1, List* list2);
List* List_merge_sort(List* list, List_compare cmp);
	
void dump_list(List* list);
static void dump_node(ListNode* node, char* nodeName);
#endif
