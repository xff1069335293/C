
//3.实现一个函数判断year是不是润年。
//
int Year(int year)
{
	int ret = 0;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) 
	{
		ret = year;
	}
	else
	{
		ret = -1;
	}
	return ret;	
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	printf("请输入一个年份：\n");
	int ret = 0;
	int year = 0;
	scanf("%d", &year);
	printf("你输入的是: %d \n", year);
    ret = Year(year);
	if (ret == -1)
	{
		printf("%d 不是闰年", year);
	}
	else 
	{
		printf("%d 是闰年", year);
	}
system("pause");
	return 0;
}
