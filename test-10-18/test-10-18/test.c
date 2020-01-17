#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

void MyStrcpy1(char *dst, char *src)//注意断言指针不为空
{
	assert(dst != NULL && src != NULL);
	while (*src != '\0')
	{
		*dst++ = *src++;
	
	}
	*dst = *src;
}

void MyStrcpy2(char *dst, char *src)//优化一下
{
	assert(dst != NULL && src != NULL);
	while (*++dst = *src++)
	{
		;
	}
	*dst = *src;
}

int main()
{
	char arr[] = "#######";
	char arr2[] = "bit";
	/*strcpy(arr, arr2);
	printf("%s\n",arr);
	MyStrcpy1(arr, arr2);
	printf("%s\n", arr);*/
	MyStrcpy2(arr, arr2);
	printf("%s\n", arr);
	system("pause");
	return 0;
}