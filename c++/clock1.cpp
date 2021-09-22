#include <iostream>
using namespace std;
/*类中的特殊函数*/
/*
构造函数：作用：初始化，在一个对象生成的时候被隐式调用
默认有一个系统生成的构造函数，若我们自行实现了构造函数，系统默认的那个不再生成
长相：函数名与类同名，不需要返回值，可传参（可1个或多个）可无参
构造函数可以同时存在多个
*/

class Clock
{
public:
	Clock();
	Clock(int h);
	void ShowTime();
	void SetTime(int h,int m,int s);
private:
	int hour;
	int minute;
	int second;
};
Clock::Clock()
{	
	cout << "Clock()" << endl;
	hour = minute = second = 0;	
}
Clock::Clock(int h)
{	
	cout << "Clock(int)" << endl;
	hour = h ; 		minute = second = 0;	
}
void Clock::ShowTime()
{	cout << hour << ":" << minute << ":" << second << endl;  }
void Clock::SetTime(int h,int m,int s)
{	hour = h; minute = m; second = s;	}

int main()
{
	Clock c0;
	Clock c1(4);
	Clock c2(14,15);
//	c1.ShowTime();

	return 0;
}

