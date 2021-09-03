#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <glob.h>
#include <string.h>

struct cmd_st
{
	glob_t globres;
	//......
};

#define DELIMS		" \n\t"

void prompt(void)
{
	printf("mysh-0.1$ ");	
}

void parse_line(char *line, struct cmd_st *res)
{//"ls -l    /etc     -i  " -> "ls" "-l" "/etc" "-i"
	char *tok;
	int flag = 0;

	while(1)
	{
		tok = strsep(&line,DELIMS);
		if(tok == NULL)
			break;
		if(tok[0] == '\0')
			continue;

		glob(tok, GLOB_NOCHECK|GLOB_APPEND*flag ,NULL, &res->globres);
		flag = 1;
	}
}

int main()
{
	pid_t pid;
	char *linebuf = NULL;
	size_t linesize = 0;
	struct cmd_st cmd;

	while(1)
	{
		prompt();

		if(getline(&linebuf,&linesize,stdin) < 0)
			break;
	
		//分析命令行 "ls -l /etc  -i  " -> "ls" "-l" "/etc" "-i"
		parse_line(linebuf,&cmd);

		if( 0 /*内部命令*/)
		{
		
		}
		else		//外部命令
		{
			pid = fork();
			if(pid < 0)
			{
				perror("fork()");
				exit(1);
			}
			if(pid == 0)
			{
				execvp(cmd.globres.gl_pathv[0] ,cmd.globres.gl_pathv);
				perror("execvp()");
				exit(1);
			}

			wait(NULL);
		}
	}

//	globfree(&globres);

	exit(0);
}



