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
	struct student_st s1 = {"alan",20,{2021,7,26},98};

	printf("%s %d[%d-%d-%d] %f\n",s1.name, s1.age, s1.bday.year, s1.bday.month, s1.bday.day, s1.math);

	exit(0);
}

