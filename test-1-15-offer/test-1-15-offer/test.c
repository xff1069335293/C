// 数组问题
//1.sizeof,strlen
//2.找出数组中的重复数字，并且删除。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Sort(int* arr,int len)   // 
{	
	for (int j = 0; j < len; j++)
	{
		for (int i = 0; i < len; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

void Print(int* arr,int len)
{
	for (int i = 0; i <= len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Delete(int *arr, int len)
{
	int src = 0;
	int dst = 1;
	int count = 0;
	while (count < len)		//2 2 2 3
	{
		while (arr[src] == arr[dst])
		{
			arr[count] = arr[src];
			dst++;
		}
		src = dst;
		count++;
		arr[count] = arr[src];
		dst++;
		if (dst == len)
		{
			break;
		}
	}
	len = count;
	return arr;
}

int main()
{
	int arr[] = {2,3,2,6,2,6,4};
	int len =(sizeof(arr) / sizeof(arr[0]))-1;
	Sort(arr,len);
	Print(arr, len);
	Delete(arr, len);
	Print(arr,len);
	system("pause");
	return 0;
}