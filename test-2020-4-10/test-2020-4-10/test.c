//.��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
//
//ʾ�� 1��
//
//���룺s = ��We are happy.��
//�������We % 20are % 20happy.��
//
//���ƣ�
//
//0 <= s �ĳ��� <= 10000



char* replaceSpace(char* s)
{
	int count = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ')
		{
			++count;
		}
	}
	char* arr = (int *)malloc(sizeof(int)*(len + 2 * count));
	arr[len + 2 * count] = 0;
	count = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != ' ')
		{
			arr[i + count] = s[i];
		}
		else
		{

			arr[i + count] = '%';
			arr[i + 1 + count] = '2';
			arr[i + 2 + count] = '0';
			count += 2;
		}
	}
	return arr;
}
