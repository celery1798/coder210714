#include <stdio.h>
#include <stdlib.h>

/* swap */
/*
void swap(int *a,int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
*/

void swap(int **a,int **b)
{
    int t;
    t = **a;
    **a = **b;
    **b = t;
}

int main()
{
	int a = 3,b = 5;
	int *p = &a,*q = &b;
	int **m = &p,**n = &q;

	printf("a = %d, b = %d\n",a,b);
//	swap(&a,&b);
	swap(m,n);
	printf("a = %d, b = %d\n",a,b);

	exit(0);

}

