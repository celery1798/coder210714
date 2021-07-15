#include <stdio.h>
#include <stdlib.h>

void sayhi()
{
	printf("HI\n");
}

void func()
{
	int i = 1;
	static int j = 1;
	i = i+1;
	j = j+1;
	printf("i: %p --> %d\n",&i,i);
	printf("j: %p --> %d\n",&j,j);
}


int main()
{

//	sayhi();
	func();
	func();
	func();


	exit(0);
}


/*

extern int j;

int main()
{

	static int i = 0;
	int j = 20;

	{
		int j = 1;

		printf("i = %d\n",i);
	}
	printf("j = %d\n",j);

	exit(0);
}

int j = 300;



*/
