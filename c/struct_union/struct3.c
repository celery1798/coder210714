#include <stdio.h>
#include <stdlib.h>

struct student_st
{
	char name[12];
	int age;
	float math;
};

int main()
{
	struct student_st s1[] = {{"alan",20,98}, {"lily",21,89}, {"john",22,99}};
	int i;
	struct student_st *p = s1;

	for(i = 0 ; i < sizeof(s1)/sizeof(*s1); i++)
		printf("%s %d %f\n",p[i].name, p[i].age, p[i].math);
//	printf("%s %d %f\n",p->name, p->age, p->math);

	exit(0);
}

