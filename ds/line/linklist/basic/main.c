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
//		list_insert(handler, 0, &a[i]);
		list_insert_value(handler,&a[i]);
	list_display(handler);

	list_reverse(handler);
	list_display(handler);

/*
	int tmp = 18;
	list_delete_value(handler,&tmp);
	list_display(handler);
*/

/*
	list_insert(handler,15,&tmp);
	list_display(handler);
*/

//	list_delete(handler,14,NULL);
//	printf("FIND:%d\n",list_find(handler,&tmp));

//	list_display(handler);

	list_destroy(handler);
	exit(0);
}


