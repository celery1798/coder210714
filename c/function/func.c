#include <stdio.h>
#include <stdlib.h>

int print_int_val(int val);


void sayhi()
{
	printf("---WELCOME---\n");
	printf("Hello World!\n");
}


int main()
{
	int i = 3,j = -5;
	int ret;

	sayhi();

	ret = print_int_val(j);
	printf("ret = %d\n",ret);
	exit(0);
}

int print_int_val(int j)
{
	if(j < 0)
		return -1;
	printf("val = %d\n",j);
	return 0;
}




