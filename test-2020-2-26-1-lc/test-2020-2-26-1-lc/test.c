#define _CRT_SECURE_NO_WARNINGS 1
����һ���ַ��� S������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��

ʾ�� 1��

���룺��ab - cd��
�������dc - ba��
ʾ�� 2��

���룺��a - bC - dEf - ghIj��
�������j - Ih - gfE - dCba��
ʾ�� 3��

���룺��Test1ng - Leet = code - Q!��
�������Qedo1ct - eeLg = ntse - T!��

��ʾ��

S.length <= 100
33 <= S[i].ASCIIcode <= 122
S �в����� \ or "


char * reverseOnlyLetters(char * S)
{
	int right = strlen(S) - 1;
	int left = 0;
	while (left < right)
	{
		int flag1 = 0, flag = 0;
		if (S[left] >= 'a'&&S[left] <= 'z' || S[left] >= 'A'&&S[left] <= 'Z')
		{
			flag1 = 1;
		}
		else
		{
			++left;
		}
		if (S[right] >= 'a'&&S[right] <= 'z' || S[right] >= 'A'&&S[right] <= 'Z')
		{
			flag = 1;
		}
		else
		{
			--right;
		}
		if (flag && flag1)
		{
			char tmp = S[left];
			S[left] = S[right];
			S[right] = tmp;
			++left;
			--right;
		}
	}
	return S;
}
