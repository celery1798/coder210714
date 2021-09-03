#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>

#define FNAME	"/tmp/out"

void daemonize()
{
	pid_t pid;
	int fd;

	pid = fork();
	if(pid < 0)
	{
		syslog(LOG_ERR,"fork():%s",strerror(errno));
		exit(0);
	}
	if(pid > 0)
		exit(0);

	// child
/*
	close(0);
	close(1);
	close(2);
*/
	fd = open("/dev/null",O_RDWR);
	if(fd < 0)
	{
		syslog(LOG_WARNING,"open():%s",strerror(errno));
	}
	else
	{
		dup2(fd,0);	
		dup2(fd,1);	
		dup2(fd,2);
		if(fd > 2)
			close(fd);
	}

	setsid();

	umask(0);
	chdir("/");

}

void daemon_job(void)
{
	FILE *fp;
	int i;

	fp = fopen(FNAME,"w");	
	if(fp == NULL)
	{
		syslog(LOG_ERR ,"fopen():%s",strerror(errno));
		exit(1);
	}

	syslog(LOG_INFO,"fopen() successed.");

	for(i = 0 ; ; i++)
	{
		fprintf(fp,"%d\n",i);
		fflush(fp);
		syslog(LOG_DEBUG,"%d was printed.",i);
		sleep(1);
	}	

	fclose(fp);

}

int main()
{
	openlog("mydaemon",LOG_PID,LOG_DAEMON);

	daemonize();

	daemon_job();

	closelog();

	exit(0);
}



