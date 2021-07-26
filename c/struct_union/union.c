#include <stdio.h>
#include <stdlib.h>


union node_st
{
	int i;			//4
	char ch;		//1
	double d;		//8
	float f;		//4
	short ch1;		//2
};

int main()
{
	union node_st a;

//	printf("%ld\n",sizeof(union node_st));
	a.i = 100;
	printf("%f\n",a.f);

	


	exit(0);
}

