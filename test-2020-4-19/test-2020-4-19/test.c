//
//�ҳ��������ظ������֡�
//
//
//��һ������Ϊ n ������ nums ����������ֶ��� 0��n - 1 �ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
//
//ʾ�� 1��
//
//���룺
//[2, 3, 1, 0, 2, 5, 3]
//�����2 �� 3


int findRepeatNumber(int* nums, int numsSize) {
	if (nums == NULL) {
		return -1;
	}
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != i && nums[i] == nums[nums[i]]) {
			return nums[i];
		}
		int tmp = nums[nums[i]];
		nums[nums[i]] = nums[i];
		nums[i] = tmp;
	}
	return -1;
}