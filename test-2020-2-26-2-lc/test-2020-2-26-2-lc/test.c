#define _CRT_SECURE_NO_WARNINGS 1
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

示例：

输入：[3, 1, 2, 4]
输出：[2, 4, 3, 1]
输出[4, 2, 3, 1]，[2, 4, 1, 3] 和[4, 2, 1, 3] 也会被接受。

提示：

1 <= A.length <= 5000
0 <= A[i] <= 5000

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
	int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
	*returnSize = ASize;
	for (int i = 0; i < ASize; i++)
	{
		int flag = 0;
		for (int j = 1; j <= ASize - i - 1; j++)
		{
			if (A[j - 1] % 2 == 1)
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
	return A;
}
