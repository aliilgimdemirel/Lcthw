#include "lcthw/dbg.h"
#include "lcthw/list.h"
#include <stdio.h>
#include <assert.h>

List *List_create()
{
	return calloc(1, sizeof(List));
}

void List_destroy(List * list)
{
	assert(list != NULL); 

	LIST_FOREACH(list, first, next, cur) {
		if (cur->prev) {
			free(cur->prev);
		}
	}

	free(list->last);
	free(list);
}

void List_clear(List * list)
{
	assert(list != NULL); 

	LIST_FOREACH(list, first, next, cur) {
		cur->value = NULL;
	}
}

void List_clear_destroy(List * list)
{
	assert(list != NULL); 

	List_clear(list);
//	List_destroy(list);
/*
	LIST_FOREACH(list, first, next, cur) {
		printf("DEBUG1\n");
		free(cur->value);
		printf("DEBUG2\n");
		if (cur->prev) {
			free(cur->prev);
		}
	}

	free(list->last);
		printf("DEBUG3\n");
	free(list);
		printf("DEBUG4\n");
*/
}

void List_push(List * list, void *value)
{
	assert(list != NULL); 

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
	assert(list != NULL); 

	ListNode *node = list->last;
	return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List * list, void *value)
{
	assert(list != NULL); 

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
	assert(list != NULL); 

	ListNode *node = list->first;
	return node != NULL ? List_remove(list, node) : NULL;
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
	assert(list != NULL); 

	ListNode *cur = list->first;
	// Check for empty List.
	check(cur != NULL, "List is empty."); 
	ListNode *node = calloc(1,sizeof(ListNode));
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
	assert(list != NULL); 

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
	assert(list1 != NULL); 
	assert(list2 != NULL); 
	assert(list3 != NULL); 
	
	for (int i = 0; i < split_index; i++) {
		List_push ( list2, List_get_nth(list1, i) );
	}

	for (int i = split_index; i < list1->count; i++) {
		List_push ( list3, List_get_nth(list1, i) );
	}

}

List *Join_two_lists(List* list1, List *list2)
{ 
	assert(list1 != NULL); 
	assert(list2 != NULL);
 
	List *joined_list =  malloc(sizeof(List));

	for (int i = 0; i < list1->count; i++) {
		List_push ( joined_list, List_get_nth(list1, i) );
	}

	for (int i = 0; i < list2->count; i++) {
		List_push ( joined_list, List_get_nth(list2, i) );
	}
	
	return joined_list;
}
