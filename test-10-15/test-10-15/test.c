//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19


DigitSum(int ch) //DigitSum(172) 9  17 2 9  1 7 2 9
{

	if (ch < 10)
	{
		return ch;
	}
	else
	{
		return  DigitSum(ch / 10) + ch % 10;

	}
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned int ch = 0;
	printf("������һ������\n");
	scanf("%d", &ch);
	int ret = DigitSum(ch);
	printf("%d\n", ret);
	system("pause");
	return 0;

}
