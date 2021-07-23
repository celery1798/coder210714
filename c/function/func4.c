#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
	if(n < 0)
		return -1;
	if(n == 0 || n == 1)
		return 1;

	return fib(n-1) + fib(n-2);
}

int main()
{
	int num;

	scanf("%d",&num);

	printf("%d\n",fib(num));


	exit(0);
}

