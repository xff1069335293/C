#define _CRT_SECURE_NO_WARNINGS 1
����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��

ʾ�� 1:

����: [1, 2, 3]
	��� : [1, 2, 4]
	���� : ���������ʾ���� 123��
	ʾ�� 2 :

	���� : [4, 3, 2, 1]
	��� : [4, 3, 2, 2]
	���� : ���������ʾ���� 4321��


	/**
	 * Note: The returned array must be malloced, assume caller calls free().
	 */
	void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[right];
		nums[right] = nums[left];
		nums[left] = tmp;
		++left;
		--right;
	}
}

	int* plusOne(int* digits, int digitsSize, int* returnSize)
	{

		int* result = (int *)malloc(sizeof(int)*(digitsSize + 1));
		int count = 1;
		int num = 0;
		while (digitsSize)
		{
			if (digits[digitsSize - 1] + count == 10)
			{
				result[num] = 0;
			}
			else
			{
				result[num] = digits[digitsSize - 1] + count;
				count = 0;
			}
			++num;
			--digitsSize;
		}
		if (digitsSize == 0 && count)
		{
			result[num] = 1;
		}
		else
		{
			--num;
		}
		reverse(result, 0, num);
		*returnSize = num + 1;
		return result;
	}
	