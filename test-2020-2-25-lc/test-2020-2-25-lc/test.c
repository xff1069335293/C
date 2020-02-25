#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//Ñ¹Ëõ×Ö·û´®
char* compress(char* chars, int charsSize)
{
	int arr[91] = { 0 };
	char* src = chars;
	if (charsSize == 0)
	{
		return chars;
	}
	while (*chars != '\0')
	{
		if (*chars >= 35 && *chars <= 126)
		{
			arr[*chars - 35]++;
		}
		++chars;
	}
	--chars;
	int num = 91;
	int count = 0;
	while (num >= 0 && chars >= src)
	{
		if (arr[num] == 1)
		{
			++count;
			*chars = num + 35;
			--chars;
		}
		if (arr[num] > 1)
		{

			while (arr[num])
			{
				*chars = (arr[num] % 10) + '0';
				arr[num] /= 10;
				--chars;
				++count;
			}
			*chars = num + 35;
			--chars;
			++count;
		}
		--num;
	}
	++chars;
	return chars;
}

int main()
{
	char chars[] = "asbfsjd";
	int len = strlen(chars);
	compress(chars, len);
	for (size_t i = 0; i < len; i++)
	{
		printf("%c ", chars[i]);
	}
	
	system("pause");
	return 0;
}