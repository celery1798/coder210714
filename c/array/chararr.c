#include <stdio.h>
#include <stdlib.h>

//字符数组初始化2种方式：逐个字符初始化，字符串常量

int main()
{

	char str[5] = {'a','b','c','d','e'};
/*	char str1[] = {'a','b','c','d','e'};
	char str2[5] = {'a','b','c'};
	char dstr[2][3] = {{'a','b','c'},{'c','d','e'}};
	char dstr1[][3] = {'a','b','c','c','d','e'};
*/
//	char sstr[6] = {"hello"}; // => 'h','e','l','l','o','\0'  
	char sstr[] = "hello";		
	int i;

//	printf("%ld\n",sizeof(sstr));
/*
	for(i = 0 ; i < sizeof(str)/sizeof(str[0]); i++)
		scanf("%c",&str[i]);

	gets(sstr);
*/
	for(i = 0 ; i < sizeof(str)/sizeof(str[0]); i++)
		printf("%c",str[i]);
	printf("\n");

	puts(sstr);
//------------------------------------------
	char buf[32];
	printf("Enter:");
//	gets(buf);
	scanf("%s",buf);
	puts(buf);




	exit(0);
}





