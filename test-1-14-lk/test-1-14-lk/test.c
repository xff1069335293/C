//��������
//����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
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