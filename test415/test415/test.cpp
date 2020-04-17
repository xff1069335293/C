#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Stack
{
public:
	Stack(int n)
	{
		int* _a = (int*)malloc(sizeof(int)*n);
		_size = 0;
		_capacity = n;
		cout<<"Stack"<< endl;
	}
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_size = 0;
		_capacity = 0;
		cout << "~Stack" << endl;
	}
	void Display()
	{
		cout << this->_capacity << endl;
	}
private:
	int* _a;
	int _size;
	int _capacity;
};

//Stack::Stack()
//{
//}
//
//Stack::~Stack()
//{
//}

class Data
{
public:
	
	void Display()
	{
		cout << this->_year << endl;
	}

private:
	int _year;
	int _day;
};



int main()
{
	/*Stack st1(10);
	st1.Display();
	Stack st2(st1);
	st2.Display();
	Stack st3(30);
	st3.Display();
	st3 = st2;
	st3.Display;
*/
	Data d1(10);
	d1.Display();
		
	getchar();
	return 0;
}