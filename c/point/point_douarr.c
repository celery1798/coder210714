#include <stdio.h>
#include <stdlib.h>

#define M	2
#define N	3

/*
	int a[2][3];
										int[3] a[2];
										int[3] *p = a
	int (*p)[3] = a;		->数组指针

	value:  a[i][j]   *(*(a+i)+j)  *(*(p+i)+j)   p[i][j]
	addr:  &a[i][j]   *(a+i)+j		*(p+i)+j	 &p[i][j]	
*/


int main()
{
	int a[M][N] = {{3,4,5},{6,7,8}}; 
	int i,j;
	int (*p)[3];
//	int *p;

	p = a;

	printf("sizeof(a) = %ld\n",sizeof(a));
	printf("sizeof(p) = %ld\n\n",sizeof(p));

	printf("a = %p\n",a);
	printf("a+1 = %p\n\n",a+1);

	printf("p = %p\n",p);
    printf("p+1 = %p\n\n",p+1);


	for(i = 0 ; i < M; i++)
	{
		for(j = 0 ; j < N; j++)
//			printf("%p -- > %d\n",&a[i][j],a[i][j]);			
//			printf("%p -- > %d\n",*(p+i)+j, *(*(p+i)+j));			
			printf("%p -- > %d\n",&p[i][j],p[i][j]);			
		printf("\n");
	}


	exit(0);
}

