#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void Swap(int *p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void Print(int* arr, int n)
{
	for (int i = 0; i <n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Merge(int* arr, int  start, int end)
{
	int mid = (start + end) >> 1;
	if (start == end)
	{
		return;
	}
	Merge(arr, start, mid);
	Merge(arr, mid + 1, end);
	while (start<=end)
	{
		if (arr[start] > arr[end])
		{
			Swap(&arr[start], &arr[end]);
		}
		++start;
		--end;
	}

}

void MergeSort(int* arr,int n)
{
	int start = 0;
	int end = n - 1;
	Merge(arr, start, end);


}




int main()
{
	int arr[] = { 9,1,5,7,6,3,8,1,2,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, n );
	Print(arr, n);
	system("pause");
	return 0;
}