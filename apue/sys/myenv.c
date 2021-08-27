#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

extern char **environ;

int main()
{
	int i;

	for(i = 0 ; environ[i] != NULL; i++)
		puts(environ[i]);

	printf("-----------------\n");

	puts(getenv("PWD"));

	exit(0);
}



