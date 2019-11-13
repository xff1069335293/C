//模拟实现strcpy函数

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <assert.h>
#include<stdlib.h>
char* Strcpy(char* dest, const char* src) {
	int i;
	char* ret = dest;
	assert(src != NULL);
	assert(dest != NULL);
	for (i = 0; src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return ret;
}
int main() {
	char string1[1024];
	char string2[1024];
	gets(string1);
	Strcpy(string2, string1);
	puts(string2);
	system("pause");
	return 0;
}
