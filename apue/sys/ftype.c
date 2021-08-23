#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int  ftype(const char *fname)
{
	struct stat statres;

	if(stat(fname,&statres) < 0)
	{
		perror("stat()");
		exit(1);
	}

	if(S_ISREG(statres.st_mode))
		return '-';
	else if(S_ISDIR(statres.st_mode))
			return 'd';
		else 
			return '?';
}

int main(int argc,char *argv[])
{

	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s file\n",argv[0]);
		exit(1);
	}
	
	
	printf("%c\n",ftype(argv[1]));



	exit(0);
}



