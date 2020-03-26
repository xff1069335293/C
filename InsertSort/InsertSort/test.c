#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

Swap(int *p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void Sort(int* arr, int n)
{				
	int num = arr[0];
	int index = 0;
	int i = 0;
	while (i<=n) 
	{
		if (num <= arr[i])
		{
			num = arr[i];
			index = i;
			++i;
		}
		else
		{
			
			while (index >= 0 && arr[index + 1] < arr[index])
			{
				Swap(&arr[index], &arr[index + 1]);
				--index;
			}
			index = i;
			++i;
			num = arr[index];
		}
	}
}	
Print(int* arr, int n)
{
	for (int i = 0; i <= n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1,5,6,7,8,9,64,2,5,6,5,1,3,13,13,1,5,5,15};
	int n = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, n - 1);
	Print(arr, n - 1);
	system("pause");
	return 0;
}