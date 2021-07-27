#include <stdio.h>
#include <stdlib.h>

union
{
	struct
	{
		unsigned short low;
		unsigned short hight;
	}x;
	unsigned int y;
}num;

int main()
{
	num.y = 0x11223344;

	printf("%x\n", num.x.low + num.x.hight);


	exit(0);
}

