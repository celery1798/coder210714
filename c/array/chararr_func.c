#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*strlen  strcpy  strncpy  strcmp  strncmp  strcat  strncat  */

int main()
{
	char str[] = "abcdb11111";
	char str1[] = "abcda11111";

	printf("%d\n",strcmp(str1,str));
	printf("%d\n",strncmp(str1,str,7));





/*
	char str[128];
	char h[] = "hello",s[] = " ",w[] = "world";

	strcpy(str,h);
	strcat(str,s);
	strcat(str,w);

	puts(str);
*/


//	printf("%ld\n",sizeof(str));
//	printf("%ld\n",strlen(str));
	
/*
	char str[32] = "hello";
	char str1[12];
	printf("str = %p\n",str);
	printf("str1 = %p\n",str1);

	strcpy(str1, str);
	
	puts(str);
	puts(str1);
*/
	exit(0);
}




