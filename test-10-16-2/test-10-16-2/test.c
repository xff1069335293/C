//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Reverse_string(char *str) {
	if (*(++str) != '\0')
	{
		Reverse_string(str);
	}
	printf("%c", *(str - 1));
}
int main() {
	char a[] = "HelloWorld";
	Reverse_string(a);
	printf("\n");
	system("pause");
	return 0;
}