#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//1. ������A�е����ݺ�����B�е����ݽ��н�����������һ����
//int main() {
//	int arr1[] = { 1,2,3 };
//	int arr2[] = { 4,5,6 };
//	int count = sizeof(arr1) / sizeof(arr1[0]);
//	for (int i=0; i<count; i++) 
//	{
//		int tmp = arr2[i];
//		arr2[i] = arr1[i];
//		arr1[i] = tmp;
//	}
//	for (int i=0; i<count; i++) 
//	{
//		printf("%d", arr1[i]);
//    }
//	printf("\n");
//	for (int i=0; i<count; i++) 
//	{
//		printf("%d", arr2[i]);
//	}
//	system("pause");
//	return 0;
//	}
//2. ����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ��
//int  Pow(int x, int y)
//{
//	int num = 1;
//	for (int j = 1; j <= y; j++)
//	{
//		num *= x;
//	}
//	return num;
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d",&input);
//	float sum = 0;
//	for (int i = 1; i <= input; i++)
//	{
//		sum +=(float) Pow(-1, i+1) / i;//���;��㲻������ȷ���
//	}
//	printf("%f", sum);
//	system("pause");
//	return 0;
//}

//3. ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
int main()
{
	int num = 100,count=0;
	for (int  i = 1; i <= num; i++)
	{
		if (9 == i % 10)
		{
			++count;
		}
		else if (9 == i / 10)
		{
			++count;
		}
	}
	printf("%d",count);
	system("pause");
	return 0;
}


