#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i;
	char str[2][32] = {"hello","welcome"};
	char (*p)[32] = str;
	
	for(i = 0 ; i < 2; i++)
		puts(p[i]); 




/*
	char str[] = "hello";
	char *p = str;

	puts(p);
	puts(str);
	puts(p+3);
	puts(str+3);

*/

	exit(0);
}

