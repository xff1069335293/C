#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
	//�ҳ����������֣����ʵ�֡�
	int arr[] = { 4,8,8,4,19,5,9,3,5,9,3,15,56,20 };
	int count = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);//12
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		count = 0;//ÿ��ִ��ѭ��ʱ��ʼ��Ϊ0
		for (j = 0; j < sz; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count == 1)
		{
			printf("%d\n", arr[i]);
		}
	}

	system("pause");
	return 0;
}

