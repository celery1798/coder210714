#include <stdio.h>
#include <stdlib.h>


typedef struct node_st
{
	int coef;
	int exp;
	struct node_st *next;
}POLY;

POLY *poly_create(int (*a)[2],int m)
{
	POLY *head,*p,*q;
	int i;

	head = malloc(sizeof(*head));
	if(head == NULL)
		return NULL;
	head->next = NULL;

	p = head;

	for(i = 0 ; i < m ; i++)
	{
		q = malloc(sizeof(*q));
		if(q == NULL)
			return NULL;
		q->coef = a[i][0];
		q->exp = a[i][1];
		q->next = NULL;

		p->next = q;
		p = q;
	}

	return head;
}

void poly_display(POLY *head)
{
	POLY *cur = head->next;

	while(cur)
	{
		printf("(%d,%d) ",cur->coef,cur->exp);
		cur = cur->next;
	}
	printf("\n");
}

void poly_add(POLY *p1,POLY *p2)
{
	POLY *p = p1->next;
	POLY *q = p2->next;
	POLY *r = p1;

	
	while(p && q)
	{
		if(p->exp < q->exp)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			if(p->exp > q->exp)
			{
				r->next = q;
				r = q;
				q = q->next;
			}
			else // p->exp == q->exp
			{
				p->coef += q->coef;
				if(p->coef)
				{
					r->next = p;
					r = p;
				}
				p = p->next;
				q = q->next;
			}
		}
	}

	if(p == NULL)
		r->next = q;
	else
		r->next = p;
}

int main()
{
	int a[][2] = {{5,0},{2,1},{8,8},{-34,16}};
	int b[][2] = {{6,1},{7,6},{-8,8}};
	POLY *p1,*p2;
	
	p1 = poly_create(a,4);
	poly_display(p1);
	
	p2 = poly_create(b,3);
	poly_display(p2);

	poly_add(p1,p2);
	poly_display(p1);

	exit(0);
}


