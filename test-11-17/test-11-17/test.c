//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ�� ��20Ԫ�����Զ�����ˮ

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	int money = 20;
	int total = money;
	int empty = money;
	while (empty >= 2)  //����ѭ��������ֻҪ����2ƿ ���ܼ�����
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n", total);
	system("pause");
	return 0;
}
