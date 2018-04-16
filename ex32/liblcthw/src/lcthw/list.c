#include "lcthw/dbg.h"
#include "lcthw/list.h"
#include "stdio.h"

List *List_create()
{
	return calloc(1, sizeof(List));
}

void List_destroy(List * list)
{
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
	LIST_FOREACH(list, first, next, cur) {
		//printf("cur value is: %s\n", cur->value);
		cur->value = NULL;
		//printf("cur value is: %s\n", cur->value);
	}
}

List *Merge_two_lists(List* list1, List *list2)
{
	List *merged_list =  calloc(1, sizeof(List));

	list1->last->next = list2->first;
	list2->first->prev = list1->last;

	merged_list = list1;
	merged_list->last = list2->last;
	merged_list->count = list1->count + list2->count;
	
	return merged_list;
}

void List_clear_destroy(List * list)
{
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

void List_insert_at_nth(List * list, int n, void *value)
{
	ListNode *cur = list->first;
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
	ListNode *node = list->first;

	for (int i = 0; i < n; i ++) {
		node = node->next;	
	}

	return node->value;

error:
	return NULL;
}

void List_push(List * list, void *value)
{
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
	ListNode *node = list->last;
	return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List * list, void *value)
{
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
	ListNode *node = list->first;
	return node != NULL ? List_remove(list, node) : NULL;
}

void *List_remove(List * list, ListNode * node)
{
	void *result = NULL;

	check(list->first && list->last, "List is empty.");
	check(node, "node can not be NULL.");

	
	// Single Element
	if (node == list->first && node == list->last) {
		list->first = NULL;
		list->last = NULL;
	// Single Element
	} else if (node == list->first) {
		list->first = node->next;
		check(list->first !=NULL,
				"Invalid list, somehow got a first that is NULL.");
		list->first->prev = NULL;
	} else if (node == list-> last)	{
		list->last = node->prev;
		check(list->last != NULL,
				"Invalid list, somehow got a next that is NULL.");
		list->last->next = NULL;
	} else {
		ListNode *after = node->next;
		ListNode *before = node->prev;
		after->prev = before;
		before->next =after;
		//Try ! TODO
		//node->next->prev = node->prev;
		//node->prev->next = node->next;
	}
	
	list->count--;
	result = node->value;
	free(node);

error:
	return result;
}















