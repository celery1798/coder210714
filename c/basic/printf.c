#include <stdio.h>
#include <stdlib.h>

/*
printf("format",var...);

format:%[修饰符]格式符
*/


int main()
{
	int i = 1234;
	float f = 3.333;
	char ch = 'x';
	double d = 6.666;
	int ret;

	ret = printf("Hello World!\n");
	printf("RET:%d\n",ret);

	printf("%d %.1f %c %.2lf %s\n",i,f,ch,d,"hello");
	
	printf("---i = %2d---\n",i);
	printf("%.3s\n","1234567890");

	printf("Hello!\n");
	
	//exit(0);
}












