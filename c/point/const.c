#include <stdio.h>
#include <stdlib.h>

/*
	const  常量化  保护

	int const i;
	const int i;

	const int *p;
	int const *p;
	int * const p;
	
	const int *const p;
*/

int main()
{
	int i = 1,j = 10;
    const int * const p = &i;

//F	*p = 100;
//F    p = &j;

    printf("%d\n",*p);




/*
	int i = 1,j = 10;
    int * const p = &i;

//T	*p = 100;
	p = &j;

	printf("%d\n",*p);
*/



/*
	int i = 1,j = 10;
	const int *p = &i;

//F	*p = 100;
	p = &j;

	printf("%d\n",*p);
*/





/*
	const float f = 3.14;

	f = 300;

	printf("%f\n",f);
*/	


	exit(0);
}

