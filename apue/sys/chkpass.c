#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <shadow.h>


int main(int argc,char *argv[])
{
	char *inputpass;
	char *cryptedpass;
	struct spwd *shdline;

	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s username\n",argv[0]);
		exit(1);
	}
	
	inputpass = getpass("PLEASE ENTER PASSWORD:");
	/*if error*/

	shdline = getspnam(argv[1]);
	/*if error*/
	
	cryptedpass = crypt(inputpass,shdline->sp_pwdp);
	/*if error*/
	
	if(strcmp(cryptedpass,shdline->sp_pwdp) == 0)
		puts("WELCOME!");
	else
		puts("ERROR!");



	exit(0);
}



