//1.�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
//
//ʾ�� 1��
//
//���� : s = ��abcdefg��, k = 2
//	��� : ��cdefgab��
//	ʾ�� 2��
//
//	���� : s = ��lrloseumgh��, k = 6
//	��� : ��umghlrlose��
//
//
	void Swap(char *pa, char *pb)
{
	char tmp = *pb;
	*pb = *pa;
	*pa = tmp;
}
void Reverse(char* s, int begin, int end)
{
	while (begin < end)
	{
		Swap(&s[begin], &s[end]);
		++begin;
		--end;
	}
}
char* reverseLeftWords(char* s, int n)
{
	int len = strlen(s);
	Reverse(s, 0, n - 1);
	Reverse(s, n, len - 1);
	Reverse(s, 0, len - 1);
	return s;
}
