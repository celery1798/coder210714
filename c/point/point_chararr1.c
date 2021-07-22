#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *p = "world";
	char str[] = "hello";

//T	strcpy(str,p);
//F	strcpy(p,str);

	puts(p);
	puts(str);



/*
	printf("sizeof(p) = %ld\n",sizeof(p));
	printf("sizeof(str) = %ld\n\n",sizeof(str));

	printf("strlen(p) = %ld\n",strlen(p));
	printf("strlen(str) = %ld\n\n",strlen(str));

	puts(p);
	puts(str);
*/
	exit(0);
}

