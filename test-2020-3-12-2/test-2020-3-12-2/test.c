//����һ���������� A��ֻ�п��Խ��仮��Ϊ��������ȵķǿղ���ʱ�ŷ��� true�����򷵻� false��
//
//
//
//ʾ�� 1��
//
//�����[0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1]
//�����true
//���ͣ�0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
//ʾ�� 2��
//
//���룺[0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1]
//�����false
//ʾ�� 3��
//
//���룺[3, 3, 6, 5, -2, 2, 5, 1, -9, 4]
//�����true
//���ͣ�3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
//
//��ʾ��
//
//3 <= A.length <= 50000
//- 10 ^ 4 <= A[i] <= 10 ^ 4
//

bool canThreePartsEqualSum(int* A, int ASize)
{
	int sum = 0, num = 0, count = 0;
	for (int i = 0; i < ASize; i++)
	{
		sum += A[i];
	}
	if (sum % 3 == 0)
	{
		num = sum / 3;
		sum = 0;
		for (int i = 0; i < ASize; i++)
		{
			sum += A[i];
			if (sum == num)
			{
				count++;
				sum = 0;
			}
		}
	}
	if (count >= 3)
		return true;
	return false;
}
