#define _CRT_SECURE_NO_WARNINGS 1
#define  N 5
#include <stdio.h>
#include <math.h>
//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值是value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
//unsigned int reverse_bit(unsigned int value) 
//{
//	int sum = 0;
//	for (int  i = 0; i < 32; i++)
//	{
//		sum+=(((value >> i) & 1)*pow(2, 31 - i));
//	}
//	return sum;
//}
//
//int main() 
//{
//	int input = 0;
//	scanf("%d",&input);
//	printf("%u", reverse_bit(input));
//	system("pause");
//	return 0;
//}
//2.不使用（a + b） / 2这种方式，求两个数的平均值。

//int average1(int num1, int num2)
//{
//	return	num1>num2?((num1 - num2) / 2) + num2: ((num2- num1) / 2+num1);
//
//}
//
//int average2(int num1, int num2)
//{
//	return ((num1&num2) + ((num1^num2) >> 1));
//}
//
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf("%d %d",&a,&b);
//	int ret = average2(a, b);
//	printf("%d",ret);
//	system("pause");
//	return 0;
//}
//
//3.编程实现： 
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//int  OneNum(int* arr,int len)
//{
//	int num = 0;
//	for (int i = 0; i < len; i++)
//	{
//		num ^= arr[i];
//	}
//	return num;
//}
//
//int main()
//{
//	int arr[] = { 1,1,2,2,3,3,6 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int ret = OneNum(arr,len);
//	printf("%d",ret);
//	system("pause");
//	return 0;
//}

