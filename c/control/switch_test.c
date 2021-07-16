#include <stdio.h>
#include <stdlib.h>


int main()
{

	int s;

	scanf("%d",&s);

	if(s > 100 || s < 0)
	{
		printf("Input error.\n");
		return 1;
	}

	switch(s/10)
	{
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		default:
			printf("E\n");
			break;
	}

	exit(0);
}

