数组中/*有一个数字出现的次数超过数组长度的一半，请找出这个数字。



你可以假设数组是非空的，并且给定的数组总是存在多数元素。



示例 1 :

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
	输出 : 2*/

	
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
int majorityElement(int* nums, int numsSize) {
	int count = 0;
	QuickSort(nums, 0, numsSize - 1);
	for (int i = 0; i <= numsSize / 2; i++)
	{
		if ((i + numsSize / 2) < numsSize && nums[i] == nums[i + numsSize / 2])
		{
			count = nums[i];
		}
	}
	return count;
}