#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char *name[] = {"Follow Me","BASIC","Great Wall","Computer","Python"};
	int i,j,k;
	char *tmp = NULL;	// void *tmp = NULL;

	//sort
	for(i = 0 ; i < 4; i++)
	{
		k = i;
		for(j = i+1; j < 5;j++)
		{
			if(strcmp(name[k],name[j]) > 0)
				k = j;
		}
		if(k != i)
		{
			tmp = name[i];
			name[i] = name[k];
			name[k] = tmp;
		}
	}

	for(i = 0 ; i < 5; i++)
		puts(name[i]);


	exit(0);
}

