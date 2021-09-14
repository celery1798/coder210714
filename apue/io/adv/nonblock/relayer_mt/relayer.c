#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TTY1	"/dev/tty11"
#define TTY2	"/dev/tty12"

#define BUFSIZE 1024

enum
{
	STATE_R=1,
	STATE_W,
	STATE_Ex,
	STATE_T
};

enum
{
	STATE_RUNNING=1,
	STATE_CANCELED,
	STATE_OVER
};

struct rel_fsm_st
{
	int state;
	int sfd,dfd;
	char buf[BUFSIZE];
	int len;
	int pos;
	char *errstr;
	int count;
};

struct rel_job_st
{
	int job_state;
	int fd1,fd2;
	struct rel_fsm_st fsm12,fsm21;
	
};



void fsm_driver(struct rel_fsm_st *fsm)
{
	int ret;

	switch(fsm->state)
	{
		case STATE_R:
			fsm->len = read(fsm->sfd,fsm->buf,BUFSIZE);
			if(fsm->len == 0)
				fsm->state = STATE_T;
			else
			{
				if(fsm->len < 0)
				{
					if(errno == EAGAIN)
						fsm->state = STATE_R;
					else
					{	
						fsm->errstr = "read()";
						fsm->state = STATE_Ex;
					}
				}
				else // fsm->len > 0  write
				{
					fsm->pos = 0;
					fsm->state = STATE_W;
				}
			}
			break;
		
		case STATE_W:
			ret = write(fsm->dfd,fsm->buf+fsm->pos,fsm->len);
			if(ret < 0)
			{
				if(errno == EAGAIN)
					fsm->state = STATE_W;
				else
				{
					fsm->errstr = "write()";
					fsm->state = STATE_Ex;
				}	
			}
			else
			{
				fsm->len -= ret;
				fsm->pos += ret;
				if(fsm->len == 0)
					fsm->state = STATE_R;
				else
					fsm->state = STATE_W;			
			}
			break;
		
		case STATE_Ex:
			perror(fsm->errstr);
			fsm->state = STATE_T;
			break;
		
		case STATE_T:
			//.....
			break;
		
		default:
			abort();
			break;
	}

}

void relay(int fd1,int fd2)
{
	int fd1_save,fd2_save;
	struct fsm_st fsm12,fsm21;

	fd1_save = fcntl(fd1,F_GETFL);
	fcntl(fd1,F_SETFL,fd1_save|O_NONBLOCK);
	fd2_save = fcntl(fd2,F_GETFL);
	fcntl(fd2,F_SETFL,fd2_save|O_NONBLOCK);

	fsm12.state = STATE_R;
	fsm12.sfd = fd1;
	fsm12.dfd = fd2;

	fsm21.state = STATE_R;
	fsm21.sfd = fd2;
	fsm21.dfd = fd1;

	while(fsm12.state != STATE_T || fsm21.state != STATE_T)
	{
		fsm_driver(&fsm12);	
		fsm_driver(&fsm21);	
	}

	fcntl(fd1,F_SETFL,fd1_save);
	fcntl(fd2,F_SETFL,fd2_save);

}



