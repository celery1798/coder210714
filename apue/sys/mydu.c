#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <glob.h> 
#include <stdint.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#define PATHSIZE	1024

int path_no_loop(const char *path)
{// ../io/..a   /etc/.   mydir/..  /etc/a/b/c/d/..a
	char *pos;

	pos = strrchr(path,'/');

	if(strcmp(pos+1,".") == 0 || strcmp(pos+1,"..") == 0)
		return 0;
	return 1;
}

int64_t mydu(const char *path)
{
	int i;
	struct stat statres;
	char nextpath[PATHSIZE];
	glob_t globres;
	int64_t sum = 0;

	if(lstat(path,&statres) < 0)
	{
		perror("lstat()");
		exit(1);
	}

	// not a dir
	if(!S_ISDIR(statres.st_mode))
		return statres.st_blocks;

	// is a dir   path =  "../io"  "/etc"  "mydir"

	strncpy(nextpath,path,PATHSIZE);
	strncat(nextpath,"/*",PATHSIZE);
	glob(nextpath,0,NULL,&globres);

	strncpy(nextpath,path,PATHSIZE);
	strncat(nextpath,"/.*",PATHSIZE);
	glob(nextpath,GLOB_APPEND,NULL,&globres);

	for(i = 0 ; i < globres.gl_pathc; i++)
	{
		if(path_no_loop(globres.gl_pathv[i]))
			sum += mydu(globres.gl_pathv[i]);
	}
	sum += statres.st_blocks;
	
	return sum;
}

int main(int argc,char *argv[])
{
	glob_t globres;
	int i,err;

	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s file\n",argv[0]);
		exit(1);
	}

	printf("TOTAL:%lld\n",(long long)mydu(argv[1])/2);

	exit(0);
}



