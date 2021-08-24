#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>

int main(int argc,char *argv[])
{
	struct passwd *pwdline;

	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s file\n",argv[0]);
		exit(1);
	}
	
	
	pwdline = getpwuid(atoi(argv[1]));
	if(pwdline == NULL)
	{
		perror("getpwuid()");
		exit(1);
	}

	puts(pwdline->pw_name);

	exit(0);
}



