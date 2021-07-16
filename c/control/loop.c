#include <stdio.h>
#include <stdlib.h>

/*	初始化， 循环成立／不成立 ，步长变化*/
// while   do-while   for      if-goto
int main()
{
	int i = 1,sum = 0;


loop:
	sum += i;
	i++;
	if(i <= 100)
		goto loop;


/*

	for(   ; i <= 100; i++)
	{
		sum += i;
	}
*/


/*
	do
	{	
		sum += i;
		i++;
	}while(i <= 100);
*/




/*
	while(i <= 100)
	{
		sum += i; 
		i++;
	}
*/
	printf("sum = %d\n",sum);
	exit(0);
}

