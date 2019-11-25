#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//strcpy实现
char *my_strcpy(char *arr, char *p)
{
	assert((arr != NULL) && (p != NULL)); 	//如果arr和p为空则终止程序
	char *s = arr;
	while (*p)
	{
		*arr++ = *p++;
	}
	*arr = '\0';
	return s;
}

//strcat实现
char *my_strcat(char *arr, char *p)
{
	assert((arr != NULL) && (p != NULL));	//如果arr和p为空则终止程序
	char *s = arr;
	while (*arr)
	{
		arr++;
	}
	while (*p)
	{
		*arr++ = *p++;
	}
	*arr = '\0';
	return s;
}


//strcmp实现
int my_strcmp(char *arr, char *p)
{
	assert((arr != NULL) && (p != NULL));
	while (*arr || *p)
	{
		if (*arr > *p)
		{
			return 1;
		}
		else if (*arr < *p)
		{
			return -1;
		}
		else
		{
			arr++;
			p++;
		}
	}
	return 0;
}

int main()
{
	//strcpy实现
	char str1[100] = "hello";
	char str2[100] = "world";
	printf("after strcpy is: %s\n", my_strcpy(str1, str2));

	//strcat实现
	char str3[100] = "hello";
	char str4[100] = "world!";
	printf("after strcat is: %s\n", my_strcat(str3, str4));

	//strcmp实现
	char str5[100] = "hello";
	char str6[100] = "world";
	printf("after strcmp is: %d\n", my_strcmp(str5, str6));
	system("pause");
	return 0;
}
