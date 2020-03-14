//
//����һ��������������飬�ҵ���������������еĳ��ȡ�
//
//ʾ�� :
//
//����: [10, 9, 2, 5, 3, 7, 101, 18]
//	��� : 4
//	���� : ���������������[2, 3, 7, 101]�����ĳ����� 4��
//	˵�� :
//
//	���ܻ��ж�������������е���ϣ���ֻ��Ҫ�����Ӧ�ĳ��ȼ��ɡ�
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