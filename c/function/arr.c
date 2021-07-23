#include <stdio.h>
#include <stdlib.h>

#define N		5

void print_arr(int p[], int n)	//int *p
{
	int i;

	printf("sizeof(p) = %ld\n",sizeof(p));
	
	for(i = 0 ; i < n ; i++)
		printf("%p --> %d\n",&p[i],p[i]);
	printf("\n");
}

int main()
{
	int i;
	int arr[] = {5,6,7,8,9,8,9,2,3,4,5,6,7};
	int *p = arr;

//	printf("sizeof(arr) = %ld\n",sizeof(arr));

	print_arr(p,sizeof(arr)/sizeof(*arr));	
//	print_arr(arr,sizeof(arr)/sizeof(*arr));	


	exit(0);
}









