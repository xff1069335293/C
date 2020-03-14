//
//给定一个无序的整数数组，找到其中最长上升子序列的长度。
//
//示例 :
//
//输入: [10, 9, 2, 5, 3, 7, 101, 18]
//	输出 : 4
//	解释 : 最长的上升子序列是[2, 3, 7, 101]，它的长度是 4。
//	说明 :
//
//	可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
int lengthOfLIS(int* nums, int numsSize) {
	int i, len = 0, dp[numsSize + 1];
	dp[0] = INT_MIN;
	for (i = 0; i < numsSize; ++i)
	{
		if (nums[i] > dp[len])
			dp[++len] = nums[i];
		else
		{
			int low = 1, high = len, mid;
			while (low < high)
			{
				mid = low + (high - low) / 2;
				if (dp[mid] < nums[i]) low = mid + 1;
				else high = mid;
			}
			dp[low] = nums[i];
		}
	}
	return len;
}