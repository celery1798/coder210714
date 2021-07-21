#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i = 1;
	int *p = &i;
	void *m = NULL;

	*p = 100;
	printf("%d\n",*p);


	exit(0);
}

