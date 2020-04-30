#include<iostream>
#include <cstring>
using namespace std;
//类和对象中篇
//class Time {
//public:
//	Time() {
//		_hour =0 ;
//		cout << "Time（） "<< endl;
//	}
//public:
//	int _hour;
//};
//
//class Date
//{
//public:
//	//建议使用--全缺省构造函数
//	Date(int year = 1900, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//
//	}
//	//无参构造函数
//	/*Date() {
//		_year = year;
//		_month = month;
//		_day = day;
//
//	}*/
//	//析构函数
//	~Date() {
//
//	}
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day<< endl;
//			cout <<_t._hour<< endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};


//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//	void Display()
//	{
//		cout << _str << endl;
//	}
//private:
//	char* _str;
//};

int main()
{
	//Date d1;//不写构造函数时，会调用默认构造函数，完成初始化
	//d1.Display();
	//Date d2(2020,2,1);
	//d2.Display();
	//String s1("hello");
	//String s2;
	//s2 = s1;
	getchar();
	return 0;
}


