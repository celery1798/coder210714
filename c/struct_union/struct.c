#include <stdio.h>
#include <stdlib.h>


//struct				// node_st
struct node_st
{
	int i;
	float f;
	char ch;
}b = {4,8.9,'x'};

int main()
{
	struct node_st a = {4,8.9,'x'};

//	printf("%ld\n",sizeof(a));
/*
	a.i = 4;
	a.f = 4.8;
	a.ch = 'a';
*/
	printf("%d, %f, %c\n",a.i , a.f, a.ch);

	exit(0);
}

