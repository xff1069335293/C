//
//2.编写一个函数实现n^k，使用递归实现

double Pow(int n, int k)
{
	
	if(k >= 0)
	{
		if (k == 0)
		{
			return	1;
		}
		if (k == 1)
		{
			return n;
		}
		return n * Pow(n, k - 1); 
	}
	else
	{
		return 1.0/(n * Pow(n, -k - 1));
	}


}


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	int k = 0;
	printf("请输入n,k的值：\n");
	scanf("%d %d", &n, &k);
	double ret = Pow(n,k);
	printf("%lf", ret);
	system("pause");
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


