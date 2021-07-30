#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

SQLIST *sqlist_create()
{
	SQLIST *ptr;

	ptr = malloc(sizeof(*ptr));
	if(ptr == NULL)
		return NULL;
	
	ptr->last = -1;
	return ptr;
}

int sqlist_isempty(SQLIST *ptr)
{
	if(ptr->last == -1)
		return 1;
	return 0;
}

int sqlist_isfull(SQLIST *ptr)
{
	if(ptr->last == DATAMAX-1)
		return 1;
	return 0;
}

int sqlist_setempty(SQLIST *ptr)
{
	ptr->last = -1;
	return 0;
}

int sqlist_insert(SQLIST *ptr, int pos ,int *newdata)
{
	int i;
	if(sqlist_isfull(ptr))
		return -1;

	if(pos < 0 || pos > ptr->last+1)
		return -2;

	i = ptr->last;
	
	while(i >= pos)
	{
		ptr->data[i+1] = ptr->data[i];
		i--;
	}	

	ptr->data[pos] = *newdata;
	ptr->last ++;

	return 0;
}

int sqlist_delete(SQLIST *ptr,int pos,int *x)
{
	int i;
	if(sqlist_isempty(ptr))
		return -1;
	if(pos < 0 || pos > ptr->last)
		return -2;
	
	if(x != NULL)
		*x = ptr->data[pos];

	i = pos+1;
	
	while(i <= ptr->last)
	{
		ptr->data[i-1] = ptr->data[i];
		i++;
	}

	ptr->last--;

	return 0;
}

int sqlist_insert_value(SQLIST *ptr,int *newdata)
{//3 5     *newdata=12
	int i = 0;
	if(sqlist_isfull(ptr))
		return -1;

	while(i <= ptr->last && ptr->data[i]  < *newdata)		
		i++;	 
	return sqlist_insert(ptr,i,newdata);

}
int sqlist_delete_value(SQLIST *ptr,int *x)
{
	int pos;

	pos = sqlist_find(ptr,x);

	if(pos >= 0)
	{
		return sqlist_delete(ptr,pos,NULL);
	}

	return pos;
}

int sqlist_find(SQLIST *ptr, int *x)
{
	int i;
	if(sqlist_isempty(ptr))
		return -2;

	for(i = 0 ; i <= ptr->last;i++)
		if(ptr->data[i] == *x)
			return i;
	return -1;
}

int sqlist_union(SQLIST *ptr1,SQLIST *ptr2)
{
	int i,ret;
	if(sqlist_isempty(ptr2))
		return -1;

	for(i = 0 ; i <= ptr2->last	;i++)
	{	
		ret = sqlist_find(ptr1, &ptr2->data[i]);
		if(ret == -1)
			sqlist_insert_value(ptr1, &ptr2->data[i]);
			/*if error*/
	}
	return 0;
}

void sqlist_display(SQLIST *ptr)
{
	int i;
	
	if(sqlist_isempty(ptr))
		return ;

	for(i = 0 ; i <= ptr->last; i++)
		printf("%d ",ptr->data[i]);
	printf("\n");
}

void sqlist_destroy(SQLIST *ptr)
{
	free(ptr);
	ptr = NULL;
}




