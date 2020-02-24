#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
//
//ʾ�� 1:
//
//����: ��A man, a plan, a canal : Panama��
//	��� : true
//	ʾ�� 2 :
//
//	���� : ��race a car��
//	��� : false


bool isPalindrome(char * s)
{
	char * arr = (char *)malloc(sizeof(char)*(strlen(s)));
	int num = 0;
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9' || *s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z')
		{
			if (*s >= 'A' && *s <= 'Z')
			{
				*s += 32;
			}
			arr[num] = *s;
			++num;
		}
		++s;
	}
	if (num == 0)
	{
		return true;
	}
	int right = num - 1;
	int left = 0;
	while (left <= right && arr[left] == arr[right])
	{
		left++;
		right--;
	}
	if (left < right)
	{
		return false;
	}
	return true;
}