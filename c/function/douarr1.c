#include <stdio.h>
#include <stdlib.h>

#define M	2
#define N	3

void func(int *, int *,int *,int ,int(*)[N], int *,int ,int *, int ,int ,int )
{
}

int main()
{
	int a[M][N] = {{3,4,5},{6,7,8}};
	int i,j;
	int (*p)[N] = a;
	int *q = *a;

	func(a[1],*p,q+3,*q+2,p+1,*p+1,a[0][0],a[1]+1,**p,*q,*q+p[1][1]);

	exit(0);
}

