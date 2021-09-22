#include <iostream>
using namespace std;

/*  new delete */

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
	//Clock *p = new Clock;
	//delete p;

	Clock *p = new Clock[5];
	delete []p;

	return 0;
}


