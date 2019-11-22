#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
	//找出这两个数字，编程实现。
	int arr[] = { 4,8,8,4,19,5,9,3,5,9,3,15,56,20 };
	int count = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);//12
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		count = 0;//每次执行循环时初始化为0
		for (j = 0; j < sz; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count == 1)
		{
			printf("%d\n", arr[i]);
		}
	}

	system("pause");
	return 0;
}

