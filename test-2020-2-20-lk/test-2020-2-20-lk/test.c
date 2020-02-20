#define _CRT_SECURE_NO_WARNINGS 1
//给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
//
//
//
//示例 1：
//
//输入：[-4, -1, 0, 3, 10]
//输出：[0, 1, 9, 16, 100]
//示例 2：
//
//输入：[-7, -3, 2, 3, 11]
//输出：[4, 9, 9, 49, 121]
//
//
//提示：
//
//1 <= A.length <= 10000
//- 10000 <= A[i] <= 10000
//A 已按非递减顺序排序。
int* sortedSquares(int* A, int ASize, int* returnSize) {
	int i = 0, j = ASize - 1;
	int k = ASize - 1;
	int *b = (int *)malloc(sizeof(int)*ASize);
	while (i <= j)
	{
		if (abs(A[i]) > abs(A[j]))
		{
			b[k] = A[i] * A[i];
			k--;
			i++;
		}
		else
		{
			b[k] = A[j] * A[j];
			k--;
			j--;
		}
	}
	*returnSize = ASize;
	return b;
}
#include<stdio.h>
#include<stdlib.h>
void sort(int* nums, int numsSize)
{
	for (int i = 0; i < numsSize; i++)
	{
		int flag = 0;
		for (int j = 1; j <= numsSize - i - 1; j++)
		{
			if (nums[j - 1] > nums[j])
			{
				flag = 1;
				int tmp = nums[j - 1];
				nums[j - 1] = nums[j];
				nums[j] = tmp;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

int* sortedSquares(int* A, int ASize, int* returnSize)
{
	for (int i = 0; i < ASize; i++)
	{
		returnSize[i] = A[i] * A[i];
		
	}
	sort(returnSize, ASize);
	return returnSize;
}
int main()
{
	int A[] = { -1,0,1,2,3,4,5,6 };
	int ASize = sizeof(A) / sizeof(A[0]);
	int returnSize[10000] = { 0 };
	sortedSquares(A, ASize, returnSize);
	for (int i=0; i < ASize; i++)
	{
		printf("%d ",returnSize[i]);
	}
	system("pause");
	return 0;
}





