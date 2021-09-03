#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define LEFT    30000000
#define RIGHT   30000200


int main()
{
	int i,j,flag;

	for(i = LEFT; i <= RIGHT; i++)
	{
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
	}
	exit(0);
}



