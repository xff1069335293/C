//��һ�޶��ĳ��ִ���
//����һ���������� arr�������æͳ��������ÿ�����ĳ��ִ�����
//���ÿ�����ĳ��ִ������Ƕ�һ�޶��ģ��ͷ��� true�����򷵻� false��
//

bool uniqueOccurrences(int* arr, int arrSize) {
	int x, i, j;
	int count[1000] = { 0 }, t = 0;
	bool a;
	for (i = 0; i < arrSize; i++)
	{
		a = false;
		if (arr[i] != -1001)x = arr[i];
		for (j = i; j < arrSize; j++)
		{
			if (x == arr[j])
			{
				count[t]++;
				arr[j] = -1001;
				a = true;
			}
		}
		if (a)t++;
	}
	for (i = 0; i < t; i++)
	{
		for (j = 0; j < t; j++)
		{
			if (count[i] == count[j] && i != j)
			{
				return false;
			}
		}
	}
	return true;

}