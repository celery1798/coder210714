#include <stdlib.h>
#include <string.h>

#include "llist.h"

LLIST* llist_create(int size)
{
	LLIST *new;
	
	new = malloc(sizeof(*new));
	if(new == NULL)
		return NULL;

	new->size = size;
	new->head.data = NULL;
	new->head.prev = new->head.next = &new->head;
	
	return new;
}

int llist_insert(LLIST *ptr, const void *data,int mode)
{
	struct llist_node_st *newnode;

	newnode = malloc(sizeof(*newnode));
	if(newnode == NULL)
		return -1;
	
	newnode->data = malloc(ptr->size);
	if(newnode->data == NULL)
	{
		free(newnode);
		return -2;
	}
	memcpy(newnode->data, data, ptr->size);


	if(mode == LLIST_FORWARD)
	{
		newnode->prev = &ptr->head;
		newnode->next = ptr->head.next;
	}
	else
	{
		if(mode == LLIST_BACKWARD)
		{
			newnode->prev = ptr->head.prev;
			newnode->next = &ptr->head;
		}
		else
			return -3;
	}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;

	return 0;
}

void *llist_find(LLIST *ptr,const void *key,llist_cmp *cmp)
{

	struct llist_node_st *cur;

	for(cur = ptr->head.next; cur != &ptr->head ; cur = cur->next)
	{
		if(cmp(key, cur->data) == 0)
			return cur->data;
	}

	return NULL;

}


void llist_travel(LLIST *ptr, llist_op *op)
{
	struct llist_node_st *cur;

	for(cur = ptr->head.next; cur != &ptr->head ; cur = cur->next)
		op(cur->data);

}













