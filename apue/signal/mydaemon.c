#include <stdio.h>
#include <signal.h>
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

static FILE *fp;

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


}

void deamon_exit(int s)
{

	fclose(fp);
	closelog();

	exit(0);
}

int main()
{
	struct sigaction sa;
	
//	signal(SIGINT, deamon_exit);
//	signal(SIGQUIT, deamon_exit);
//	signal(SIGTERM, deamon_exit);

	sa.sa_handler = deamon_exit;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGQUIT);
	sigaddset(&sa.sa_mask, SIGTERM);
	sigaddset(&sa.sa_mask, SIGINT);
	sa.sa_flags = 0;

	sigaction(SIGINT,&sa,NULL);
	/*if error*/
	sigaction(SIGQUIT,&sa,NULL);
	/*if error*/
	sigaction(SIGTERM,&sa,NULL);
	/*if error*/





	openlog("mydaemon",LOG_PID,LOG_DAEMON);

	daemonize();

	daemon_job();


	exit(0);
}



