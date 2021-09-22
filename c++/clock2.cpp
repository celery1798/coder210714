#include <iostream>
using namespace std;
/*类中的特殊函数*/
/*
析构函数：作用：清理或销毁，在一个对象生命周期即将终止时被隐式调用
默认有一个系统生成的析构函数，若我们自行实现析构函数，系统默认的那个不再生成
长相：函数名与类同名，前面加～，不需要返回值，不可传参
*/

class Clock
{
public:
	Clock(int h=0,int m=0,int s=0);
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
	Clock c0;
	{
	Clock c2(14,15);
	}
	Clock c1(4);

	return 0;
}

