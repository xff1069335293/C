#define _CRT_SECURE_NO_WARNINGS 1
//��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
//
//
//
//ʾ�� 1��
//
//���룺s = "We are happy."
//�����"We%20are%20happy."

char* replaceSpace(char* s) {
	int len = strlen(s);
	char* ans = (char*)calloc(len * 3 + 1, sizeof(char));
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != ' ')
			ans[count++] = s[i];
		else
		{
			ans[count++] = '%';
			ans[count++] = '2';
			ans[count++] = '0';
		}
	}
	ans[count] = '\0';
	return ans;
}