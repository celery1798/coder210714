#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{
	QUEUE *qu;
	int a[] = {1,3,5,7,9,11,13};
	int i,tmp;

//	qu = queue_create();	
	queue_create1(&qu);
	/*if error*/

	for(i = 0 ; i < sizeof(a)/sizeof(*a); i++)
		queue_en(qu,&a[i]);

	queue_display(qu);

	while(!queue_isempty(qu))
	{
		queue_de(qu,&tmp);
		printf("DE:%d\n",tmp);
	}	
	
	queue_destroy(qu);

	exit(0);
}

