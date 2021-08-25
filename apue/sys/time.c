#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define FNAME	"time.log"
#define BUFSIZE	128

int main()
{
	FILE *fp;
	time_t stamp;
	struct tm *tm;
	char buf[BUFSIZE];
	int no = 0;

	fp = fopen(FNAME,"a+");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}

	while(fgets(buf,BUFSIZE,fp) != NULL)
		no++;

	while(1)
	{
		time(&stamp);
		tm = localtime(&stamp);
		fprintf(fp,"%-4d%d-%d-%d %d:%d:%d\n",++no,tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday, tm->tm_hour,tm->tm_min , tm->tm_sec);
		fflush(fp);  //fflush(NULL);
		sleep(1);
	}

	fclose(fp);

	exit(0);
}



