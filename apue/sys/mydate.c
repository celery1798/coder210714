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

int main(int argc,char *argv[])
{
	time_t stamp;
	struct tm *tm;
	char fmtstr[TIMESTRSIZE] = {'\0'};
	char timestr[TIMESTRSIZE];
	int ch;
	FILE *fp = stdout;

	stamp = time(NULL);
	tm = localtime(&stamp);

	while(1)
	{
		ch = getopt(argc,argv,"-y:mdH:MS");
		if(ch < 0)
			break;
		switch(ch)
		{
			case 1:
				if(fp == stdout)
				{
					fp = fopen(argv[optind-1],"w");
					if(fp == NULL)
					{
						perror("fopen()");
						fp = stdout;
					}
				}
				break;
			case 'y':
				if(strcmp(optarg,"2") == 0)
					strncat(fmtstr,"%y ",TIMESTRSIZE);
				else if(strcmp(optarg,"4") == 0)
						strncat(fmtstr,"%Y ",TIMESTRSIZE);
					 else
					 	fprintf(stderr,"Invalid argument of -y\n");
				break;
			case 'm':
				strncat(fmtstr,"%m ",TIMESTRSIZE);
				break;
			case 'd':
				strncat(fmtstr,"%d ",TIMESTRSIZE);
				break;
			case 'H':
				if(strcmp(optarg,"12") == 0)
					strncat(fmtstr,"%I(%P) ",TIMESTRSIZE);
				else if(strcmp(optarg,"24") == 0)
					strncat(fmtstr,"%H ",TIMESTRSIZE);
				else
					fprintf(stderr,"Invalid argument of -H\n");

				break;
			case 'M':
				strncat(fmtstr,"%M ",TIMESTRSIZE);
				break;
			case 'S':
				strncat(fmtstr,"%S ",TIMESTRSIZE);
				break;
			default:
				break;
		}
	}

	strncat(fmtstr,"\n",TIMESTRSIZE);
	strftime(timestr,TIMESTRSIZE,fmtstr,tm);
	fputs(timestr,fp);

	if(fp != stdout)
		fclose(fp);

	exit(0);
}



