#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LEFT    30000000
#define RIGHT   30000200


int main()
{
	pid_t pid;
	int i,j,flag;

	for(i = LEFT; i <= RIGHT; i++)
	{
		pid = fork();
		if(pid < 0)
		{
			perror("fork()");
			exit(1);
		}
		if(pid == 0)
		{
			flag = 1;
			for(j = 2; j < i/2 ;j++)
			{
				if(i % j == 0)
				{
					flag = 0;
					break;
				}
			}
			if(flag)
				printf("%d is a primer.\n",i);
			exit(0);
		}
	}

	int st;
	for(i = LEFT; i <= RIGHT; i++)
		wait(NULL);
	/*
	{
		wait(&st);
		if(WIFEXITED(st))
			printf("%d\n",WEXITSTATUS(st));
	
	}
	*/
	exit(0);
}



