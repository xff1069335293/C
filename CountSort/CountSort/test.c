#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void CountSort(int *arr,int n)
{
	int max , min = arr[0];
	max = min;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i]<=min)
		{
			min = arr[i];
		}
		
	}
	int range = max - min+1;
	int* a = (int*)malloc(sizeof(int)*range);
	for (int i = 0; i < range; i++)
	{
		a[i] = 0;
	}
	
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		a[arr[i] - min ]++;
	}

	for (int i = 0; i < range; i++)
	{
		while (a[i] > 0)
		{
			arr[count] = i + min;
			count++;
			a[i]--;
		}
	}
	free(a);
}

void Print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 9,8,8,8,8,4,4,10,10,5,6,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr,n);
	Print(arr, n);
	system("pause");
	return 0;
}