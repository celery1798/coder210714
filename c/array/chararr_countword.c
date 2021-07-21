#include <stdio.h>
#include <stdlib.h>

//hello   world   123      456   

int main()
{
	char buf[128];
	int i = 0,count = 0,flag = 0;
	
	gets(buf);

	for(; buf[i] != '\0'; i++)
	{
		if(buf[i] == ' ')
		{
			flag = 0;
		}
		else	// char
		{
			if(flag == 0)
			{
				flag = 1;
				count++;
			}	
		}
	}
	printf("WORD:%d\n",count);


	exit(0);
}

