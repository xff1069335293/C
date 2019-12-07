//×Ö·û´®ÄæÐòº¯Êý


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void string_reverse(const char *ptr, char *str)
{
	int len = strlen(ptr), i;

	ptr += (len - 1);

	for (i = 0; i < len; i++)
	{
		*str = *ptr;
		str++;
		ptr--;
	}
}

int main()
{
	char *ptr = (char *)malloc(sizeof(char) * 64);
	char *str = (char *)malloc(sizeof(char) * 64);

	printf("Please input:\n");
	scanf("%s", ptr);

	string_reverse(ptr, str);

	printf("%s\n", str);
	system("pause");
	return 0;
}