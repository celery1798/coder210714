#include <stdio.h>
#include <stdlib.h>

#define M	2
#define N	3

void test1()
{
	int a[M][N] = {1,2,3,4,5,6};
	int b[N][M],i,j;

	for(i = 0 ; i < M ; i++)
	{
		for(j = 0 ; j < N ; j++)
		{
			printf("%d ",a[i][j]);
			b[j][i] = a[i][j];
		}
		printf("\n");
	}

	for(i = 0 ; i < N; i++)
	{
		for(j = 0 ; j < M ; j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
}

void test2()
{
	int a[3][4] = {78,45,2,6,123,4,9,16,98,2,67,12};
	int i,j,max,col,line;

	max = a[0][0];
	col = line = 0;

	for(i = 0 ; i < 3; i++)
	{
		for(j = 0 ; j < 4; j++)
		{
			if(max < a[i][j])
			{
				max = a[i][j];
				line = i;
				col = j;
			}
		}
	}
	printf("MAX:a[%d][%d] = %d\n",line,col,max);
}

void test3()
{
	int a[5][4] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	int i,j;

	for(i = 0 ; i < 5-1; i++)
	{
		for(j = 0 ; j < 4-1; j++)
		{
			a[4][3] += a[i][j];
			a[4][j] += a[i][j];
			a[i][3] += a[i][j];
		}
	}

	for(i = 0 ; i < 5; i++)
    {
        for(j = 0 ; j < 4; j++)
        {
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}



}

int main()
{

//	test1();
//	test2();
	test3();

	exit(0);
}

