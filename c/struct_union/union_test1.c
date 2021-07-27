#include <stdio.h>
#include <stdlib.h>

union 
{
	struct 
	{
		char a:1;
		char b:2;
		char c:1;
	} s;
	char d;
}u;

int main()
{
	u.d = 1;
	printf("%d\n", u.s.a);

	exit(0);
}

