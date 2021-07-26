#include <stdio.h>
#include <stdlib.h>

struct bith_st
{
	int year;
	int month;
	int day;
};

struct student_st
{
	char name[12];
	int age;
	struct bith_st bday;
	float math;
};

int main()
{
/*
	struct student_st s1 = {"alan",20,98},s2;
	struct student_st *p = &s1;

	// s2 = s1;

	printf("%s %d %f\n",s1.name, s1.age, s1.math);
	printf("%s %d %f\n",p->name, p->age, p->math);
*/

	struct student_st s1 = {"alan",20,{2021,7,26},98};
	struct student_st *p = &s1;

	printf("%s %d[%d-%d-%d] %f\n",p->name, p->age, p->bday.year, p->bday.month, p->bday.day, p->math);

	exit(0);
}

