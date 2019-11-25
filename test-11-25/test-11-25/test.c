#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//strcpyʵ��
char *my_strcpy(char *arr, char *p)
{
	assert((arr != NULL) && (p != NULL)); 	//���arr��pΪ������ֹ����
	char *s = arr;
	while (*p)
	{
		*arr++ = *p++;
	}
	*arr = '\0';
	return s;
}

//strcatʵ��
char *my_strcat(char *arr, char *p)
{
	assert((arr != NULL) && (p != NULL));	//���arr��pΪ������ֹ����
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


//strcmpʵ��
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
	//strcpyʵ��
	char str1[100] = "hello";
	char str2[100] = "world";
	printf("after strcpy is: %s\n", my_strcpy(str1, str2));

	//strcatʵ��
	char str3[100] = "hello";
	char str4[100] = "world!";
	printf("after strcat is: %s\n", my_strcat(str3, str4));

	//strcmpʵ��
	char str5[100] = "hello";
	char str6[100] = "world";
	printf("after strcmp is: %d\n", my_strcmp(str5, str6));
	system("pause");
	return 0;
}
