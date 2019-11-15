//ģ��ʵ��strstr
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>

char *my_strstr(const char *str1, const char *str2)
{
	assert(str1);
	assert(str2);

	char *dest = (char *)str1;
	char *sorc = (char *)str2;
	char *flag = NULL;

	if (!*str2)			//����ڶ����ַ���ΪNULL��ֱ�ӷ���NULL
	{
		return NULL;
	}

	while (*dest)   //��*dest����'\0'ʱ������ѭ��
	{
		flag = dest;
		sorc = (char *)str2;
		while (*flag && *sorc && (*flag == *sorc))
		{
			flag++;
			sorc++;
		}

		if (!*sorc) //��*sorc='\0'����ʾstr2�������ַ����Ƚ����ˣ���ʱ�����ж�str2��str1���Ӵ�
		{
			return dest;
		}
		else
		{
			dest++;
		}

	}
	return NULL;
}

int main()
{
	char s1[] = "we are student!";
	char s2[] = "are";
	printf("%s", my_strstr(s1, s2));
	system("pause");
	return 0;
}
