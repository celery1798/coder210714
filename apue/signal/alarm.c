#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alrm_handler(int s)
{
	alarm(2);
	write(1,"!",1);
}


int main()
{
	signal(SIGALRM,alrm_handler);

	alarm(5);
//	alarm(10);
//	alarm(1);


	while(1)
	{	
		write(1,"*",1);
		sleep(1);
	}
	//	pause();

	exit(0);
}



