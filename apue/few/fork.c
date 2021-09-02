#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*
不要假设或猜测父子进程谁先被调度,这取决于调度器的调度策略

*/

int main()
{
	pid_t pid;

	printf("[%d]:Begin!\n",getpid());

	fflush(NULL);	/*!!!*/

	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0)		//child
	{
		printf("[%d]:Child is working.\n",getpid());
	}
	else				//parent
	{
		printf("[%d]:Parent is working.\n",getpid());
	}

	printf("[%d]:End!\n",getpid());

//	sleep(1000);

	exit(0);
}



