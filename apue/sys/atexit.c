#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

void f1()
{
	puts("f1() is working.");
}
void f2()
{
	puts("f2() is working.");
}
void f3()
{
	puts("f3() is working.");
}

int main()
{

	puts("Begin!");

	atexit(f1);
	atexit(f2);
	atexit(f3);
	
	puts("End!");

	exit(0);
}



