#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#define NAMESIZE	32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
};

void print_s(void *data)
{
	struct score_st *d = data;

	printf("%d %s %d\n",d->id, d->name, d->math);
}

int main()
{
	STACK *handler;
	struct score_st tmp;
	int i,ret;

	handler = stack_create(sizeof(struct score_st));
	if(handler == NULL)
	{
		printf("stack_create() failed.\n");
		exit(1);
	}


	for(i = 0 ; i < 7 ; i++)
	{
		tmp.id = i;
		tmp.math = 100-i;
		snprintf(tmp.name, NAMESIZE,"STU%d",i);

		stack_push(handler, &tmp);
	}

	while(1)
	{
		ret = stack_pop(handler,&tmp);
		if(ret)
			break;
		print_s(&tmp);
	}

	stack_destroy(handler);

	exit(0);
}




