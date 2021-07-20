#include <stdio.h>
#include <stdlib.h>

#define N	10

void sort_bubble()
{
	int a[N] = {5,4,3,7,0,8,2,9,1,6};
	int i,j,t;

	for(i = 0 ; i < N ; i++)
		printf("%d ",a[i]);
	printf("\n");

	for(i = 0 ; i < N-1; i++)
	{
		for(j = 0;  j < N-1-i  ;j++)
		{
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		
		}
/*
		for(t = 0 ; t < N ; t++)
			printf("%d ",a[t]);
		printf("\n");
		
		getchar();
*/
	}

	 for(i = 0 ; i < N ; i++)
        printf("%d ",a[i]);
    printf("\n");

}

void sort_choice()
{
	int a[N] = {5,4,3,7,0,8,2,9,1,6};
    int i,j,t,m;

    for(i = 0 ; i < N ; i++)
        printf("%d ",a[i]);
    printf("\n");

	for(i = 0 ; i < N-1; i++)
	{
		t = i;
		for(j = i+1; j < N ; j++)
		{
			if(a[t] > a[j])
			{
				t = j;
			}
		}
		
		if(t != i)
		{
			m = a[t];
			a[t] = a[i];
			a[i] = m;
		}
/*
		for(t = 0 ; t < N ; t++)
            printf("%d ",a[t]);
        printf("\n");
        
        getchar();
*/
	}

	for(i = 0 ; i < N ; i++)
        printf("%d ",a[i]);
    printf("\n");

}

void num_base()
{
	int num,base;
	int a[128],i = 0;

	printf("Pleae enter for NUM:");
	scanf("%d",&num);
	printf("Pleae enter for BASE:");
	scanf("%d",&base);

	if(base != 2 && base != 8 && base != 16)
	{
		printf("ERROR!\n");
		return ;
	}

	do
	{
		a[i] = num % base;
		i++;
		num = num / base; 
	}while(num != 0);

	for(i--; i >= 0 ;i--)
	{
		if(a[i] >= 10)
			printf("%c ",a[i]-10+'A');
		else
			printf("%d ",a[i]);
	}	

	printf("\n");
}

void primer()
{
	int a[1001] = {0};
	int i,j;

	for(i = 2; i < 1001 ; i++)
	{
		if(a[i] == 0)
		{
			for(j = i+i; j < 1001 ;j += i)
				a[j] = 1;	/*!*/	
		}
	}

	for(i = 2; i < 1001; i++)
		if(!a[i])
			printf("%d ",i);
	printf("\n");

}

void array_max()
{
	int a[N] = {5,4,3,7,0,8,2,9,1,6};
    int i,pos,max;

	max = a[0];
	pos = 0;

	for(i = 0 ; i < N ;i++)
	{
		if(a[i] > max)
		{
			max = a[i];
			pos = i;
		}
	}
	printf("MAX:a[%d] = %d\n",pos,max);
}

void array_pos_insert()
{
	int a[N] = {5,4,3,7,8,2,9,1,6};
    int i,data = 100,pos = 3,j = 8;

	for(i = 0 ; i < N ; i++)
        printf("%d ",a[i]);
    printf("\n");

	while(j >= pos)
	{
		a[j+1] = a[j];
		j--;
	}

	a[pos] = data;

	for(i = 0 ; i < N ; i++)
        printf("%d ",a[i]);
    printf("\n");

}


int main()
{
	
//	sort_bubble();
//	sort_choice();
//	num_base();
//	primer();
//	array_max();
	array_pos_insert();


	exit(0);
}

