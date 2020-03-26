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

//向下调整算法用于建堆
void AdjustDown(int* arr, int parent,int n)
{	
	assert(arr);
	int child = 2 * parent + 1;
	while (child<n)
	{
		if (child+1<n && arr[child] < arr[child + 1])
		{
			++child;
		}
		if(arr[parent] < arr[child])
		{
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = 2*parent+ 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	assert(arr);
	for (int i = (n-2)/2; i >= 0; --i)
	{
		AdjustDown(arr, i, n);
	}
	int end = n-1;
	while (end)
	{
		Swap(&arr[0], &arr[end]);
		--end;
		AdjustDown(arr, 0, end);
	}
}
void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1,5,6,7,8,9,64,2,5,6,5,1,3,13,13,1,5,5,15 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, n);
	Print(arr, n);
	system("pause");
	return 0;
}