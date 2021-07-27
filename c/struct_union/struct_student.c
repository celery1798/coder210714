#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NAMESIZE	32

struct student_st
{
	int id;
	char name[NAMESIZE];
	float math;
	float chinese;
};

void menu()
{
	printf("\n---MENU---\n");
	printf("1:SET\n2:CHANGENAME\n3:SHOW\nq:QUIT\n");
	printf("Enter your choice:");

}

void set(struct student_st *p)
{
	printf("Please enter :");
	scanf("%d%s%f%f",&p->id,p->name,&p->math,&p->chinese);
}

void show(struct student_st *p)
{
	printf("%d %s %f %f\n",p->id,p->name, p->math, p->chinese);
}

void changename(struct student_st *p)
{
	char newname[NAMESIZE];

	printf("Please enter the NEW NAME:");
	scanf("%s",newname);
	strcpy(p->name,newname);
}

int main()
{
	struct student_st s = {0,"",0,0};
	int ch;

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

	exit(0);
}

