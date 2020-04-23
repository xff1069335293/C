#include<iostream>
using namespace std;
class Date
{
public:
	//获取某月的天数
	int Getmonthday(int year, int month)
	{
		int day[13] = { 0, 31,28,31,30,31,30,31,30,31,30,31,30 };
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			day[2] = 29;
		}
		return day[month];
	}
	//构造函数全缺省
	Date(int year=1900, int month=1, int day=1)
	{
		if (year >= 0 && month > 0 && month < 13 && day>0 && day <= Getmonthday(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
		}
	}
	//析构函数
	~Date()
	{

	}
	//运算符>重载
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year&&_month > d._month)
		{
			return true;
		}
		else if (_year == d._year&&_month == d._month&& _day > d._day)
		{
			return true;
		}
		return false;
	}
	//运算符==重载
	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}
	//运算符！=重载
	bool operator!=(const Date& d)
	{
		
		
		return !(*this == d);
	}
	//运算符>=重载
	bool operator>=(const Date& d)
	{
		if (*this > d)
		{
			return true;
		}
		else if (*this == d)
		{
			return true;
		}
		return false;
	}

	//运算<重载
	bool operator<(const Date& d)
	{
		if (*this >= d)
		{
			return false;
		}
		return true;
	}

	//运算<=重载
	bool operator<=(const Date& d)
	{
		if (*this > d)
		{
			return false;
		}
		return true;
	}
	//赋值运算符号 = 
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	//日期-天数
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0)
			{
				--_month;
				if (_month == 0)
				{
					_month = 12;
					--_year;
				}
				_day += Getmonthday(_year, _month);
			}
		return *this;
	}
	Date operator-(int day)
	{
		Date d(*this);
		d -= day;
		return d;
	}
	//日期+天数
	Date operator+(int day)
	{
		Date d = *this;
		d += day;
		return d;
	}
	//日期+=天数
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}
			_day += day;
			while (_day > Getmonthday(_year, _month))
			{
				++_month;
				if (_month > 12)
				{
					++_year;
					_month = 1;
				}
				_day -= Getmonthday(_year, _month);
			}
		return *this;
	}
	//前置++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	//后置++
	Date operator++(int)
	{
		Date d(*this);
		*this += 1;
		return d;
	}
	//前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}
	//后置--
	Date operator--(int)
	{
		Date d(*this);
		*this -= 1;
		return d;
	}
	//日期-日期
	int operator-( Date  d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		int num = 0;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		while (min != max)
		{
			++num;
			++min;
		}
		return flag == 1 ? num: -num;
	}

	void Display()
	{
		cout << _year <<"-"<<_month <<"-"<<_day << endl;	
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020,4,15);
	d1.Display();
	Date d2(2020,4,10);
	d2.Display();
	Date d3(d2);
	d3.Display();
	d3++;
	d3.Display(); 
	//d2.Display();
	
	
	/*cout << (d1 > d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 != d2) << endl;
	cout << d2 - d1 << endl;
	cout << d1 - d2 << endl;*/
	
	getchar();
	return 0;
}



