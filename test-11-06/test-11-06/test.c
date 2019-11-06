//有一个字符数组的内容为:"student a am i" 
//	请你将数组的内容改为"i am a student".
//用库函数实现

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
char* string_(char* string) 
{
	char* ptmp;
	char temp[1024] = { 0 };
	//从右边找到空格
	while (ptmp = strrchr(string, ' ')) {
		//地址加1开始拼接
		strcat(temp, ptmp + 1);
		//拼接完成之后给空格
		strcat(temp, " ");
		*ptmp = '\0';
	}
	strcat(temp, string);
	strcpy(string, temp);
	return string;
}
int main()
{
	char string[] = { "student a am i" };
	puts(string_(string));
	system("pause");
	return 0;
}
