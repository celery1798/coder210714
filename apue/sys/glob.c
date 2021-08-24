#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <glob.h> 

#define PAT		"/etc/a*.conf"

int myerrfun(const char *epath, int eerrno)
{
	fprintf(stderr,"%s:%s\n",epath,strerror(eerrno);
}

int main()
{
	glob_t globres;
	int i,err;

	err = glob(PAT, 0, NULL/*myerrfun*/, &globres);
	if(err)
	{
		printf("ERROR CODE:%d\n",err);
		exit(1);
	}

	for(i = 0 ; i < globres.gl_pathc ; i++)
	{
		puts(globres.gl_pathv[i]);
	}
	
	globfree(&globres);


	exit(0);
}



