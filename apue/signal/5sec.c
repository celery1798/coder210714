#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>


int main()
{
	long long count = 0;
	time_t end;

	end = time(NULL)+5;

	while(time(NULL) <= end)
		count++;
	
	printf("%lld\n",count);

	exit(0);
}



