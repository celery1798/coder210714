#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"


int main()
{
	SQLIST *sq,*sq1;
	int a[] = {14,5,26,37,8};
	int b[] = {4,5,6,7,8};
	int i,x;
		
	sq = sqlist_create();
	if(sq == NULL)
	{
		printf("sqlist_create() error.\n");
		exit(1);
	}
	
	for(i = 0 ; i < sizeof(a)/sizeof(*a); i++)
//		sqlist_insert(sq, 0, &a[i]);
		sqlist_insert_value(sq,&a[i]);
	sqlist_display(sq);


	sq1 = sqlist_create();
    if(sq1 == NULL)
    {
        printf("sqlist_create() error.\n");
        exit(1);
    }

    for(i = 0 ; i < sizeof(b)/sizeof(*b); i++)
        sqlist_insert_value(sq1,&b[i]);
    sqlist_display(sq1);

	sqlist_union(sq,sq1);
	sqlist_display(sq);

/*
	x = 137;
	sqlist_delete_value(sq,&x);
	sqlist_display(sq);

*/

/*
	x = 100;
	sqlist_insert(sq,15,&x);
	sqlist_display(sq);
*/
/*
	sqlist_delete(sq, 14, &x);
	printf("DEL:%d\n",x);
*/
//	sqlist_display(sq);

/*
	sqlist_setempty(sq);
	x = 6;
	printf("FIND:%d\n",sqlist_find(sq,&x));

*/
	sqlist_destroy(sq);

	exit(0);
}




