#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

static volatile int flag  = 1;

void alrm_handler(int s)
{
	flag  = 0;
}

int main()
{
	long long count = 0;
	
	signal(SIGALRM,alrm_handler);
	alarm(5);


	while(flag)
		count++;
	
	printf("%lld\n",count);

	exit(0);
}



