//模拟实现strncmp
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int Strncmp(const char* dst, const char* src, int size) {
	for (int i = 0; i < size; ++i) {
		if (*(dst + i) > *(src + i)) {			//前面的大返回1
			return 1;
		}
		else if (*(dst + i) < *(src + i)) {		//后面的大返回-1
			return -1;
		}
		if (*(dst + i) == 0 || *(src + i) == 0) {		//相等返回0
			break;
		}
	}
	return 0;
}
int main() {
	char str1[] = "abcdef";
	char str2[] = "abcd";
	printf("%d\n", Strncmp(str1, str2, 4));
	printf("%d\n", Strncmp(str1, str2, 5));
	printf("%d\n", Strncmp(str2, str1, 5));
	system("pause");
	return 0;
}

