#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <glob.h> 

#define PAT		"abcd"

int main()
{
	glob_t globres;
	int i,err;

	err = glob(PAT, GLOB_NOCHECK, NULL, &globres);
	if(err)
	{
		printf("ERROR CODE:%d\n",err);
		exit(1);
	}

	printf("globres.gl_pathc = %ld\n",globres.gl_pathc);



	for(i = 0 ; i < globres.gl_pathc ; i++)
	{
		puts(globres.gl_pathv[i]);
	}
	
	globfree(&globres);


	exit(0);
}



