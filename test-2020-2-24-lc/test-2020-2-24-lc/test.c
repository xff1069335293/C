#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//你的算法时间复杂度必须是 O(log n) 级别。
//
//如果数组中不存在目标值，返回[-1, -1]。
//
//示例 1:
//
//输入: nums = [5, 7, 7, 8, 8, 10], target = 8
//	输出 : [3, 4]
//	示例 2 :
//
//	输入 : nums = [5, 7, 7, 8, 8, 10], target = 6
//	输出 : [-1, -1]
//	
//
	/**
	 * Note: The returned array must be malloced, assume caller calls free().
	 */
	int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
	int* ret = (int *)malloc(sizeof(int)*(2));
	returnSize[0] = 2;
	ret[0] = -1;
	ret[1] = -1;
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		if (nums[left] != target)
		{
			++left;
		}
		else
		{
			ret[0] = left;
		}
		if (nums[right] != target)
		{
			--right;
		}
		else
		{
			ret[1] = right;
		}
		if (ret[0] != -1 && ret[1] != -1)
		{
			break;
		}
	}
	return ret;
}
	