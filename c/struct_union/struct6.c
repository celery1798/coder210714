#include <stdio.h>
#include <stdlib.h>


struct node_st
{
	int i;
	char ch[5];
	char ch1;
	float f;
};

int main()
{
	struct node_st a; //	= {4,'y',8.9,'x'};

	printf("%ld\n",sizeof(a));
/*
	printf("%p -> %d\n",&a.i, a.i);
	printf("%p -> %c\n",&a.ch, a.ch);
	printf("%p -> %f\n",&a.f, a.f);
	printf("%p -> %c\n",&a.ch1, a.ch1);
*/
	exit(0);
}

