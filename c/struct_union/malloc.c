#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int func(char **x, int n)
{
	*x = malloc(n);
    if(*x == NULL)
    {
        printf("malloc() error.\n");
        return  -1 ;
    }

	strcpy(*x,"hello");
	puts(*x);
	return 0;
}

int main()
{
	char *p = NULL;

	func(&p,100);

	free(p);

/*
	int *p ;

	p = malloc(100);
	if(p == NULL)
	{
		printf("malloc() error.\n");
		exit(1);
	}
		
	*p = 1;
	printf("%p -- %d\n",p,*p);

	free(p);
	p = NULL;
*/	
	exit(0);
}

