#include <stdio.h>
#include <stdlib.h>

//#define 宏名  宏体
#define PI	3.14159
#define MM	(2+3)

int func(int a,int b)
{
	return a > b ? a : b ;
}

//#define MAX(a,b)	(a > b ? a : b)
//#define MAX(a,b)	({int A=(a),B=(b); A > B ? A : B;})
#define MAX(a,b)	({typeof(a) A=(a),B=(b); A > B ? A : B;})


int main()
{
	int i = 3,j = 5;
//	printf("%d\n",func(i,j));

	printf("i = %d , j = %d\n",i,j);
	printf("%d\n",MAX(i++,j++));
	printf("i = %d , j = %d\n",i,j);



/*
	//PI * r * r;
	printf("%d\n",MM*MM);
*/


	exit(0);
}

