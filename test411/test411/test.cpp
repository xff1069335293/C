#include<iostream>


class A1 {
public:
	void f1() {}
private:
	int _a;
};
// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};
// 类中什么都没有---空类
class A3
{};

using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator>(const Date& d2)
	{
		if (_year > d2._year)
		{
			return true;
		}
		else if (_year == d2._year&&_month > d2._month)
		{
			return true;
		}
		else if (_year == d2._year&&_month > d2._month&& _day > d2._day)
		{
			return true;
		}
		return false;
	}
private:
	int _year;
	int _month;
	int _day;

};

int main()
{
	/*A1 a1;
	A2 a2;
	A3 a3;
	cout << sizeof(a1) << endl;
	cout << sizeof(a2) << endl;
	cout << sizeof(a3) << endl;*/
	Date d1(2010, 5, 13);
	Date d2(2020, 4, 11);
	cout<< (d1 > d2)<<endl;
	getchar();
	return 0;
}



