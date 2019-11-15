//模拟实现strstr
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

	if (!*str2)			//如果第二个字符串为NULL，直接返回NULL
	{
		return NULL;
	}

	while (*dest)   //当*dest不是'\0'时，进入循环
	{
		flag = dest;
		sorc = (char *)str2;
		while (*flag && *sorc && (*flag == *sorc))
		{
			flag++;
			sorc++;
		}

		if (!*sorc) //当*sorc='\0'，表示str2的所有字符都比较完了，此时可以判定str2是str1的子串
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
