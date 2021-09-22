#include <iostream>
using namespace std;
/*类中的特殊函数*/
/*
拷贝构造函数：作用：初始化 ，在一个对象生成时，且用相同类型的已存在的对象初始化时调用拷贝构造 
默认有一个系统生成的拷贝构造函数，若我们自行实现了拷贝构造函数，系统默认的那个不再生成
长相：函数名与类同名，无返回值，参数为常引用
*/

class Clock
{
public:
	Clock(int h=0,int m=0,int s=0);
	Clock(const Clock &other);
	~Clock();
	void ShowTime();
	void SetTime(int h,int m,int s);
private:
	int hour;
	int minute;
	int second;
};
Clock::Clock(int h,int m,int s)
{	
	cout << "Clock(3*int)" << endl;
	hour = h ; 		
	minute = m;
	second = s;	
}
Clock::Clock(const Clock &other)
{
	cout << "Clock(&)" << endl;
	hour = other.hour;
	minute = other.minute;
	second = other.second;
}
Clock::~Clock()
{	
	cout << "~Clock()  " << hour <<  endl;
}

void Clock::ShowTime()
{	cout << hour << ":" << minute << ":" << second << endl;  }
void Clock::SetTime(int h,int m,int s)
{	hour = h; minute = m; second = s;	}

int main()
{
	Clock c1(4);
	Clock c2 = c1;
	c2.ShowTime();

	return 0;
}


