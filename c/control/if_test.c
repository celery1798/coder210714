#include <stdio.h>
#include <stdlib.h>

void leapyear()
{
	int year;

	scanf("%d",&year);

	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		printf("%d is a leap year.\n",year);

}

void score()
{
	int s;

	scanf("%d",&s);

	if(s > 100 || s < 0)
	{
		printf("Input error.\n");
		return ;
	}

	// [0,100]
	
	if(s >= 90)
		printf("A\n");
	else	// s < 90
	{
		if(s >= 80)
			printf("B\n");
		else
		{
			if(s >= 70)
				printf("C\n");
			else
			{
				if(s >= 60)
					printf("D\n");
				else
					printf("E\n");
			}
		}

	}	



	/*
	if(s <= 100 && s >= 90)
		printf("A\n");
	if(s < 90 && s >= 80)
		printf("B\n");
	if(s < 80 && s >= 70)
		printf("C\n");
	if(s < 70 && s >= 60)
		printf("D\n");
	if(s < 60)
		printf("E\n");
	*/
}


int main()
{

//	leapyear();
	score();

	exit(0);
}









