//�� 1 + 2 + ... + n ��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����
//
//
//
//ʾ�� 1��
//
//���� : n = 3
//	��� : 6
//	ʾ�� 2��
//
//	���� : n = 9
//	��� : 45

	int sumNums(int n) {
	if (n == 0)
	{
		return 0;
	}
	int sum = n;
	sum += sumNums(n - 1);
	return sum;
}