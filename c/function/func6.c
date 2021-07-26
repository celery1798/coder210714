#include <stdio.h>
#include <stdlib.h>
//  type name = value 
/*
!	int(int,int)   plus{ ... } 
	int plus(int,int){  }
*/


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

//    int (*p)(int,int) = plus;
  //  int (*s)(int,int) = sub;

	int(*arr[2])(int,int) = {plus, sub}; 		//函数指针 数组

	for(t = 0 ; t< 2; t++)
    	printf("%d\n",arr[t](i,j));




/*
	int i = 3,j = 5;

	int (*p)(int,int) = plus;
	int (*s)(int,int) = sub;

//	printf("%d\n",plus(i,j));
	printf("%d\n",p(i,j));
	printf("%d\n",s(i,j));
*/

	exit(0);
}

