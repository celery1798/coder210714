#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#include "mytbf.h"

#define SIGWAKEUP	SIGUSR1


struct mytbf_st
{
	int cps;
	int burst;
	int token;
	int pos;
};

typedef void (*sighandler_t)(int);

static struct mytbf_st *job[MYTBF_MAX];
static int inited = 1;
static sighandler_t alrm_handler_save;

static void usr1_handler(int s)
{
	return;
}

static void alrm_handler(int s)
{
	int i;
	alarm(1);

	for(i = 0 ; i < MYTBF_MAX; i++)
	{
		if(job[i] != NULL)
		{
			job[i]->token += job[i]->cps;
			if(job[i]->token > job[i]->burst)
				job[i]->token  = job[i]->burst;
		}
	}
}

static void module_unload(void)
{
	int i;

	alarm(0);
	signal(SIGALRM,alrm_handler_save );
	for(i = 0 ; i < MYTBF_MAX; i++)
		free(job[i]);
}

static void module_load(void)
{
	signal(SIGWAKEUP,usr1_handler);

	alrm_handler_save = signal(SIGALRM,alrm_handler);
	alarm(1);
	atexit(module_unload);
}

static int get_free_pos()
{
	int i;

	for(i = 0 ; i < MYTBF_MAX; i++)
		if(job[i] == NULL)
			return i;
	return -1;
}


mytbf_t *mytbf_create(int cps,int burst)
{
	struct mytbf_st *me;
	int pos;

	if(inited)
	{
		module_load();
		inited= 0;
	}

	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;

	me->cps = cps;
	me->burst = burst;
	me->token = 0;

	pos = get_free_pos();	
	if(pos < 0)
	{
		free(me);
		return NULL;
	}
	me->pos = pos;
	job[pos] = me;

	return me;
}

static int min(int a,int b)
{
	if(a < b)
		return a;
	return b;
}

int mytbf_fetchtoken(mytbf_t *ptr, int n)
{
	struct mytbf_st *me = ptr;
	int size;

	if(n < 0)
		return -EINVAL;

	while(me->token <= 0)
		pause();

	size = min(me->token, n);	
	me->token -= size;
	return size;
}

int mytbf_returntoken(mytbf_t *ptr,int n)
{
	struct mytbf_st *me = ptr;
	
	if(n < 0)
		return -1;

	me->token += n;
	if(me->token > me->burst)
		me->token = me->burst;
	raise(SIGWAKEUP);

	return 0;
}

void mytbf_destroy(mytbf_t *ptr)
{
	struct mytbf_st *me = ptr;

	job[me->pos] = NULL;
	free(ptr);

}




