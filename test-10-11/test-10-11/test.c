//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��

int intt(int arr[], int ch)
{
	int n = 0;
	int i = 0;
	for (i = 0; i < ch; i++)
	{
		scanf("%d", &n);
		if (n == 0)
			;
		else
		{
			arr[i] = n;
			printf("%d ", arr[i]);
		}
	}
}

int  reverse(int arr[], int ch)
{
	int i = 0;
	for (i = 0; i < ch / 2; i++)
	{
		int tmp = arr[i];
		arr[i] = arr[ch - i - 1];
		arr[ch - i - 1] = tmp;

	}
	for (i = 0; i < ch; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

int empty(int arr[], int ch)
{
	int i = 0;
	for (i = 0; i < ch; i++)
	{
		arr[i] = 0;
		printf("%d", arr[i]);
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
int main()
{
	int arr[10] = { 0 };
	int ch = sizeof(arr) / sizeof(0);
	printf("�뿪ʼ��ʼ�����飺\n");
	intt(arr, ch);
	printf("\n");
	printf("��ʼ����\n");
	reverse(arr, ch);
	printf("\n");
	printf("��ʼ���\n");
	empty(arr, ch);
	printf("\n");
	system("pause");
	return 0;
}