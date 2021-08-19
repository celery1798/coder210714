#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main()
{
	FILE *fp;

	fp = fopen("tmp.log","w");
//	fp = fopen("/etc/shadow","r");
	if(fp == NULL)
	{
//		printf("fopen failed.errno = %d\n",errno);
//		perror("fopen()");
		printf("fopen():%s\n",strerror(errno));
		exit(1);
	}

	puts("OK!");

	fclose(fp);

	exit(0);
}



