#define _CRT_SECURE_NO_WARNINGS 1
//����һ���ǿ����飬���ش������е������������������ڣ��򷵻���������������Ҫ���㷨ʱ�临�Ӷȱ�����O(n)��
//ʾ�� 1:
//����: [3, 2, 1]
//
//	��� : 1
//
//	���� : ����������� 1.
//	ʾ�� 2 :
//
//	���� : [1, 2]
//
//	��� : 2
//
//	���� : ���������������, ���Է��������� 2 .
//	ʾ�� 3 :
//
//	���� : [2, 2, 3, 1]
//
//	��� : 1
//
//	���� : ע�⣬Ҫ�󷵻ص������������ָ��������Ψһ���ֵ�����
//	��������ֵΪ2���������Ƕ��ŵڶ���

int thirdMax(int* nums, int numsSize)
{
	int max = nums[0];
	int min = nums[0];
	for (int i = 0; i < numsSize; i++)
	{
		if (max < nums[i])
		{
			int tmp = nums[i];
			nums[i] = max;
			max = tmp;
		}
		if (min > nums[i])
		{
			int tmp = nums[i];
			nums[i] = min;
			min = tmp;
		}
	}
	int mid = min;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] < max && mid < nums[i])
		{
			int tmp = nums[i];
			nums[i] = mid;
			mid = tmp;
		}
		if (nums[i] < mid && min < nums[i])
		{
			int tmp = nums[i];
			nums[i] = min;
			min = tmp;
		}
	}
	if (mid == min)
	{
		return max;
	}
	return min;
}
