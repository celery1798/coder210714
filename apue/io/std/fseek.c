#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main()
{
	FILE *fp;

	fp = fopen("tmp.log","r+");
	if(fp == NULL)
	{
		printf("fopen():%s\n",strerror(errno));
		exit(1);
	}

		
	fseek(fp,4,SEEK_SET);

	fputc('X',fp);


	fclose(fp);

	exit(0);
}



