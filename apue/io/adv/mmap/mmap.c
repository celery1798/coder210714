#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>


int main(int argc,char *argv[])
{
	int sfd;
	struct stat statres;
	char *str;
	int i,count = 0;

	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s srcfile\n",argv[0]);
		exit(1);
	}

	sfd = open(argv[1],O_RDONLY);
	if(sfd < 0)
	{
		perror("open()");
		exit(1);
	}

	if(fstat(sfd,&statres) < 0)
	{
		perror("fstat()");
		exit(1);
	}
	
	str = mmap(NULL,statres.st_size,PROT_READ,MAP_SHARED,sfd,0);
	if(str == MAP_FAILED)
	{
		perror("mmap()");
		exit(1);
	}
	close(sfd);

	for(i = 0 ; i < statres.st_size ; i++)
		if(str[i] == 'a')
			count++;
	printf("%d\n",count);

	munmap(str,statres.st_size);

//	close(sfd);

	exit(0);
}



