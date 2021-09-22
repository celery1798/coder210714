#include <iostream>
using namespace std;

/*
C:struct student_st   ->  sizeof ->  40

main(): struct student_st s1;  func(&s1);
func(struct student_st *per )


C++:struct student_st   ->  sizeof ->  40
main(): struct student_st s1;  func(s1);
func(struct student_st &per )

*/

int main()
{
	int i = 1;
	int &j = i;

	j = 11;
	cout << "i = " << i << "    &i = " << &i << endl;
	cout << "j = " << j << "    &j = " << &j << endl;

	return 0;
}

