//√∞≈›≈≈–Ú
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int Bubblesort1(int* arr, int len) //√∞≈›≈≈–Ú
{
	int count = 0;
	for (int i = 0; i <= len - 1; i++)
	{
		
		for (int j = 1; j <= len - i - 1; j++)
		{
			count++;
			if (arr[j - 1] > arr[j])
			{
				int tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return count;
}
int Bubblesort2(int* arr,int len) //√∞≈›≈≈–Ú”≈ªØ
{
	int count = 0;
	for (int i =0; i <= len-1; i++)
	{
		int flag = 0;
		for (int j = 1; j <=len-i-1; j++)
		{
			count++;
			if (arr[j-1] > arr[j ])
			{
				flag = 1;
				int tmp = arr[j-1];
				arr[j-1] = arr[j ];
				arr[j ] = tmp;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	return count;
}

void Print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = {4,8,9,10,11,12,13};
	int len = sizeof(arr) / sizeof(arr[0]);
	Print(arr, len);
	int ret = Bubblesort1(arr,len);
	printf("%d\n", ret);
	Print(arr, len);
	int ret2 = Bubblesort2(arr, len);
	printf("%d\n",ret2);
	Print(arr, len);
	system("pause");
	return 0;
}
