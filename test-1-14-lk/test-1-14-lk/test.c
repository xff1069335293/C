//最大子序和
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
int maxSubArray(int* nums, int numsSize)
{
	int sum = nums[0];
	int now = nums[0];

	for (int i = 1; i < numsSize; i++)
	{
		if (now < 0)
			now = nums[i];
		else
			now = now + nums[i];

		if (now > sum)
			sum = now;
	}
	return sum;
}