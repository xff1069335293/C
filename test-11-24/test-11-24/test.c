//δ���1.
//дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1   15  7  3  2   
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	 ���� 1��λ�� 
//}
//
//2.��ȡһ�������������������е�ż��λ������λ��
//�ֱ�������������С�
//
//3. ���һ��������ÿһλ��
//
//4.���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int  count_one_bits(int y)
//{
//	int x=0;
//	while (z)
//	{
//		
//		if (y > 1)
//		{
//			x = y % 2;
//			y = y / 2;
//		
//		}
//		else
//		{
//			x = 0;
//		}
//		z--;
//		printf("%d", x);
//	}
//
//	return x;
//}
//
//int main()
//{
//	int ch = 0;
//	printf("������һ������\n");
//	scanf("%d",&ch);
//	int ret = count_one_bits(ch);
//	printf("%d",ret);
//	system("pause");
//	return 0;
//}

//��ȡһ�������������������е�ż��λ������λ���ֱ�������������С�
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main()
{
	int num = 20;
	int i = 0;
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", ((num >> i) & 1));
	}
	//��ߵ�ż��λ�����ƶ�31λ�����һλ�����ż��λ�����ƶ�1λ�����һλ
	printf("\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", ((num >> i) & 1));
	}
	//��ߵ�����λ�����ƶ�30λ�����һλ�����������λ�����ƶ�0λ�����һλ
	printf("\n");
	system("pause");
	return 0;
}
