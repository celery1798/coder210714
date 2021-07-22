#include <stdio.h>
#include <stdlib.h>

#define M	2
#define N	3

/*
	int a[2][3];
	int (*p)[3] = a;		->数组指针

	value:  a[i][j]   *(*(a+i)+j)  *(*(p+i)+j)   p[i][j]
	addr:  &a[i][j]   *(a+i)+j		*(p+i)+j	 &p[i][j]	
*/


int main()
{
	int a[M][N] = {{3,4,5},{6,7,8}}; 
	int i,j,k;
//	int (*p)[3];				数组指针
	int * p [3] = {&i , &j, &k};			指针数组		

	
->		p[0]	p+1		p++		 p  	*p
	    int *   int*    FFFF     int*   *(p+0)=>p[0]int*


->	int a[3];
		a[0]int   *a  *(a+0) a[0] int



	exit(0);
}







