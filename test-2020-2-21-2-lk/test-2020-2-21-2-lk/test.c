#define _CRT_SECURE_NO_WARNINGS 1
//����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ
//
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�
//
//ʾ�� :
//
//���� nums = [2, 7, 11, 15], target = 9
//
//��Ϊ nums[0] + nums[1] = 2 + 7 = 9
//���Է���[0, 1]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
	int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int* ret = (int*)malloc(sizeof(int) * 2);
	*returnSize = 0;
	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				*returnSize = 2;
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}
	}
	return NULL;
}
