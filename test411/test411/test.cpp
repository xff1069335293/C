#include<iostream>
using namespace std;
class Date
{
public:
	//��ȡĳ�µ�����
	int Getmonthday(int year, int month)
	{
		int day[13] = { 0, 31,28,31,30,31,30,31,30,31,30,31,30 };
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			day[2] = 29;
		}
		return day[month];
	}
	//���캯��ȫȱʡ
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
			cout << "�Ƿ�����" << endl;
		}
	}
	//��������
	~Date()
	{

	}
	//�����>����
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
	//�����==����
	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}
	//�������=����
	bool operator!=(const Date& d)
	{
		
		
		return !(*this == d);
	}
	//�����>=����
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

	//����<����
	bool operator<(const Date& d)
	{
		if (*this >= d)
		{
			return false;
		}
		return true;
	}

	//����<=����
	bool operator<=(const Date& d)
	{
		if (*this > d)
		{
			return false;
		}
		return true;
	}
	//��ֵ������� = 
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	//����-����
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
	//����+����
	Date operator+(int day)
	{
		Date d = *this;
		d += day;
		return d;
	}
	//����+=����
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
	//ǰ��++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	//����++
	Date operator++(int)
	{
		Date d(*this);
		*this += 1;
		return d;
	}
	//ǰ��--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}
	//����--
	Date operator--(int)
	{
		Date d(*this);
		*this -= 1;
		return d;
	}
	//����-����
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



