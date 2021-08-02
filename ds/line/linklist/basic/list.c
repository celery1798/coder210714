#include <stdio.h>
#include <stdlib.h>

#include "list.h"

LIST *list_create()
{
	LIST *p;

	p = malloc(sizeof(*p));
	if(p == NULL)
		return NULL;

	p->next = NULL;
	return p;
}

void list_create1(LIST **p)
{
	*p = malloc(sizeof(**p));
    if(*p == NULL)
        return ;

    (*p)->next = NULL;
    return ;
}

int list_isempty(LIST *p)
{
	if(p->next == NULL)
		return 1;
	return 0;
}

//pos
int list_insert(LIST *ptr,int pos, int *newdata)
{    
	int i = 0;
	LIST *p = ptr,*q;

	while(i < pos && p )
	{
		p = p->next;
		i++;
	}

	if(p)
	{
		q = malloc(sizeof(*q));
		if(q == NULL)
			return -1;
		q->data = *newdata;
		q->next = p->next;
		p->next = q;

		return 0;
	}	//p == NULL
	else
		return -2;
}
/*
int list_delete(LIST *,int pos, int *newdata);

//value
int list_insert_value(LIST *,int *newdata);
int list_delete_value(LIST *,int *newdata);

int list_find(LIST *int *data);
*/
void list_display(LIST *ptr)
{
	LIST *p = ptr->next;
	
	if(list_isempty(p))
		return ;

	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

//void list_destroy(LIST *);
