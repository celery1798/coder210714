#include <stdio.h>
#include <stdlib.h>

typedef int (*FUNCP)(int,int);

int op(int a,int b, FUNCP p)
{
	return p(a,b);
}
int plus(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int main()
{
	int i = 3,j = 5;
	int t;
	
	printf("%d\n",op(i,j,sub));

	exit(0);
}

