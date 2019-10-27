#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int count_one_bits(unsigned int value)//这里也可以用操作符实现类似效果
{
	int num = 0;
	while (value)
	{
		if (value % 2)
			num++;
		value = value / 2;
	}
	return num;
}
int main()
{
	int i = 0;
	int num = 0;
	printf("请输入一个正数：");
	scanf("%d", &i);
	num = count_one_bits(i);
	printf("num=%d\n", num);
	system("pause");
	return 0;
}
