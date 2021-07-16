#include <stdio.h>
#include <stdlib.h>

/*
if( exp )
{
	;
	;
}


if(exp)
{

}
else	// exp == 0
{

}
------------------------
if(1)
	;
else	//2
	;


if(1)
	;
else if(2)
		;
	  else
	  	error;



*/

int main()
{

	int a = 1,b = 1,c = 2;

	if(a == b)
	{
		if(b == c)
			printf("a == b == c\n");
	}	
	else
		printf("a != b\n");





/*
	int a = 8,b = 9,c = 0;

	if(a > b && b <= 0)
		c = 100;

	printf("c = %d\n",c);

	if(a++ >= b && !b-- || c != 0)
		printf("1\n");
	else
		printf("2\n");
*/

	exit(0);
}










