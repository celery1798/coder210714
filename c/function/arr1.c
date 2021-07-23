#include <stdio.h>
#include <stdlib.h>

#define N		5

void func(int *p, int n, int ,int *, int, int ,int ,int *,int )
{
}

int main()
{
	int i;
	int arr[] = {5,6,7,8,9,8,9,2,3,4,5,6,7};
	int *p = arr;

	func(p,sizeof(arr)/sizeof(*arr),p[0],a+3,*a,a[5],*p,p++,*(p+4)+2);	


	exit(0);
}









