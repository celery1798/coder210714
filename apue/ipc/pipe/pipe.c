#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>


#define BUFSIZE	128

int main(int argc,char *argv[])
{
	pid_t pid;
	int pd[2],len;
	char buf[BUFSIZE];

	if(pipe(pd) < 0)
	{
		perror("pipe()");
		exit(1);
	}

	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0) // child read
	{
		close(pd[1]);
		len = read(pd[0],buf,BUFSIZE);
		/*if error*/
		buf[len] = '\0';
		puts(buf);
		close(pd[0]);
		exit(0);
	}
	else			//parent write
	{
		close(pd[0]);
		write(pd[1],"HELLO!",6);
		close(pd[1]);
		wait(NULL);
		exit(0);
	}


	exit(0);
}



