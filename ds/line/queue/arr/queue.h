

#ifndef __QUEUE_H__
#define __QUEUE_H__

#define DATAMAX		6

typedef struct 
{
	int data[DATAMAX];
	int front;
	int tail;
}QUEUE;

QUEUE *queue_create();
void queue_create1(QUEUE **);

int queue_isempty(QUEUE *);
int queue_isfull(QUEUE *);

int queue_en(QUEUE *,const int *x);
int queue_de(QUEUE *,int *x);

void queue_display(QUEUE *);

void queue_destroy(QUEUE *);

#endif


