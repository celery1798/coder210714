#include <stdio.h>
#include <stdlib.h>

/*

	int arr[3];
	value: arr[i]   *(arr+i)
	addr:  &arr[i]   arr+i

	eg: arr[1] <=> *(arr+1) <=> *(1+arr)  <=> 1[arr]   it's a joke


*/




int main()
{
	int arr[3] = {4,5,6};
	int i;


	printf("arr = %p\n\n",arr);

	for(i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++)
//		printf("%p --> %d\n",&arr[i],arr[i]);
//		printf("%p --> %d\n",arr+i,*(arr+i));
		printf("%p --> %d\n",arr+i,i[arr]);
	printf("\n");


//数组越界
//FFFFF	arr[30] = 120;
//FFFFF	printf("!!!!%d\n",arr[30]);




	exit(0);
}









