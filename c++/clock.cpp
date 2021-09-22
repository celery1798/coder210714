#include <iostream>
using namespace std;
//内联函数inline  1类内实现  2用inline关键字类内声明，实现可以写在类外
//public protected private
class Clock
{
public:
	void ShowTime();
	void SetTime(int h,int m,int s);
private:
	int hour;
	int minute;
	int second;
};
void Clock::ShowTime()
{	cout << hour << ":" << this->minute << ":" << second << endl;  }

void Clock::SetTime(int h,int m,int s)
{	this->hour = h; this->minute = m; second = s;	}

int main()
{
	Clock c1,c2;

//	cout << sizeof(c1) << endl;
	c2.SetTime(10,10,10);
	c1.ShowTime();

	return 0;
}

