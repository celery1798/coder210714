#include <stdio.h>
#include <stdlib.h>

#include "llist.h"

#define NAMESIZE	32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
};


int main()
{
	LLIST *handler;
	struct score_st tmp;
	int i;

	handler = llist_create(sizeof(struct score_st));
	if(handler == NULL)
	{
		printf("llist_create() failed.\n");
		exit(1);
	}


	for(i = 0 ; i < 7 ; i++)
	{
		tmp.id = i;
		tmp.math = 100-i;
		snprintf(tmp.name, NAMESIZE,"STU%d",i);

		llist_insert(handler, &tmp, LLIST_FORWARD);
	}

	llist_travel();

	exit(0);
}




