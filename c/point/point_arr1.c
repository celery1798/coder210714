#include <stdio.h>
#include <stdlib.h>

/*
	int arr[3];
	int *p = arr
	value: arr[i]   *(arr+i)  *(p+i)   p[i]
	addr:  &arr[i]   arr+i	  p+i      &p[i]
*/

int main()
{
	int arr[3] = {4,5,6};
	int i;
	int *p = arr;
	
	for(i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++,p++)
		scanf("%d",p);	

	p = arr;

	for(i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++)
		printf("%p --> %d\n",&p[i],p[i]);
	printf("\n");


	exit(0);
}









