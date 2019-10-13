//
//2.编写一个函数实现n^k，使用递归实现


int Mypow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k == 1)
	{
		return n;
	}
	else
	{
		return n * Mypow(n, k - 1);
	}
}


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
{
	int n = 2;
	int k = 5;
	int c = Mypow(n, k);
	printf("%d^%d = %d\n", n, k, c);
	return 0;
}




//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
//
//5.递归和非递归分别实现strlen
//6.递归和非递归分别实现求n的阶乘
//7.递归方式实现打印一个整数的每一位 


