#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int buf[10] = { 0 };//把数组全部初始化为0
	int i = 0;
	int len = 9;//数组的下标
	for (i = 0; i < 10; ++i)	//循环输入数组
	{
		scanf("%d", &buf[i]);
	}
	for (i = 0; i <= len; ++i) 
	{
		if (buf[i] % 2 == 0) 
		{
			int tmp = buf[len];
			buf[len] = buf[i];
			buf[i] = tmp;//交换数组
			len = len - 1;//即控制循环跳出条件,又控制数组下边往前移动一.
			i = i - 1;//因为不知道交换的元素是否为偶数,所以把这次循环再进行一次
		}
	}
	for (i = 0; i < 10; ++i) 
	{
		printf("%d ", buf[i]);
	}
	system("pause");
	return 0;
}
