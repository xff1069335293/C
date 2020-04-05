#include<iostream>
using namespace std;
//C++练习
//作用域
//namespace N 
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}
//将命名空间的成员引入
//using N::a;
//将命名空间引入
//using namespace N;
//使用作用域限定符
//N::a
//int main()
//{
//	printf("%d\n", a); 
//	getchar();
//	return 0;
//}

//缺省参数
//void TestFunc1(int a = 10, int b = 20, int c = 30) {
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//void TestFunc2(int a, int b = 10, int c = 20) {
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//int main()
//{
//	TestFunc2(5,1,2); // 没有传参时，使用参数的默认值
//	TestFunc2(20); // 传参时，使用指定的实参
//	getchar();
//}

//重载
//int Add(int left, int right) 
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//long Add(long left, long right) 
//{
//	return left + right;
//}
//int main()
//{
//	Add(10, 20);
//	Add(10.0, 20.0);
//	Add(10L, 20L);
//	return 0;
//}

//引用
//
//void swap(int*pa, int *pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//void swap_c(int& ra, int& rb)
//{
//	int tmp = ra;
//	ra = rb;
//	rb = tmp;
//}
//int main()
//{
//	int a = 1;
//	int b = 0;
//	swap(&a, &b);
//	swap_c(a, b);
//	cout << a << endl;
//	system("pause");
//	return 0;
//}