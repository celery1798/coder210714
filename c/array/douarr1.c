#include <stdio.h>
#include <stdlib.h>

#define M	2
#define N	3

/*
	int a[2][3];
	value:  a[i][j]   *(*(a+i)+j)
	addr:  &a[i][j]   *(a+i)+j
*/


int main()
{
	int a[M][N] = {{3,4,5},{6,7,8}}; 
	int i,j;

	printf("a = %p\n",a);
	printf("a+1 = %p\n\n",a+1);

	for(i = 0 ; i < M; i++)
	{
		for(j = 0 ; j < N; j++)
//			printf("%p -- > %d\n",&a[i][j],a[i][j]);			
			printf("%p -- > %d\n", *(a+i)+j, *(*(a+i)+j));			
		printf("\n");
	}


	exit(0);
}

