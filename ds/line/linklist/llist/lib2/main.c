#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

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

int id_cmp(const void *key, const void *data)
{
	const int *k = key;
	const struct score_st *d = data;

	return *k - d->id;
}

int name_cmp(const void *key, const void *data)
{
	const char *k = key;
	const struct score_st *d = data;

	return strcmp(k, d->name);
}

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

		llist_insert(handler, &tmp, LLIST_BACKWARD);
	}

	llist_travel(handler,print_s);
	printf("\n\n");

	int findid = 12;
	char *findname = "STU40";
	struct score_st *retp;

/*
	//retp = llist_find(handler,&findid,id_cmp);
	retp = llist_find(handler,findname,name_cmp);
	if(retp)
		print_s(retp);
	else
		printf("Can not find.\n");
*/
//	llist_delete(handler,&findid,id_cmp);
	if(llist_fetch(handler,&findid,id_cmp,&tmp) == 0)
		print_s(&tmp);
	printf("\n\n");	
	

	llist_travel(handler,print_s);


	llist_destroy(handler);

	exit(0);
}




