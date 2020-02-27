#define _CRT_SECURE_NO_WARNINGS 1
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1, 2, 3]
	输出 : [1, 2, 4]
	解释 : 输入数组表示数字 123。
	示例 2 :

	输入 : [4, 3, 2, 1]
	输出 : [4, 3, 2, 2]
	解释 : 输入数组表示数字 4321。


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
	