#include <stdio.h>
#include <stdlib.h>

// score    3*4  

#define M	3
#define N	4

float func_ave(int *p, int n)
{
	int i;
	float sum = 0;
	for(i = 0 ; i < n ; i++)
		sum += p[i];
	return  sum / n;
}
#if 0
int func_find(int (*p)[N],int m,int n)
{
	int id,i;
	printf("Pease enter the ID[0,2]:");
	scanf("%d",&id);

	if(id < 0 || id > 2)
		return -1;
	
	for(i = 0 ; i < n;i++)
		printf("%d ",p[id][i]);
	printf("\n");
	return 0;
}

#else


int * func_find(int (*p)[N],int m,int n)
{
    int id,i;
    printf("Pease enter the ID[0,2]:");
    scanf("%d",&id);

    if(id < 0 || id > 2)
        return NULL;
    
	return *(p+id);

}

#endif

int main()
{
	int a[M][N] = {{98,78,84,91},{99,78,85,88},{88,89,90,100}};
	int *retp;
	int i;

	printf("AVE = %f\n",func_ave(*a,M*N));
	retp = func_find(a,M,N);
	if(retp)
	{
		for(i = 0 ; i < N ;i++)
      	  printf("%d ",retp[i]);
 	   printf("\n");	
	}
	else
	{
		printf("Can not find.\n");
	}
	exit(0);
}







