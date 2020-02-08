#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	int num1 = 1;
//	int num2 = 2;
//	printf("%d %d %d ",num1 & num2, num1 | num2, num1^num2);//操作符与 或 抑或
//	printf("%d ",num1>>1);  //左移1位 ✖2 右移➗2
//	printf("%d %d\n",num1,num2);//创建变量的交换
//	num1 = num1 ^ num2; //3
//	num2 = num1 ^ num2;//1
//	num1 = num1 ^ num2;//2
//	printf("%d %d\n", num1, num2);
//	system("pause");
//	return 0;
//}


//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1  10  1010 
//程序原型：
//int count_one_bits(int value)
//{
//	// 返回 1的位数 
//}
//int count_bits1(unsigned int input)//求负数应该将数转化为无符号整型
//{
//	int count = 0;
//	while (input)
//	{
//		if (input%2 == 1)
//		{
//			count++;
//		}
//		input = input / 2;
//	}
//	return count;
//}
//
//int count_bits2(int input)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{	
//		if ((input >> i) & 1 == 1)//先右移在和1与，将最后一位的1取出来计数，循环32次将负数也能取出
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int count_bits3(int input) 
//{	 
//	int count = 0;
//	while (input)
//	{
//		++count;
//		input = (input - 1)&input;//从右向左依次将1取出，直到值为零。
//	}
//	return count;
//}
//
//
//int main()
//{ 
//	int input = 0;
//	scanf("%d", &input);
//	printf("%d %d %d\n", count_bits1(input),count_bits2(input),count_bits3(input));
//	system("pause");
//	return 0;
//}

//2.获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。
//
//3. 输出一个整数的每一位。
//
//int main()
//{
//	int num = 0;
//	scanf("%d",&num);
//	while (num)
//	{
//		printf("%d ",num%10);
//		num = num / 10;
//	}
//	system("pause");
//	return 0;
//}
//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
//
//
//int main()
//{
//	int b = -20;
//	system("pause");
//	return 0;
//}