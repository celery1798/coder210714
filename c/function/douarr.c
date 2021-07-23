#include <stdio.h>
#include <stdlib.h>

#define M	2
#define N	3

#if 0
void print_douarr(int (*p)[N],int m,int n )
{
	int i,j;
	printf("sizeof(p) = %ld\n",sizeof(p));
	
	for(i = 0 ; i < m; i++)
	{
		for(j = 0 ; j < n ;j++)
			printf("%p -- > %d\n",&p[i][j],p[i][j]);			
		printf("\n");
	}
}

#else

void print_douarr(int *p, int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
}

#endif


int main()
{
	int a[M][N] = {{3,4,5},{6,7,8}};
	int i,j;
	int (*p)[N] = a;
	int *q = *a;

//	printf("sizeof(a) = %ld\n",sizeof(a));
//	printf("sizeof(a[0][0]) = %ld\n\n",sizeof(a[0][0]));

//	print_douarr(p,M,N);
	print_douarr(q,M*N);

	exit(0);
}

