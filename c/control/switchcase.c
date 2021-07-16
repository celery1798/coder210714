#include <stdio.h>
#include <stdlib.h>

/*							a <= b  m!= n 
switch(exp)
{
	case 常整形1:     		//3 25  'a'  '\n' 2+3
		;
		;
		break;
	case 常整形2:
        ;
        ;
        break;	
	...
	default:
		break;
}


*/

int main()
{
	int ch;
	
	ch = getchar();

	switch(ch)
	{
		case 'a':
		case 'A':
			printf("Ant:a small insect which lives in group.\n");
			break;
		case 'b':
		case 'B':
			printf("Bee:a small flying insect which dangerous.\n");
			break;
		case 'c':
		case 'C':
			printf("Cobra:a type of snake which very dangerous.\n");
			break;
		case 'd':
		case 'D':
			printf("Donkey:a lovely animal which has long ears and shourt legs.\n");
			break;
		default:
			printf("Input Error.\n");
			break;
	}

	exit(0);
}








