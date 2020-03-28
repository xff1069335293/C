#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void Swap(int *p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

SelectSort(int *arr, int n)
{
	int left = 0;
	int right = n - 1;
	int max = 0, min = 0;
	while (left < right)
	{
		for (int i = left; i <= right; ++i) //如果范围不变的话，每次选的最小值和最大值都一样
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
			if (arr[i] > arr[max])
			{
				max = i;
			}
		}
			Swap(&arr[left], &arr[min]);
			if (max == left)
			{
				
				Swap(&arr[min], &arr[max]);
			}
			else
			{
				
				Swap(&arr[right], &arr[max]);
			}
		++left;
		--right;
	}
}
int main()
{
	int arr[] = {7,4,5,9,8,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, n);
	Print(arr, n);
	system("pause");
	return 0;
}