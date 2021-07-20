#include <stdio.h>
#include <stdlib.h>

/*
 二维数组的数组名，本质为地址常量
二维数组在内存中存放方式为以行为单位，顺次存放
*/

#define M	2
#define N	3

int main()
{
//	int a[M][N] = {{3,4,5},{6,7,8}};
//	int a[M][N] = {3,4,5,6,7,8};
//	int a[M][N] = {3,4,5,6};
//	int a[M][N] = {{3},{4,5,6}};
	int a[][N] = {3,4,5,6,7,8};
	int i,j;

	printf("a = %p\n\n",a);

	printf("sizeof(a[0][0]) = %ld\n",sizeof(a[0][0]));
	printf("sizeof(a) = %ld\n",sizeof(a));

/*
	for(i = 0 ; i < M; i++)
    {
		for(j = 0 ; j < N; j++)
			scanf("%d",&a[i][j]);
	}	
*/

	for(i = 0 ; i < M; i++)
	{
		for(j = 0 ; j < N; j++)
			printf("%p -- > %d\n",&a[i][j],a[i][j]);			
		printf("\n");
	}


	exit(0);
}

