#include <stdio.h>
#include <stdlib.h>

/*
scanf("format",&var...);

format:%[修饰符]格式符
*/


int main()
{
	int i = 4;
	float f = 3.333;
	char ch = 'a';
	double d = 6.666;
	int ret;

//	printf("%d\n",ch + i);


	ret = scanf("%d%f%c",&i,&f,&ch);
//	printf("%d--%f--%d\n",i,f,ch);
	printf("RET : %d\n",ret);

	exit(0);
}












