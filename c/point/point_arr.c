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
//	int *p;
//	p = arr
	
	printf("sizeof(arr) = %ld\n",sizeof(arr));
	printf("sizeof(p) = %ld\n\n",sizeof(p));
	
	printf("arr = %p\n",arr);
	printf("arr+1 = %p\n\n",arr+1);

	printf("p = %p\n",p);
	printf("p+1 = %p\n\n",p+1);

	for(i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++)
//		printf("%p --> %d\n",&arr[i],arr[i]);
//		printf("%p --> %d\n",p+i,*(p+i));
		printf("%p --> %d\n",&p[i],p[i]);
	printf("\n");


	exit(0);
}









