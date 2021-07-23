#include <stdio.h>
#include <stdlib.h>

void d()
{
    printf("%d:[%s]Begin.\n",__LINE__, __FUNCTION__);
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
	printf("%d:[%s]Begin.\n",__LINE__, __FUNCTION__);
    printf("%d:[%s]Call b().\n",__LINE__, __FUNCTION__);
    b();
    printf("%d:[%s]b() returned.\n",__LINE__, __FUNCTION__);
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

