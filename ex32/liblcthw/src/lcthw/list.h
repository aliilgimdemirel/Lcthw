#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
													ListNode *V = NULL;\
for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif

struct ListNode;

typedef struct ListNode {
	struct ListNode *next;
	struct ListNode *prev;
	void *value;

} ListNode;

typedef struct List {
	int count;
	ListNode *first;
	ListNode *last;
} List;

List *List_create();

void List_destroy(List * list);

/*
 * It assumes that the list has ptr's in data. If its just an int for example,
 * it fails.
 */
void List_clear(List * list);

void List_clear_destroy(List * list);

/*
 * inserts a Node at the end of the List.
 */
void List_push(List * list, void *value);

/*
 * removes a Node from the end of the List.
 */
void *List_pop(List * list);

/*
 * inserts a node from the beginning
 */
void List_unshift(List * list, void *value);

/*
 * deletes a node from the beginning if empty returns NULL. 
 */
void *List_shift(List * list);

/*
 * Member function to handle deletion of a Node. 
 */
void *List_remove(List * list, ListNode * node);

/*
 * Returns the value at nth position in the List. If list is empty
 * it returns NULL.
 */
void *List_get_nth(List * list, int n);

/*
 * Inserts the value at the n'th position in the List. If list is empty
 * it returns NULL. 
 */
void List_insert_at_nth(List * list, int n, void *value);

/*
 * Given 2 lists, joins them into 1 and returns it.
 */
List *Join_two_lists(List* list1, List *list2);

/*
 * Splits the first List into the next 2 lists, until and excluding position 
 * split_index. e.g., a 6 node long list will be divided into 2 and 4 long Lists
 * if the index is  2.
 * When fed too big a number for index, the index will be normalized as 
 * list1->count.
 */
void Split_list_into_2_Lists_At_Position(List* list1, List *list2, List *list3, int split_index);

/*
 * frees all Nodes then, frees the List itself.
 */
