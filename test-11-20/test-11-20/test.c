//ģ��ʵ��strncpy
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void my_strncpy(char* dst,const char* src, int a, int len)
{
	if (a <= len)		//����Ҫ���Ƶĳ���С��str2ʱ�򣬲����ڸ��ǵ���\0��
	{
		for (int i = 0; i < a; ++i)
		{
			*(dst++) = *(src++);
		}

	}
	else//Ϊ�˼�'\0'
	{
		for (int i = 0; i <= len; ++i)
		{
			*(dst++) = *(src++);
		}
		*(dst + 1) = '\0';
	}

}
int main()
{
	char str1[10] = "abcdefgh";
	char str2[7] = "321321";
	int a = 0;
	scanf("%d", &a);
	my_strncpy(str1, str2, a, strlen(str2));
	puts(str1);
	system("pause");
	return 0;
}
