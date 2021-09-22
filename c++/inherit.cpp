#include <iostream>
using namespace std;
/*
父类-子类   基类-派生类
		parent->:	public			protected			private
	public:			public			protected			-
	protected:		protected		protected			-
	private:		private			private				-
*/

class A
{
public:
	A()	{cout << "A()" << endl;}
	~A() {cout << "~A()" << endl;}
	void GetA()	{  cout << "A::GetA() " <<  a << endl;}
protected:
	void Show()	 {	cout << "A::Show()" <<  a << endl;}
private:
	int a;
};

class B : public A
{
public:
	B() {cout << "B()" << endl;}
	~B() {cout << "~B()" << endl;}
	void GetShow() { Show();	}
	void GetA() {  cout << "B::GetA() " << endl;}
};

int main()
{
	B tmp;
	tmp.GetA();

	return 0;
}

