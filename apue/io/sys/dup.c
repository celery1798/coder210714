#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
	int fd;
//	close(1);
	fd = open("/tmp/out",O_WRONLY|O_CREAT|O_TRUNC,0600);
	if(fd < 0)
	{
		perror("open()");
		exit(1);
	}

//	close(1);
//	dup(fd);

	dup2(fd,1);

	if(fd != 1)
		close(fd);

//---------------------------------------------
	puts("Hello!");

	exit(0);
}



