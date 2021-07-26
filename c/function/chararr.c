#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrcpy(char *dest, const char *src)
{
	int i;

	for(i = 0 ; (dest[i] = src[i] ) != '\0'; i++)
		;
	return dest;
}

int main()
{
	char str[] =  "hello";
	char str1[32];
		
//	strcpy(str1,str);
	mystrcpy(str1,str);

	puts(str1);

	exit(0);
}

