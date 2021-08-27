#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static jmp_buf save;

void d()
{
    printf("%d:[%s]Begin.\n",__LINE__, __FUNCTION__);

	printf("%d:[%s]Jump now!~~~\n",__LINE__, __FUNCTION__);
	longjmp(save,666);

    printf("%d:[%s]End.\n",__LINE__, __FUNCTION__);
}

void c()
{
    printf("%d:[%s]Begin.\n",__LINE__, __FUNCTION__);
    printf("%d:[%s]Call d().\n",__LINE__, __FUNCTION__);
    d();
    printf("%d:[%s]d() returned.\n",__LINE__, __FUNCTION__);
    printf("%d:[%s]End.\n",__LINE__, __FUNCTION__);
}

void b()
{
    printf("%d:[%s]Begin.\n",__LINE__, __FUNCTION__);
    printf("%d:[%s]Call c().\n",__LINE__, __FUNCTION__);
    c();
    printf("%d:[%s]c() returned.\n",__LINE__, __FUNCTION__);
    printf("%d:[%s]End.\n",__LINE__, __FUNCTION__);
}


void a()
{
	int ret;

	printf("%d:[%s]Begin.\n",__LINE__, __FUNCTION__);

	ret = setjmp(save);
	if(ret == 0)
	{
		printf("%d:[%s]Call b().\n",__LINE__, __FUNCTION__);
		b();
		printf("%d:[%s]b() returned.\n",__LINE__, __FUNCTION__);
	}
	else
		printf("%d:[%s]Jumped back here with code %d\n",__LINE__, __FUNCTION__,ret);
	printf("%d:[%s]End.\n",__LINE__, __FUNCTION__);
}

int main()
{
	printf("%d:[%s]Begin.\n",__LINE__, __FUNCTION__);
	printf("%d:[%s]Call a().\n",__LINE__, __FUNCTION__);
	a();
	printf("%d:[%s]a() returned.\n",__LINE__, __FUNCTION__);
	printf("%d:[%s]End.\n",__LINE__, __FUNCTION__);

	exit(0);
}

