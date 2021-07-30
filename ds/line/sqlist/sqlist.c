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




