#include <iostream>
using namespace std;

class A
{
public:	
	A()	{	str = new char[1]; *str = '\0'	};
	~A() { delete []str;	}
	void Show()	{	cout << str << endl;	}
private:
	char *str;
};

int main()
{
	A a1;
	return 0;
}

