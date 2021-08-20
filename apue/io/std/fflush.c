#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
缓冲区:暂存空间,大多数情况下,缓冲区的存在是件好事,作用合并系统调用 
行缓冲:stdout,换行时,满了时,强制刷新
全缓冲:默认,(只要不是终端设备,全采用全缓冲模式)满了时,强制刷新 
无缓冲:stderr,需要立即输出


*/

int main()
{
	int i;

	for(i = 0 ; i < 5; i++)
	{
		putchar('x');
		sleep(1);
	}

	putchar('\n');

/*
	int i= 1;


	printf("Befor while()");
	fflush(stdout);


	while(1);


	printf("After while()");

*/	
	exit(0);
}



