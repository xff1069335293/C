#define _CRT_SECURE_NO_WARNINGS 1
//给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
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
//提示：
//
//1 <= A.length <= 10000
//- 10000 <= A[i] <= 10000
//A 已按非递减顺序排序。


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
	void sort(int* A, int ASize)
{
	for (int i = 0; i < ASize; i++)
	{
		int flag = 0;
		for (int j = 1; j <= ASize - 1 - i; j++)
		{
			if (A[j - 1] > A[j])
			{
				flag = 1;
				int tmp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = tmp;
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
	*returnSize = ASize;
	for (int i = 0; i < ASize; i++)
	{
		A[i] *= A[i];
	}
	sort(A, ASize);
	return A;
}
