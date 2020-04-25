//.һ���������� nums �����������֮�⣬�������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
//
//ʾ�� 1��
//
//���룺nums = [4, 1, 4, 6]
//�����[1, 6] ��[6, 1]
//ʾ�� 2��
//
//���룺nums = [1, 2, 10, 4, 1, 4, 3, 3]
//�����[2, 10] ��[10, 2]


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

//����
//˫ָ��
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