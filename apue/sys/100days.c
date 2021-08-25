#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define TIMESTRSIZE		128

int main()
{
	time_t stamp;
	struct tm *tm;
	char timestr[TIMESTRSIZE];

	stamp = time(NULL);
	tm = localtime(&stamp);
	strftime(timestr,TIMESTRSIZE,"Now:%Y-%m-%d",tm);
	puts(timestr);

	tm->tm_mday += 100;
	mktime(tm);
	strftime(timestr,TIMESTRSIZE,"100 days later:%Y-%m-%d",tm);
	puts(timestr);


	exit(0);
}



