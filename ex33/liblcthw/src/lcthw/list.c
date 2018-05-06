#include "lcthw/dbg.h"
#include "lcthw/list.h"
#include <stdio.h>

List *List_create()
{
	List* list = calloc(1, sizeof(List));
	check_mem(list);
	return list;

error:
	return NULL;
}

void List_destroy(List * list)
{
	check(list != NULL, "Non existent list");

	LIST_FOREACH(list, first, next, cur) {
		if (cur->prev) {
			free(cur->prev);
		}
	}

	free(list->last);
	free(list);

error:
	return ;
}

void List_clean(List * list)
{
	check(list != NULL, "Non existent list");

	LIST_FOREACH(list, first, next, cur) {
		if (cur->prev) {
			List_pop(list);
		}
	}

	List_pop(list);

error:
	return ;
}

void List_clear(List * list)
{
	check(list != NULL, "Non existent list");

	LIST_FOREACH(list, first, next, cur) {
		cur->value = NULL;
	}

error:
	return ;
}

void List_clear_destroy(List * list)
{
	check(list != NULL, "Non existent list");

	List_clear(list);
	List_destroy(list);

error:
	return ;
}

void List_push(List * list, void *value)
{
	check(list != NULL, "Non existent list");

	ListNode *node = calloc(1, sizeof(ListNode));
	check_mem(node);

	node->value = value;

	if (list->last == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}

	list->count++;

error:
	return;
}

void *List_pop(List * list)
{
	check(list != NULL, "Non existent list");

	ListNode *node = list->last;
	return node != NULL ? List_remove(list, node) : NULL;

error:
	return NULL;
}

void List_unshift(List * list, void *value)
{
	check(list != NULL, "Non existent list");

	ListNode *node = calloc(1, sizeof(ListNode));
	check_mem(node);

	node->value = value;

	if (list->first == NULL) {
		list->first = node;
		list->last = node;
	} else {
		node->next = list->first;
		list->first->prev = node;
		list->first = node;
	}

	list->count++;	

error:
	return;
}

void *List_shift(List * list)
{
	check(list != NULL, "Non existent list");

	ListNode *node = list->first;
	return node != NULL ? List_remove(list, node) : NULL;

error:
	return NULL;
}

void *List_remove(List * list, ListNode * node)
{
	void *result = NULL;

	check(list->first && list->last, "List is empty.");
	check(node, "node can not be NULL.");
	
	// Removes Last Node in the List.
	if (node == list->first && node == list->last) {
		list->first = NULL;
		list->last = NULL;
	// Removes first Node in the List
	} else if (node == list->first) {
		list->first = node->next;
		check(list->first !=NULL,
				"Invalid list, somehow got a first that is NULL.");
		list->first->prev = NULL;
	// Removes last Node in the List
	} else if (node == list-> last)	{
		list->last = node->prev;
		check(list->last != NULL,
				"Invalid list, somehow got a next that is NULL.");
		list->last->next = NULL;
	// Removes a Node from the middle portion of the List.
	} else {
		ListNode *after = node->next;
		ListNode *before = node->prev;
		after->prev = before;
		before->next =after;
	}
	
	list->count--;
	result = node->value;
	free(node);

error:
	return result;
}

void List_insert_at_nth(List * list, int n, void *value)
{
	check(list != NULL, "Non existent list");

	ListNode *cur = list->first;
	// Check for empty List.
	check(cur != NULL, "List is empty."); 
	ListNode *node = calloc( 1, sizeof(ListNode) );
	check_mem(node);

	for (int i = 0; i < n; i++) {
		cur = cur->next;	
	}

	node->value = value;
	node->prev = cur->prev;
	node->next = cur;
	cur->prev->next = node;
	cur->prev = node;

	list->count++;


error:
	return ;
}

void *List_get_nth(List * list, int n)
{
	check(list != NULL, "Non existent list");

	ListNode *node = list->first;
	check(node != NULL, "List is empty."); 

	for (int i = 0; i < n; i ++) {
		node = node->next;	
	}

	return node->value;

error:
	return NULL;
}

void Split_list_into_2_Lists_At_Position(List* list1, List *list2, List *list3, int split_index)
{
	check(list1 != NULL, "Non existent list");
	check(list2 != NULL, "Non existent list");
	check(list3 != NULL, "Non existent list");

	// TODO	
	for (int i = 0; i < split_index; i++) {
		List_push ( list2, List_get_nth(list1, i) );
	}

	for (int i = split_index; i < list1->count; i++) {
		List_push ( list3, List_get_nth(list1, i) );
	}

error:
	return;
}

void List_concat(List* list1, List *list2)
{ 
	check(list1 != NULL, "Non existent list");
	check(list2 != NULL, "Non existent list");
 
	ListNode *cur;
	if ( list2->first ) {
		cur = list2->first;
		while ( cur != NULL) {
			List_push(list1, cur->value);
			cur = cur->next;
		}
	}
	
error:
	return ;
}

List *Join_two_lists(List* list1, List *list2)
{ 
	check(list1 != NULL, "Non existent list");
	check(list2 != NULL, "Non existent list");
 
	List *joined_list =  List_create();
	check_mem(joined_list);

	ListNode *cur;
	if ( list1->first ) {
		cur = list1->first;
		while ( cur != NULL) {
			List_push(joined_list, cur->value);
			cur = cur->next;
		}
	}

	if ( list2->first ) {
		cur = list2->first;
		while ( cur != NULL) {
			List_push(joined_list, cur->value);
			cur = cur->next;
		}
	}
	
	return joined_list;

error:
	return NULL;
}

List *List_copy(List* list1)
{
	check(list1 != NULL, "Non existent list");

	List *ret_list = List_create();
	check_mem(ret_list);

	ListNode *cur;
	if ( list1->first ) {
		cur = list1->first;
		while ( cur != NULL) {
			List_push(ret_list, cur->value);
			cur = cur->next;
		}	
	}

	return ret_list;

error:
	return NULL;
}
