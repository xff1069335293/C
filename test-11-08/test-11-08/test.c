//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>

void left_rotate(char str[], int n, int sz)
{
	int i = 0;
	assert(str);
	n %= sz;
	while (n--)
	{
		char tmp = str[0];
		for (i = 0; i < sz - 1; i++)
		{
			str[i] = str[i + 1];
		}
		str[sz - 1] = tmp;
	}
}

int main()
{
	int n = 0;
	char str[] = "ABCD";
	int len = strlen(str);
	printf("������Ҫ��ת�����ַ���>");
	scanf("%d", &n);
	left_rotate(str, n, len);
	printf("%s\n", str);
	system("pause");
	return 0;
}