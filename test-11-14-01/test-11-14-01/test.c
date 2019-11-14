//Ä£ÄâÊµÏÖmemcpy
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void* my_memcpy(void* dest, const void* src, size_t n)
{
	assert(dest);
	assert(src);
	char* pdest = (char*)dest;
	const char* psrc = (const char*)src;
	while (n--)
	{
		*pdest++ = *psrc++;
	}
	return dest;
}
int main()
{
	char str1[] = "Sample string";
	char str2[40];
	my_memcpy(str2, str1, strlen(str1) + 1);
	printf("str1: %s\nstr2: %s\n", str1, str2);
	system("pause");
	return 0;
}
