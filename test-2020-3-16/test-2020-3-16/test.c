//�ַ���ѹ���������ַ��ظ����ֵĴ�������дһ�ַ�����ʵ�ֻ������ַ���ѹ�����ܡ����磬�ַ���aabcccccaaa���Ϊa2b1c5a3������ѹ��������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ���������Լ����ַ�����ֻ������СдӢ����ĸ��a��z����
//
//ʾ��1 :
//
//���룺"aabcccccaaa"
//�����"a2b1c5a3"
//ʾ��2 :
//
//	���룺"abbccd"
//	�����"abbccd"
//	���ͣ�"abbccd"ѹ����Ϊ"a1b2c2d1"����ԭ�ַ������ȸ�����
//	��ʾ��
//
//	�ַ���������[0, 50000]��Χ�ڡ�
//
	char* compressString(char* S)
{
	char* res = (char*)malloc(sizeof(char) * 500001);
	sprintf(res, "%s", "");
	int len = strlen(S);
	int count = 1, i = 0, j;
	while (i < len) {
		j = i;
		while (j < len&&S[j] == S[i]) {
			j++;
		}
		sprintf(res, "%s%c%d", res, S[i], j - i);
		i = j;
	}
	if (strlen(res) < len)
		return res;
	return S;
}