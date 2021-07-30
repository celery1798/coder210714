#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"


int main()
{
	SQLIST *sq;
	int a[] = {4,5,6,7,8};
	int i,x;
		
	sq = sqlist_create();
	if(sq == NULL)
	{
		printf("sqlist_create() error.\n");
		exit(1);
	}
	
	for(i = 0 ; i < sizeof(a)/sizeof(*a); i++)
		sqlist_insert(sq, 0, &a[i]);

	sqlist_display(sq);

	x = 100;
	sqlist_insert(sq,15,&x);
	sqlist_display(sq);

	sqlist_delete(sq, 2, &x);
	printf(x);


	sqlist_destroy(sq);

	exit(0);
}




