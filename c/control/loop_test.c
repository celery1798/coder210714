#include <stdio.h>
#include <stdlib.h>


void func4()//fibonacci
{
	long long int i,f1 = 1,f2 = 1;

	for(i = 1 ; i <= 20; i++)
	{
		printf("%10lld%10lld",f1,f2);
		if(i % 2 == 0)
			printf("\n");
		f1 += f2;
		f2 += f1;
	}
}	

void func5()
{
	int i,j;

	for(i = 1; i <= 9 ; i++)
	{
		for(j = 1 ; j <= i ; j++)
			printf("%2d*%-2d=%-3d",i,j,i * j);
		printf("\n");
//			printf((i==j) ? "%4d\n" : "%4d", i*j);
	}

}

void func6()
{
	int x,y,z;

	for(x = 0 ; x < 20; x++)
	{
		for(y = 0 ; y < 33; y++)
	    {
			z = 100-x-y;
			if(z % 3 == 0 && 5*x + 3*y + z/3 == 100)
				printf("%d %d %d\n",x,y,z);
		}
	}

}

#define LINE	6

void func9()
{
	char ch = 'F';
	int i,j;

	for(i = 0 ; i < LINE; i++)
	{
		for(j = 0; j <= i-1; j++)
			putchar('_');

		for(j = 0,ch = 'F' ; j <= i; j++,ch--)
			putchar(ch);
		putchar('\n');
	}
}

#define LEFT	30000000
#define RIGHT	30000200

void func_primer(void)
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

}

#define MAX		100
#define MIN		0


void func_max_min()
{
	int score,min = MAX,max = MIN;
	
	while(scanf("%d",&score) == 1 && score != -1)
	{
		if(score > MAX || score < MIN)
		{
			printf("Try again:");
			continue;
		}
	
		min = score < min ? score : min;
		max = score > max ? score : max;

	}
	printf("min = %d\tmax = %d\n",min,max);

}


int main()
{
//	func4();
//	func5();
//	func6();
//	func9();
//	func_primer();
	func_max_min();


	exit(0);
}






