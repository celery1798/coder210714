#include <stdio.h>
#include <stdlib.h>

#define STATE_HANGUP	20

enum
{
	STATE_RUNNING=5,
	STATE_STOP= 18,
	STATE_ERROR,
	STATE_ZONBLE=33
};


int main()
{

	printf("%d\n",STATE_RUNNING);
	printf("%d\n",STATE_STOP);
	printf("%d\n",STATE_ERROR);


	int state;

	switch(state)
	{
		case STATE_RUNNING:
			break;
		case STATE_STOP:
			break;

		case STATE_HANGUP:
			break;


	
	}



	exit(0);
}

