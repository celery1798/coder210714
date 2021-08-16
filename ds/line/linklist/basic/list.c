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

int list_delete(LIST *ptr,int pos, int *newdata)
{// ->  -  3 4 5 6;  pos = 2
/*     i = 0;p-> -
	 while(0<2 && p)	p->3;i=1
	 while(1<2&&p )     p->4;i=2
	 while(2<2&&p )  
*/
	int i = 0;
    LIST *p = ptr,*q;

	if(list_isempty(ptr))
		return -2;

    while(i < pos && p )
    {
        p = p->next;
        i++;
    }

	if(p)
	{
		q = p->next;
		p->next = q->next;
		if(newdata != NULL)
			*newdata = q->data;
		free(q);
		q = NULL;
		return 0;
	}
	else // p == NULL
		return -1;
}

//value
int list_insert_value(LIST *ptr,int *newdata)
{// ->  -   2 4  6 8   *newdata = 5;
/*	p->-
	while(2<5)   p->2
	while(4<5)   p->4
	while(6<5)   -----
*/	
	
	LIST *p = ptr,*q;

	while(p->next && p->next->data < *newdata)
		p = p->next;

	q = malloc(sizeof(*q));
	if(q == NULL)
		return -1;
	q->data = *newdata;
	q->next = p->next;
	p->next = q;
	return 0;
}
int list_delete_value(LIST *ptr,int *newdata)
{// ->  -   2 4 6 8   *newdata = 6;
	
	LIST *p = ptr,*q;

	if(list_isempty(ptr))
		return -2;

	while(p->next && p->next->data != *newdata)
		p = p->next;

	if(p->next == NULL)
		return -1;
	else
	{
		q = p->next;
		p->next = q->next;
		free(q);
		q = NULL;
		return 0;
	}
}

int list_find(LIST *ptr,int *data)
{
	LIST *p = ptr->next;

	if(list_isempty(p))
        return -1;

	while(p)
	{
		if(p->data == *data)
			return 0;
		p = p->next;
	}
	return -2;
}

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

void list_destroy(LIST *ptr)
{
	LIST *p = ptr->next,*q;

	if(list_isempty(p))
        return ;

	while(p)
    {
		q = p->next;
        free(p);
		p = q;
    }
	free(ptr);
}

void list_reverse(LIST *ptr)		
{
	LIST *p,*q,*r;

	if(ptr->next == NULL || ptr->next->next == NULL)
		return ;
	
	p = ptr->next->next;
	q = ptr->next;
	r = NULL;
	
	while(p)
	{
		q->next = r;
		r = q;
		q = p;
		p = p->next;
	}

	q->next = r;
	r = q;
	ptr->next = r;

}



