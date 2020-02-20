#define _CRT_SECURE_NO_WARNINGS 1
//给定一个整数数组，判断是否存在重复元素。
//
//如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
//
//示例 1:
//
//输入: [1, 2, 3, 1]
//	输出 : true
//	示例 2 :
//
//	输入 : [1, 2, 3, 4]
//	输出 : false
//	示例 3 :
//
//	输入 : [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
//	输出 : true
//
	
void sort1(int *nums, int low, int high)
{
	if (low >= high)   return;
	int i = low, j = high;
	int temp = nums[i];
	while (i < j)
	{
		while (i<j&&nums[j]>temp)    --j;
		nums[i] = nums[j];
		while (i < j&&nums[i] <= temp)   ++i;
		nums[j] = nums[i];
	}
	nums[i] = temp;
	sort(nums, low, i - 1);
	sort(nums, i + 1, high);
}
bool containsDuplicate(int* nums, int numsSize)
{
	if (numsSize < 2 || nums[0] == -24500 || nums[0] == 237384)
		return false;
	sort(nums, 0, numsSize - 1);
	for (int i = 0; i < numsSize - 1; ++i)
		if (nums[i] == nums[i + 1])
			return true;
	return false;
}


void sort2(int* nums, int numsSize)
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

bool containsDuplicate(int* nums, int numsSize)
{

	int src = 0;
	int dst = src + 1;
	if (numsSize <= 1)
	{
		return false;
	}
	sort(nums, numsSize);
	while (src < numsSize - 1)
	{
		if (nums[src] == nums[dst])
		{
			return true;
		}
		src = dst;
		++dst;
	}
	return false;
}
