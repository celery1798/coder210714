#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define CPS			10
#define BUFSIZE 	CPS
#define BURST		100

static volatile int token = 0;

void alrm_handler(int s)
{
	token ++;
	if(token > BURST)
		token = BURST;
}
	
int main(int argc,char *argv[])
{
	int sfd,dfd = 1;
	char buf[BUFSIZE];
	ssize_t len,ret,pos;
	struct itimerval itv;
	struct sigaction sa;

	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s srcfile\n",argv[0]);
		exit(1);
	}

//	signal(SIGALRM,alrm_handler);

	sa.sa_handler = alrm_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	if(sigaction(SIGALRM,&sa,NULL) < 0)
	{
		perror("sigaction()");
		exit(1);
	}



	itv.it_interval.tv_sec = 1;
	itv.it_interval.tv_usec = 0;
	itv.it_value.tv_sec = 1;
	itv.it_value.tv_usec = 0;

	if(setitimer(ITIMER_REAL,&itv,NULL) < 0)
	{
		perror("setitimer()");
		exit(1);
	}


	do
	{
		sfd = open(argv[1],O_RDONLY);
		if(sfd < 0)
		{
			if(errno != EINTR)
			{
				perror("open()");
				exit(1);
			}
		}
	}while(sfd < 0);

	while(1)
	{
		while(token <= 0)
			pause();
		token --;	
		
		while((len = read(sfd,buf,BUFSIZE)) < 0)
		{
			if(errno == EINTR)
				continue;
			perror("read()");
			exit(1);
		}

		if(len == 0)
			break;

		//len > 0
		pos = 0;
		while(len > 0)
		{
			ret = write(dfd,buf+pos,len);	
			if(ret < 0)
			{	
				if(errno == EINTR)
					continue;
				perror("write()");
				exit(1);
			}
			pos += ret;
			len -= ret;
		}

	}

	close(sfd);


	exit(0);
}



