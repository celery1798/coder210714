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
	struct student_st s1[2][3] = {{{"alan",20,98}, {"lily",21,89}, {"john",22,99}},{{"alan",20,98}, {"lily",21,89}, {"john",22,99}}};
	int i,j;
	struct student_st *p = *s1;

	struct student_st (*q)[3] = s1;

	for(i = 0 ; i < 2*3 ; i++)
		printf("%s %d %f\n",p[i].name, p[i].age, p[i].math);
	printf("\n");

	for(i = 0 ; i < 2; i++)
	{
		for(j = 0 ; j < 3; j++)
			printf("%s %d %f\n",q[i][j].name, q[i][j].age, q[i][j].math);
		printf("\n");
	}
//	printf("%s %d %f\n",p->name, p->age, p->math);

	exit(0);
}

