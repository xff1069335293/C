#define _CRT_SECURE_NO_WARNINGS 1
#define  N 5
#include <stdio.h>
#include <math.h>
//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
//unsigned int reverse_bit(unsigned int value) 
//{
//	int sum = 0;
//	for (int  i = 0; i < 32; i++)
//	{
//		sum+=(((value >> i) & 1)*pow(2, 31 - i));
//	}
//	return sum;
//}
//
//int main() 
//{
//	int input = 0;
//	scanf("%d",&input);
//	printf("%u", reverse_bit(input));
//	system("pause");
//	return 0;
//}
//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��

//int average1(int num1, int num2)
//{
//	return	num1>num2?((num1 - num2) / 2) + num2: ((num2- num1) / 2+num1);
//
//}
//
//int average2(int num1, int num2)
//{
//	return ((num1&num2) + ((num1^num2) >> 1));
//}
//
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf("%d %d",&a,&b);
//	int ret = average2(a, b);
//	printf("%d",ret);
//	system("pause");
//	return 0;
//}
//
//3.���ʵ�֣� 
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
//int  OneNum(int* arr,int len)
//{
//	int num = 0;
//	for (int i = 0; i < len; i++)
//	{
//		num ^= arr[i];
//	}
//	return num;
//}
//
//int main()
//{
//	int arr[] = { 1,1,2,2,3,3,6 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int ret = OneNum(arr,len);
//	printf("%d",ret);
//	system("pause");
//	return 0;
//}

