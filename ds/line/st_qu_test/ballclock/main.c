#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "stack.h"

int check(QUEUE *qu)
{// 1 2 3 4 5 ... 27   i  < i+1
	int i;

	i = (qu->front+1)%DATAMAX;

	while(i != qu->tail)
	{
		if(qu->data[i] > qu->data[(i+1)%DATAMAX])
			return 0;
		i = (i+1)%DATAMAX;
	}
	return 1;
}

int main()
{
	STACK *st_hour,*st_fivemin,*st_min;
	QUEUE *qu;
	int time = 0,i,ball,tmp;

	st_hour = stack_create();
	/*if error*/
	st_fivemin = stack_create();
	/*if error*/
	st_min = stack_create();
	/*if error*/

	qu = queue_create();
	/*if error*/
	
	for(i = 1; i <= 27; i++)
		queue_en(qu,&i);
	queue_display(qu);

	while(1)
	{
		queue_de(qu,&ball);	
		/*if error*/
		
		time++;

		if(st_min->top != 3)  // 1min stack is not full
		{
			stack_push(st_min,&ball);	
		}
		else	// 1min stack  is full
		{
			while(!stack_isempty(st_min))
			{
				stack_pop(st_min,&tmp);
				queue_en(qu,&tmp);
			}
		
			if(st_fivemin->top != 10)	//5min st  is not full
			{
				stack_push(st_fivemin,&ball);
			}
			else// 5min is full
			{
				while(!stack_isempty(st_fivemin))
				{
					stack_pop(st_fivemin,&tmp);
					queue_en(qu,&tmp);
				}

				if(st_hour->top != 10)
					stack_push(st_hour,&ball);
				else	// hour st is full
				{
					while(!stack_isempty(st_hour))
					{
						stack_pop(st_hour,&tmp);
						queue_en(qu,&tmp);
					}
					queue_en(qu,&ball);
					// 27 balls
					if(check(qu))
						break;

				}
			
			}
		
		}
	}


	printf("%d\n",time);

	queue_display(qu);

	queue_destroy(qu);
	stack_destroy(st_hour);
	stack_destroy(st_fivemin);
	stack_destroy(st_min);


	exit(0);
}



