#include <stdio.h>
#include <stdlib.h>


typedef struct node_st
{
	int data;
	struct node_st *next;
}JOSEPHU;

JOSEPHU *josephu_create(int n)
{
	JOSEPHU *l,*p,*q;
	int i = 1;

	l = malloc(sizeof(*l));
	if(l == NULL)
		return NULL;
	l->data = i;
	l->next = l;

	p = l;
	i++;

	while(i <= n)
	{
		q = malloc(sizeof(*q));
		if(q == NULL)
			return NULL;
		q->data = i;
		i++;
		q->next = l;
		p->next = q;
		p = q;
	}
	return l;
}

void josephu_show(JOSEPHU *l)
{
	JOSEPHU *p = l;

	while(p->next != l)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("%d\n",p->data);
}

void josephu_kill(JOSEPHU **l, int n)
{
//  l-> 1 2 3 4 5 6 7 8     n = 3   i = 1  p->1
/*
	while(1<3)  q->1;p->2;i=2;
	while(2<3)	q->2;p->3;i=3;
	while(3<3)  -----
*/
	int i = 1;
	JOSEPHU *p = *l,*q;

	printf("KILL:");

	while(p->next != p)
	{
		while(i < n)
		{
			q = p;
			p = p->next;
			i++;
		}

		q->next = p->next;
		printf("%d ",p->data);
		free(p);

		i = 1;
		p = q->next;
	}
	printf("\n");

	*l = p;
}

int main()
{
	JOSEPHU *l;
	int num = 8;
	int count = 3;

	l = josephu_create(num);

	josephu_show(l);

	josephu_kill(&l,count);
	josephu_show(l);


	exit(0);
}


