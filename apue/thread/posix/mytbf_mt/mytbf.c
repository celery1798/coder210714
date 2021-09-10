#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#include "mytbf.h"


struct mytbf_st
{
	int cps;
	int burst;
	int token;
	int pos;
	pthread_mutex_t mut;
};

static struct mytbf_st *job[MYTBF_MAX];
static pthread_mutex_t mut_job = PTHREAD_MUTEX_INITIALIZER;
static pthread_once_t inited = PTHREAD_ONCE_INIT;
static pthread_t tid;

static void *thr_alrm(void *p)
{
	int i;

	while(1)
	{
		pthread_mutex_lock(&mut_job);
		for(i = 0 ; i < MYTBF_MAX; i++)
		{
			if(job[i] != NULL)
			{
				pthread_mutex_lock(&job[i]->mut);
				job[i]->token += job[i]->cps;
				if(job[i]->token > job[i]->burst)
					job[i]->token  = job[i]->burst;
				pthread_mutex_unlock(&job[i]->mut);
			}
		}
		pthread_mutex_unlock(&mut_job);
		sleep(1);
	}
}

static void module_unload(void)
{
	int i;

	pthread_cancel(tid);
	pthread_join(tid,NULL);

	pthread_mutex_destroy(&mut_job);	
}

static void module_load(void)
{
	int err;

	err = pthread_create(&tid,NULL, thr_alrm, NULL);
	if(err)
	{
		fprintf(stderr,"pthread_create():%s\n",strerror(err));
		exit(1);
	}
	atexit(module_unload);
}

static int get_free_pos_unlocked()
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

	pthread_once(&inited,module_load);

	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;

	me->cps = cps;
	me->burst = burst;
	me->token = 0;
	pthread_mutex_init(&me->mut,NULL);

	pthread_mutex_lock(&mut_job);
	pos = get_free_pos_unlocked();	
	if(pos < 0)
	{
		pthread_mutex_unlock(&mut_job);
		free(me);
		return NULL;
	}
	job[pos] = me;
	pthread_mutex_unlock(&mut_job);

	me->pos = pos;

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

	pthread_mutex_lock(&me->mut);
	while(me->token <= 0)
	{
		pthread_mutex_unlock(&me->mut);
		sched_yield();
		pthread_mutex_lock(&me->mut);
	}

	size = min(me->token, n);	
	me->token -= size;
	pthread_mutex_unlock(&me->mut);

	return size;
}

int mytbf_returntoken(mytbf_t *ptr,int n)
{
	struct mytbf_st *me = ptr;
	
	if(n < 0)
		return -1;
	pthread_mutex_lock(&me->mut);
	me->token += n;
	if(me->token > me->burst)
		me->token = me->burst;
	pthread_mutex_unlock(&me->mut);

	return 0;
}

void mytbf_destroy(mytbf_t *ptr)
{
	struct mytbf_st *me = ptr;
	
	pthread_mutex_lock(&mut_job);
	job[me->pos] = NULL;
	pthread_mutex_unlock(&mut_job);

	pthread_mutex_destroy(&me->mut);
	free(ptr);

}




