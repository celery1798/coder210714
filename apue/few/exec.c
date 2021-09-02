#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*date +%s*/

int main()
{

	printf("[%d]:Begin!\n",getpid());

	fflush(NULL);	/*!!!*/
	
	execl("/bin/date","date","+%s",NULL);	

	printf("[%d]:End!\n",getpid());


	exit(0);
}



