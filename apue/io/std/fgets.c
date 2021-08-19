#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*
fgets函数有两种情况可以导致其读取行为正常结束:
1读到了size-1个字节 
2读到了'\n'
*/
#define BUFSIZE		5

int main()
{
	FILE *fp;
	char buf[BUFSIZE];

	fp = fopen("tmp.log","r");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}

	
	fgets(buf,BUFSIZE,fp);

	puts(buf);

	fgets(buf,BUFSIZE,fp);

	puts(buf);

	fclose(fp);

	exit(0);
}



