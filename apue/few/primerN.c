#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LEFT    30000000
#define RIGHT   30000200

#define N		3

int main()
{
	pid_t pid;
	int i,j,flag,n;


	for(n = 0 ; n < N; n++)
	{	
		pid = fork();
		if(pid < 0)
		{
			perror("fork()");
			exit(1);
		}
		if(pid == 0)
		{
			for(i = LEFT+n; i <= RIGHT; i+=N)
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
					printf("[%d]%d is a primer.\n",n,i);
			}
			exit(0);
		}
	}


	for(n = 0 ; n < N; n++)
		wait(NULL);


	exit(0);
}


