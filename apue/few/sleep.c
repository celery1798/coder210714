#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/*sleep 100*/

int main()
{
	pid_t pid;

	printf("[%d]:Begin!\n",getpid());

	fflush(NULL);	/*!!!*/
	
	pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(0);
	}
	if(pid == 0)
	{
		execl("/bin/sleep","httpd","1000",NULL);	
		perror("execl()");
		exit(1);
	}
	
	wait(NULL);

	printf("[%d]:End!\n",getpid());


	exit(0);
}



