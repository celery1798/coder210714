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

int main()
{
	int i = 3;
	int j = 5;

	printf("hello1111\n");
	printf("hello2222\n");
	func4();
	printf("hello3333\n");
	printf("hello4444\n");
	printf("hello5555\n");
	exit(0);
}






