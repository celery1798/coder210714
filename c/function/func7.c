#include <stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[])  //char **argv
{
	int i;
		
	printf("argc = %d\n\n",argc);

//	for(i = 0 ; i < argc  ; i++)
	for(i = 0 ; argv[i] != NULL  ; i++)
		puts(argv[i]);

	exit(0);
}

