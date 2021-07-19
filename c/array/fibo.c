#include <stdio.h>
#include <stdlib.h>

#define N 		10

int main()
{
	int f[N] = {1,1};
	int i,j,t;

	for(i = 2; i < N ; i++)
		f[i] = f[i-1] + f[i-2];

	for(i = 0 ; i < N ; i++)
		printf("%d ",f[i]);
	printf("\n");

//-----------
	for(i = N-1; i >= 0 ; i--)
		printf("%d ",f[i]);
    printf("\n");
//--------------

	i = 0;
	j = N-1;

	while(i < j)
	{
		t = f[i];
		f[i] = f[j];
		f[j] = t;

		i++;
		j--;
	}
	
	for(i = 0 ; i < N ; i++)
        printf("%d ",f[i]);
    printf("\n");

	exit(0);
}

