//�����ַ���
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	char s[] = "basada";
	int len = strlen(s); //��ȡs����
	int p = 0, r = 0;
	int count = 0; //��¼���Ĵ�����
	int k = 0; //����ѭ���˳�
	for (int i = 0; i < len; i++) //��ǰ�������
	{
		for (int j = len - 1; j > i; j--) //�Ӻ���ǰ����
		{
			if (s[i] == s[j] && r - p + 1 > count) //���Ӵ���β����ҳ��ȴ���ԭ�ȵ��Ӵ������
			{
				p = i, r = j, k = 0;
				int n = p, m = r;
				while (n <= m)
				{
					n++;
					m--;
					if (s[n] != s[m]) //�����ֲ���ʱѭ������
					{
						k = 1;
					}
					if (k)
					{
						break;
					}
				}
				if (k)                  //���Ҳ���¼����
				{
					continue;
				}
				count = r - p + 1;
			}
		}
	}
	if (count)
	{
		for (int i = p; i <= r; i++)
		{
			printf("%c", s[i]);
		}
	}
	else
	{
		printf("0");
	}
	system("pause");
	return 0;
}
