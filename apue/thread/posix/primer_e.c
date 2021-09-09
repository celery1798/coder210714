#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>

#define LEFT    30000000
#define RIGHT   30000200

#define THRNUM	(RIGHT-LEFT+1)

struct thr_arg_st
{
	int num;
};

void *thr_primer(void *p)
{
	int i,j,flag;
	struct thr_arg_st *q = p;

	i = q->num;

//	free(p);

	flag = 1;
	for(j = 2; j < i/2 ;j++)
	{
		if(i % j == 0)
		{
			flag = 0;
			break;
		}
	}
	if(flag)
		printf("%d is a primer.\n",i);

	pthread_exit(p);
}


int main()
{
	int i,err;
	pthread_t tid[THRNUM];
	struct thr_arg_st *p;

	for(i = LEFT; i <= RIGHT; i++)
	{
		p = malloc(sizeof(*p));
		p->num = i;

		err = pthread_create(tid+(i-LEFT), NULL, thr_primer, p);
		if(err)
		{
			fprintf(stderr,"pthread_create():%s\n",strerror(err));
			exit(1);
		}
	}

	void *ptr;
	for(i = LEFT; i <= RIGHT; i++)
	{
		pthread_join(tid[i-LEFT],&ptr);
		free(ptr);
	}
	exit(0);

}




