#define _CRT_SECURE_NO_WARNINGS 1
����һ���Ǹ��������� A������һ�����飬�ڸ������У� A ������ż��Ԫ��֮�������������Ԫ�ء�

����Է���������������κ�������Ϊ�𰸡�

ʾ����

���룺[3, 1, 2, 4]
�����[2, 4, 3, 1]
���[4, 2, 3, 1]��[2, 4, 1, 3] ��[4, 2, 1, 3] Ҳ�ᱻ���ܡ�

��ʾ��

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
