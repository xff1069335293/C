#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//1
//дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1  10  1010 
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	// ���� 1��λ�� 
//}
int count_bits(unsigned int input) 
{	 
	int count = 0;
	int num = 0;
	while (input)
	{
		++count;
		input = (input - 1)&input;
	}
	return count;
}


int main()
{
	int input = 0;
	scanf("%d", &input);
	int ret = count_bits(input);
	printf("%d",ret);
	system("pause");
	return 0;
}
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
//
//
//int main()
//{
//	int b = -20;
//	system("pause");
//	return 0;
//}