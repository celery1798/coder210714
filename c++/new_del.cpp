#include <iostream>
using namespace std;

int main()
{
	char *p = new char;
	if(p == NULL)
		return -1;

	*p = 'a';
	cout << *p << endl;
	
	delete p;


	return 0;
}

