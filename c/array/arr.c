#include <stdio.h>
#include <stdlib.h>

/*
一维数组
数组名是表示地址的常量

*/

#define N		5

int main()
{
	int i;
//	int arr[3];	
//	int arr[3] = {4,5,6};
//	int arr[] = {4,5,6};
//	int arr[3] = {4,8};

	int arr[] = {5,6,7,8,9,8,9,2,3,4,5,6,7};

	printf("sizeof(arr) = %ld\n",sizeof(arr));
	printf("sizeof(arr[0]) = %ld\n",sizeof(arr[0]));


	printf("arr = %p\n\n",arr);

//	for(i = 0 ; i < 3; i++)
//		scanf("%d",&arr[i]);

//	arr[0] = 100;
//	arr[1] = arr[0]/20;
//	arr[2] = arr[0]/arr[1];


	for(i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++)
		printf("%p --> %d\n",&arr[i],arr[i]);
	printf("\n");



	exit(0);
}









