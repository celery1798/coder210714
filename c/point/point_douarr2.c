#include <stdio.h>
#include <stdlib.h>

#define M	2
#define N	3

int main()
{
	int a[M][N] = {{3,4,5},{6,7,8}}; 
	int i,j;
	int (*p)[3] = a;
	int *q = a[0];	// *(a+0)+0  //	*a;		//*(a+0)	;			//&a[0][0];


	for(i = 0 ; i < M*N; i++)
		printf("%d ",*(q+i));	//q[i]
	printf("\n");


	for(i = 0 ; i < M; i++)
	{
		for(j = 0 ; j < N; j++)
			printf("%p -- > %d\n",&p[i][j],p[i][j]);			
		printf("\n");
	}


	exit(0);
}

