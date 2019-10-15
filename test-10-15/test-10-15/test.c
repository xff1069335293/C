//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19


DigitSum(int ch) //DigitSum(172) 9  17 2 9  1 7 2 9
{

	if (ch < 10)
	{
		return ch;
	}
	else
	{
		return  DigitSum(ch / 10) + ch % 10;

	}
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned int ch = 0;
	printf("请输入一个数：\n");
	scanf("%d", &ch);
	int ret = DigitSum(ch);
	printf("%d\n", ret);
	system("pause");
	return 0;

}
