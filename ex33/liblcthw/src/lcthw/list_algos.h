#ifndef lcthw_List_algos_h
#define lcthw_List_algos_h

#include "lcthw/list.h"

typedef int (*List_compare)(char* a, char* b);



/*
 * A method for comparing the nodes. Will return 0 if first one is bigger,
 * else it will return 1. (Thus will not swp for equal nodes.)
 */
int List_node_cmp(ListNode* node1, ListNode* node2);


/*
 * A method that swps 2 nodes.
 */
void List_node_swp(ListNode* node1, ListNode* node2);






//int List_bubble_sort(List* words, (List_compare) strcmp);
#endif
