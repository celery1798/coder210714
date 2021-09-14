#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TTY1	"/dev/tty11"
#define TTY2	"/dev/tty12"
#define TTY3	"/dev/tty9"
#define TTY4	"/dev/tty10"

int main()
{
	int fd1,fd2;

	fd1 = open(TTY1,O_RDWR|O_NONBLOCK);
	if(fd1 < 0)
	{
		perror("open()");
		exit(1);
	}
	write(fd1,"TTY1\n",5);

	fd2 = open(TTY2,O_RDWR);
	if(fd2 < 0)
	{
		perror("fopen()");
		exit(1);
	}
	write(fd2,"TTY2\n",5);

	int job1;
	job1 = rel_addjob(fd1,fd2);
	if()
	{


	}


	fd3 = open(TTY3,O_RDWR|O_NONBLOCK);
	if(fd3 < 0)
	{
		perror("open()");
		exit(1);
	}
	write(fd3,"TTY3\n",5);

	fd4 = open(TTY4,O_RDWR);
	if(fd4 < 0)
	{
		perror("fopen()");
		exit(1);
	}
	write(fd4,"TTY4\n",5);

	int job2;
	job2 = rel_addjob(fd3,fd4);
	if()
	{


	}


	struct rel_stat_st jobstat;
	
	while(1)
	{
		rel_statjob(job1,&jobstat);
		printf("[%d]1->2:%d\t2->1%d\n",job1,jobstat.count12,jobstat.count21);
		rel_statjob(job2,&jobstat);
		printf("[%d]1->2:%d\t2->1%d\n",job2,jobstat.count12,jobstat.count21);
		sleep(1);
	}


	close(fd2);
	close(fd1);
	//....

	exit(0);
}



