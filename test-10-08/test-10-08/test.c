#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
////
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	for (int i = 1; i <= input; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d ",j ,i,i*j);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//2.ʹ�ú���ʵ���������Ľ�����
//void NumExchange1(int a, int b)//�����Ǹı���ʱ������a,b��ֵ
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//void NumExchange2(int* a, int *b)//��ָ�����ʵ�ʸı�ԭ��������
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main()
//	{
//	int a = 3;
//	int b = 4;
//	printf("%d %d\n", a, b);
//	NumExchange1(a, b);
//	printf("%d %d\n", a, b);
//	NumExchange2(&a, &b);
//	printf("%d %d\n", a, b);
//	system("pause");
//	return 0;
//	}

//3.ʵ��һ�������ж�year�ǲ������ꡣ
//
//int Year(int year)
//{
//	int ret = 0;
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) 
//	{
//		ret = year;
//	}
//	else
//	{
//		ret = -1;
//	}
//	return ret;	
//}

//int main()
//{
//	printf("������һ����ݣ�\n");
//	int ret = 0;
//	int year = 0;
//	scanf("%d", &year);
//	printf("���������: %d \n", year);
//  ret = Year(year);
//	printf("haha %d", ret);
//	if (ret == -1)
//	{
//		printf("%d ��������", year);
//	}
//	else 
//	{
//		printf("%d ������", year);
//	}
//system("pause");
//	return 0;
//}
//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
//
//void Init(int* arr, int len)
//{
//	int input = 0;
//	for (int i = 0; i < len; i++)
//	{
//		scanf("%d", &input);
//		arr[i] = input;
//	}
//}
//void Empty(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void Reverse(int *arr, int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while (left <= right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//void Print(int* arr, int len)
//{
//	for (int  i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int len = (sizeof(arr) / sizeof(arr[0]));
//	Init(arr,len);
//	Print(arr, len);
//	Reverse(arr,len);
//	Print(arr, len);
//	Empty(arr, len);
//	Print(arr, len);
//	system("pause");
//	return 0;
//}


//5.ʵ��һ���������ж�һ�����ǲ���������
//int Judge(int input)
//{
//	if (input == 1)
//	{
//		return 1;
//	}
//	for (int i = 1; i < input / 2; i++)
//	{
//		if (input % i != 0)
//		{
//			continue;
//		}
//		else
//		{
//			return 0;
//		}
//		return 1;
//	}
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d",&input);
//	int ret = Judge(input);
//	if (ret == 0)
//	{
//		printf("%d��������\n",input);
//	}
//	else
//	{
//		printf("%d������\n", input);
//	}
//	system("pause");
//	return 0;
//}


