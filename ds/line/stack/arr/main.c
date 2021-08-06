#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{
	STACK *st;
	int a[] = {1,3,5,7,9,11,13};
	int i,tmp;

//	st = stack_create();	
	stack_create2(&st);
	/*if error*/

	for(i = 0 ; i < sizeof(a)/sizeof(*a); i++)
		stack_push(st,&a[i]);

	stack_display(st);

	while(!stack_isempty(st))
	{
		stack_pop(st,&tmp);
		printf("POP:%d\n",tmp);
	}		
	stack_destroy(st);

	exit(0);
}

