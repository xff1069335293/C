//.一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
//
//示例 1：
//
//输入：nums = [4, 1, 4, 6]
//输出：[1, 6] 或[6, 1]
//示例 2：
//
//输入：nums = [1, 2, 10, 4, 1, 4, 3, 3]
//输出：[2, 10] 或[10, 2]


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

	int _QuickSort(int *nums, int left, int right)
{
	int key = nums[right];
	int index = right;
	while (left < right)
	{
		while (left < right)
		{
			if (nums[left] > key)
			{
				nums[index] = nums[left];
				index = left;
				break;
			}
			++left;
		}
		while (left < right)
		{
			if (nums[right] < key)
			{
				nums[index] = nums[right];
				index = right;
				break;
			}
			--right;
		}

	}
	nums[left] = key;
	return left;
}
void  QuickSort(int *nums, int left, int right)
{
	if (left > right)
	{
		return;
	}
	int index = _QuickSort(nums, left, right);
	QuickSort(nums, left, index - 1);
	QuickSort(nums, index + 1, right);
}

//快排
//双指针
int* singleNumbers(int* nums, int numsSize, int* returnSize) {
	*returnSize = 0;
	QuickSort(nums, 0, numsSize - 1);
	for (int i = 0; i < numsSize; i++)
	{
		if (i + 1 < numsSize && nums[i] == nums[i + 1])
		{
			i = i + 1;
		}
		else
		{
			nums[(*returnSize)++] = nums[i];
		}
	}
	return nums;
}