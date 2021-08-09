#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

QUEUE *queue_create()
{
	QUEUE *qu;

	qu = malloc(sizeof(*qu));
	if(qu == NULL)
		return NULL;
	qu->front = qu->tail = 0;
	return qu;
}

void queue_create1(QUEUE **ptr)
{
	*ptr = malloc(sizeof(QUEUE));
	if(*ptr == NULL)
		return ;
	(*ptr)->front = (*ptr)->tail = 0;
	return ;
}

int queue_isempty(QUEUE *ptr)
{
	if(ptr->front == ptr->tail)
		return 1;
	return 0;
}
int queue_isfull(QUEUE *ptr)
{
	if((ptr->tail + 1)%DATAMAX == ptr->front)
		return 1;
	return 0;
}

int queue_en(QUEUE *ptr,const int *x)
{
	if(queue_isfull(ptr))
		return -1;

	ptr->tail = (ptr->tail + 1)%DATAMAX;	
	ptr->data[ptr->tail] = *x;
	return 0;
}
int queue_de(QUEUE *ptr,int *x)
{
	if(queue_isempty(ptr))
		return -1;

	ptr->front = (ptr->front + 1)%DATAMAX;
	*x = ptr->data[ptr->front];
	return 0;
}	

void queue_display(QUEUE *ptr)
{
	int i = (ptr->front+1)%DATAMAX;
	while(i != ptr->tail)
	{
		printf("%d ",ptr->data[i]);
		i++;
	}
	printf("%d\n",ptr->data[i]);
}

void queue_destroy(QUEUE *ptr)
{
	free(ptr);
}
