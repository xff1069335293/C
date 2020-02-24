#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
//
//����㷨ʱ�临�Ӷȱ����� O(log n) ����
//
//��������в�����Ŀ��ֵ������[-1, -1]��
//
//ʾ�� 1:
//
//����: nums = [5, 7, 7, 8, 8, 10], target = 8
//	��� : [3, 4]
//	ʾ�� 2 :
//
//	���� : nums = [5, 7, 7, 8, 8, 10], target = 6
//	��� : [-1, -1]
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
	