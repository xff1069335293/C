
//3.ʵ��һ�������ж�year�ǲ������ꡣ
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
	printf("������һ����ݣ�\n");
	int ret = 0;
	int year = 0;
	scanf("%d", &year);
	printf("���������: %d \n", year);
    ret = Year(year);
	if (ret == -1)
	{
		printf("%d ��������", year);
	}
	else 
	{
		printf("%d ������", year);
	}
system("pause");
	return 0;
}
