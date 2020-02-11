//1.调整数组使奇数全部都位于偶数前面。 
#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<stdlib.h>
void Adjust(int* arr,int len)
{
	int* src = NULL;
	int* end = arr + len;
	while ( arr<= end)
	{
		while (*arr % 2 != 0 && arr <= end)
		{
			++arr;
		}
		src = arr;
		while (*arr % 2 == 0 && arr <= end)
		{
			++arr;
		}
		
		if (arr > end)
		{
			return ;
		}
		int tmp = *src;
		*src = *arr;
		*arr = tmp;
		arr = src;
		++arr;
	}
}

void Print(int* arr, int len)
{
	for (int i = 0; i <= len; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1,4,2,5,6,7,9,2 };
	int len = sizeof(arr) / sizeof(arr[0])-1;
	Print(arr, len);
	Adjust(arr,len);
	Print(arr,len);
	system("pause");
	return 0;
}