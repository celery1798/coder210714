#include <stdio.h>
#include <stdlib.h>

int fun(int n)
{
	if(n < 0)
		return -1;
	if(n == 0 || n == 1)
		return 1;

	return n * fun(n-1);
}

int main()
{
	int num;

	scanf("%d",&num);

	printf("%d! = %d\n",num,fun(num));


	exit(0);
}

