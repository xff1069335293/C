#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int buf[10] = { 0 };//������ȫ����ʼ��Ϊ0
	int i = 0;
	int len = 9;//������±�
	for (i = 0; i < 10; ++i)	//ѭ����������
	{
		scanf("%d", &buf[i]);
	}
	for (i = 0; i <= len; ++i) 
	{
		if (buf[i] % 2 == 0) 
		{
			int tmp = buf[len];
			buf[len] = buf[i];
			buf[i] = tmp;//��������
			len = len - 1;//������ѭ����������,�ֿ��������±���ǰ�ƶ�һ.
			i = i - 1;//��Ϊ��֪��������Ԫ���Ƿ�Ϊż��,���԰����ѭ���ٽ���һ��
		}
	}
	for (i = 0; i < 10; ++i) 
	{
		printf("%d ", buf[i]);
	}
	system("pause");
	return 0;
}
