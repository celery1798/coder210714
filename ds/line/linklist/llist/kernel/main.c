#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define NAMESIZE	32

struct score_st
{
	int id;
	char name[NAMESIZE];
	struct list_head node;
	int math;
};

void print_s(void *data)
{
	struct score_st *d = data;

	printf("%d %s %d\n",d->id, d->name, d->math);
}

int main()
{
	int i;
	struct score_st *tmp;
	struct list_head *cur;

	LIST_HEAD(head);
//	struct list_head head = { &(head), &(head) }
	
	for(i = 0 ; i < 7 ; i++)
	{
		tmp = malloc(sizeof(*tmp));
		/*if error*/
		tmp->id = i;
		tmp->math = 100-i;
		snprintf(tmp->name, NAMESIZE,"STU%d",i);

		list_add(&tmp->node,&head);
	}


	list_for_each(cur, &head)
	{
		tmp = list_entry(cur,struct score_st, node);
		print_s(tmp);
	}

	exit(0);
}




