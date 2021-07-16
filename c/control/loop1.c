#include <stdio.h>
#include <stdlib.h>

/*	初始化， 循环成立／不成立 ，步长变化*/
// while   do-while   for      if-goto
int main()
{

	int i,j ;

	for(j = 0 ; j < 3; j++)
	{
		for(i = 0 ; i < 5; i++)
		{
			printf("x");
		}
		printf("\n");
	}









/*
	int i = 4,j = 10;


	while(i < j)
	{
		printf("AA%d\n",i);
		if(i % 3 == 0)
		{
			i++;
			continue;
		}	
		printf("BB%d\n\n",i);
		i++;
	}

	printf("CC\n");
*/
	exit(0);
}

