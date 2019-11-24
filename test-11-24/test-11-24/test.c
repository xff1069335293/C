//未完成1.
//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1   15  7  3  2   
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	 返回 1的位数 
//}
//
//2.获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。
//
//3. 输出一个整数的每一位。
//
//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int  count_one_bits(int y)
//{
//	int x=0;
//	while (z)
//	{
//		
//		if (y > 1)
//		{
//			x = y % 2;
//			y = y / 2;
//		
//		}
//		else
//		{
//			x = 0;
//		}
//		z--;
//		printf("%d", x);
//	}
//
//	return x;
//}
//
//int main()
//{
//	int ch = 0;
//	printf("请输入一个数：\n");
//	scanf("%d",&ch);
//	int ret = count_one_bits(ch);
//	printf("%d",ret);
//	system("pause");
//	return 0;
//}

//获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main()
{
	int num = 20;
	int i = 0;
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", ((num >> i) & 1));
	}
	//最高的偶数位向右移动31位到最后一位，最低偶数位向右移动1位到最后一位
	printf("\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", ((num >> i) & 1));
	}
	//最高的奇数位向右移动30位到最后一位，最低奇数数位向右移动0位到最后一位
	printf("\n");
	system("pause");
	return 0;
}
