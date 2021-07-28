#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NAMEMAX		1024

typedef struct 
{
	int id;
	char *name;
	float math;
	float chinese;
}STU;

void menu()
{
	printf("\n---MENU---\n");
	printf("1:SET\n2:CHANGENAME\n3:SHOW\nq:QUIT\n");
	printf("Enter your choice:");

}

int set(STU *p)
{
	char buf[NAMEMAX];
	printf("Please enter :");
	scanf("%d%s%f%f",&p->id, buf,&p->math,&p->chinese);
	p->name = malloc(strlen(buf)+1);
	if(p->name == NULL)
	{
		return -1;
	}
	strcpy(p->name,buf);
	return 0;
}

void show(STU *p)
{
	printf("%d %s %f %f\n",p->id,p->name, p->math, p->chinese);
}

int changename(STU *p)
{
	char newname[NAMEMAX];
	
	printf("Please enter the NEW NAME:");
	scanf("%s",newname);
	
	free(p->name);
	p->name = malloc(strlen(newname)+1);
	if(p->name == NULL)
		return -1;
	strcpy(p->name,newname);
	return 0;
}

void init(STU *p)
{
	p->id = p->math = p->chinese = 0;
	p->name = malloc(1);
	/*if error*/
	*(p->name) = '\0';
}

void destroy(STU *p)
{
	free(p->name);
	p->name = NULL;
}

int main()
{
//	STU s = {0,NULL,0,0};
	STU s;
	int ch;

	init(&s);


	while(1)
	{
		menu();
		if(scanf("%d",&ch) != 1)
			break;

		switch(ch)
		{
			case 1:
				set(&s);
				break;
			case 2:
				changename(&s);
				break;
			case 3:
				show(&s);
				break;	
			default:
				break;
		}
		sleep(1);
	}

	destroy(&s);
	

	exit(0);
}

