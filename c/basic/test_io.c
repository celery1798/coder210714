#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a,b,c;
	float x1,x2,dis,p,q;

	scanf("%d%d%d",&a,&b,&c);

	dis	= b*b - 4*a*c; 
	p = (float)-b/(2*a);
	printf("----%f\n",p);
	q = sqrt(dis)/(2*a);
	printf("----%f\n",q);

	x1 = p + q;
	x2 = p - q;

	printf("x1 = %f, x2 = %f\n",x1,x2);


	exit(0);
}

