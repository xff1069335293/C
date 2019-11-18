//模拟实现strchr
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
const char* Mystrchr(const char* dst, const char str) {
	assert(dst != NULL);
	while (*dst != '\0') {//循环条件是指针不指向字符串结尾
		if (*dst == str) {//如果相等,返回开始查找的位置
			return dst;
		}
		dst++;//循环条件加加
	}
	return NULL;
}
int main() 
{
	char buf[] = "hello world";
	char* p = Mystrchr(buf, 'o');
	printf("%s", p);
	system("pause");
	return 0;
}
