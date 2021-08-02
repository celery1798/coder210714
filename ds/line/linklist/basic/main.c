#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
	LIST *handler;
	int a[] = {4,8,3,9,2};
	int i;

//	handler = list_create();
	list_create1(&handler);
	if(handler == NULL)
	{
		printf("list_create() error.\n");
		exit(1);
	}

	for(i = 0 ; i < sizeof(a)/sizeof(*a); i++)
		list_insert(handler, 0, &a[i]);

	list_display(handler);

/*
	int tmp = 100;
	list_insert(handler,15,&tmp);
	list_display(handler);
*/


	exit(0);
}


